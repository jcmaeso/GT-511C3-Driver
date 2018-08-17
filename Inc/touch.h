/*
 * touch.h
 *
 *  Created on: 17 ago. 2018
 *      Author: jcala
 */

#ifndef TOUCH_H_
#define TOUCH_H_

//TODO: ERROR HANDLER
enum TOUCH_STATE{
	TOUCH_OK,
};

enum UART_ERR{
	UART_OK,
	UART_CHECKSUM_ERR
};

void touch_open(int verbose);

#endif /* TOUCH_H_ */
