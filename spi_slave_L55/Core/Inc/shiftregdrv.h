/*
 * shiftregdrv.h
 *
 *  Created on: Jul 20, 2024
 *      Author: danie
 */

#ifndef INC_SHIFTREGDRV_H_
#define INC_SHIFTREGDRV_H_

void update_display1(float input);
void update_display2(float input);
void switch_digit(uint8_t place);
void print_digit(uint8_t place, uint8_t point);
void latch_out();

#endif /* INC_SHIFTREGDRV_H_ */
