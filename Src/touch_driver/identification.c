/*
 * identification.c
 *
 *  Created on: 4 sept. 2018
 *      Author: jcala
 */

#include "identification.h"
#include "touch.h"
#include "stm32f0xx_hal.h"

static void wait_for_finger() {
	while (!touch_is_press_finger()) {
		HAL_Delay(100);
	}
}

static void wait_for_finger_release() {
	while (!touch_is_press_finger()) {
		HAL_Delay(100);
	}
}

void identification_enroll_user() {
	touch_delete_all_fingerprints();
	touch_enroll_start(48);
	wait_for_finger();
	touch_capture_finger();
	touch_enroll_1();
	wait_for_finger_release();
	wait_for_finger();
	touch_capture_finger();
	touch_enroll_2();
	wait_for_finger_release();
	wait_for_finger();
	touch_capture_finger();
	touch_enroll_3(0);
	wait_for_finger_release();
	touch_check_enrolled(48);
	touch_check_enrolled(49);
}

void identification_check() {
	touch_check_enrolled(43);
}
