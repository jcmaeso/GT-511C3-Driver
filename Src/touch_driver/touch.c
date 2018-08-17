/*
 * touch.c
 *
 *  Created on: 17 ago. 2018
 *      Author: jcala
 */
#include "touch.h"
#include "stm32f3xx_hal.h"
#include "stm32f3xx_hal_uart.h"
#include <stdint.h>
#include <stdlib.h>

#define COMMAND_PACKET_LEN 12
#define REPONSE_PACKET_LEN 12

extern UART_HandleTypeDef huart1;

static uint8_t command_packet[12];
static uint8_t response_packet[12];



/****************************
*	Custom Data Types       *
*****************************/
typedef struct __attribute__((packed)) dev_info{
	uint32_t header;
	uint32_t FirmwareVersion;
	uint32_t IsoAreaMaxSize;
	uint8_t DeviceSerialNumber[16];
	uint16_t checksum;
}dev_info;

/****************************
*   RX/TX functions    		*
*****************************/
void touch_rcv(uint8_t* packet, int len,int timeout){
	HAL_UART_Receive(&huart1,packet,len,timeout);
}

void touch_send(uint8_t* packet, int len){
	HAL_UART_Transmit(&huart1,packet,len,1000);
}
/****************************
*   Aux functions    		*
*****************************/

uint16_t get_checksum(uint8_t *package, int len)
{
    int i = 0;
    uint16_t checksum = 0;
    for (; i < len - 2; i++)
    {
        checksum += *(package + i);
    }
    return checksum;
}

void create_command_package(uint32_t param, uint16_t command,uint8_t* package)
{
    uint16_t checksum;
    package[0] = 0x55;
    package[1] = 0xAA;
    package[2] = 0x01;
    package[3] = 0x00;
    package[4] = param & 0xFF;
    package[5] = (param >> 8) & 0xFF;
    package[6] = (param >> 16) & 0xFF;
    package[7] = (param >> 24) & 0xFF;
    package[8] = command & 0xFF;
    package[9] = (command >> 8) & 0xFF;
    checksum = get_checksum(package, COMMAND_PACKET_LEN);
    package[10] = (checksum)&0xFF;
    package[11] = (checksum >> 8) & 0xFF;
}

int rcv_ack(uint8_t* packet, int len,int timeout){
	uint16_t calc_checksum;
	uint16_t recv_checksum;
	touch_rcv(packet,len,timeout);
	recv_checksum = packet[len - 2]  | packet[len - 1] << 8;
	calc_checksum = get_checksum(packet,len);
	if(recv_checksum != calc_checksum){
		return UART_CHECKSUM_ERR;
	}
	return UART_OK;
}

void print_rcv(uint8_t *package, int len)
{
    int i;
    printf("RCV: ");
    for (i = 0; i < len; i++)
        printf("%x ", package[i] & 0xff);
    printf("\n");
}
void print_snd(uint8_t *package, int len)
{
    int i;
    printf("SND: ");
    for (i = 0; i < len; i++)
        printf("%x ", package[i] & 0xff);
    printf("\n");
}

/****************************
*   Operations       		*
*****************************/
void touch_open(int verbose){
	if(!verbose){
		create_command_package(0,1,command_packet);
		touch_send(command_packet,COMMAND_PACKET_LEN);
		if(rcv_ack(response_packet,REPONSE_PACKET_LEN,1000) != UART_OK){
			//Protocolo de errores
			return;
		}
	}else{
		dev_info* extra_info = (dev_info*)malloc(sizeof(dev_info));
		create_command_package(0,1,command_packet);
		touch_send(command_packet,COMMAND_PACKET_LEN);
		if(rcv_ack(response_packet,REPONSE_PACKET_LEN,1000) != UART_OK){
			//Protocolo de errores
			return;
		}
		touch_rcv((uint8_t*)extra_info,sizeof(dev_info),2000);
	}
}




