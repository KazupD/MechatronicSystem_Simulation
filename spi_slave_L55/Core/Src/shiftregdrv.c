/*
 * shiftregdrv.c
 *
 *  Created on: Jul 20, 2024
 *      Author: danie
 */
#include "main.h"
#include "shiftregdrv.h"

const uint8_t symbols[11] =
{
		0b11111100, //0
		0b01100000, //1
		0b11011010, //2
		0b11110010, //3
		0b01100110, //4
		0b10110110, //5
		0b10111110, //6
		0b11100000, //7
		0b11111110, //8
		0b11110110, //9
		0b00000001  //P
};

const uint8_t digit_places[8] =
{
		0b10000000,
		0b01000000,
		0b00100000,
		0b00010000,
		0b00001000,
		0b00000100,
		0b00000010,
		0b00000001,
};

uint8_t display1[4] = {1, 2, 3, 4};
uint8_t display2[4] = {5, 6, 7, 8};

void update_display1(float input)
{
	    int int_part = (int)input;
	    float decimal_part = input - int_part;

	    display1[0] = (int_part / 10) % 10;
	    display1[1] = int_part % 10;

	    decimal_part *= 10;
	    display1[2] = (int)decimal_part % 10;
	    decimal_part *= 10;
	    display1[3] = (int)decimal_part % 10;
}

void update_display2(float input)
{
	    int int_part = (int)input;
	    float decimal_part = input - int_part;

	    display2[0] = (int_part / 10) % 10;
	    display2[1] = int_part % 10;

	    decimal_part *= 10;
	    display2[2] = (int)decimal_part % 10;
	    decimal_part *= 10;
	    display2[3] = (int)decimal_part % 10;
}

void switch_digit(uint8_t place)
{
	for(int i = 0; i < 8; i++)
	{
		HAL_GPIO_WritePin(GPIOD, DIG_CLK_Pin, 0);
		HAL_GPIO_WritePin(GPIOD, DIG_DATA_Pin, 0);
		HAL_GPIO_WritePin(GPIOD, DIG_DATA_Pin, ((digit_places[place] >> i) & 1));
		HAL_GPIO_WritePin(GPIOD, DIG_CLK_Pin, 1);
		HAL_GPIO_WritePin(GPIOD, DIG_CLK_Pin, 0);
	}
	HAL_GPIO_WritePin(GPIOB, DIG_CLK_Pin, 0);
	HAL_GPIO_WritePin(GPIOB, DIG_DATA_Pin, 0);
}

void print_digit(uint8_t place, uint8_t point)
{
	for(int i = 0; i < 8; i++)
	{
		HAL_GPIO_WritePin(GPIOD, SEG_CLK_Pin, 0);
		HAL_GPIO_WritePin(GPIOD, SEG_DATA_Pin, 0);
		if(point == 1){
			HAL_GPIO_WritePin(GPIOD, SEG_DATA_Pin, (((symbols[place] | symbols[10]) >> i) & 1));
		}
		else{
			HAL_GPIO_WritePin(GPIOD, SEG_DATA_Pin, ((symbols[place] >> i) & 1));
		}
		HAL_GPIO_WritePin(GPIOD, SEG_CLK_Pin, 1);
		HAL_GPIO_WritePin(GPIOD, SEG_CLK_Pin, 0);
	}
	HAL_GPIO_WritePin(GPIOD, SEG_CLK_Pin, 0);
	HAL_GPIO_WritePin(GPIOD, SEG_DATA_Pin, 0);
}

void latch_out()
{
	HAL_GPIO_WritePin(GPIOD, COM_LATCH_Pin, 0);
	HAL_GPIO_WritePin(GPIOD, COM_LATCH_Pin, 1);
	HAL_GPIO_WritePin(GPIOD, COM_LATCH_Pin, 0);
}

