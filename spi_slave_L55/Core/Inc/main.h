/* USER CODE BEGIN Header */
/**
  ******************************************************************************
  * @file           : main.h
  * @brief          : Header for main.c file.
  *                   This file contains the common defines of the application.
  ******************************************************************************
  * @attention
  *
  * Copyright (c) 2024 STMicroelectronics.
  * All rights reserved.
  *
  * This software is licensed under terms that can be found in the LICENSE file
  * in the root directory of this software component.
  * If no LICENSE file comes with this software, it is provided AS-IS.
  *
  ******************************************************************************
  */
/* USER CODE END Header */

/* Define to prevent recursive inclusion -------------------------------------*/
#ifndef __MAIN_H
#define __MAIN_H

#ifdef __cplusplus
extern "C" {
#endif

/* Includes ------------------------------------------------------------------*/
#include "stm32l5xx_hal.h"

/* Private includes ----------------------------------------------------------*/
/* USER CODE BEGIN Includes */

/* USER CODE END Includes */

/* Exported types ------------------------------------------------------------*/
/* USER CODE BEGIN ET */

/* USER CODE END ET */

/* Exported constants --------------------------------------------------------*/
/* USER CODE BEGIN EC */

/* USER CODE END EC */

/* Exported macro ------------------------------------------------------------*/
/* USER CODE BEGIN EM */

/* USER CODE END EM */

void HAL_TIM_MspPostInit(TIM_HandleTypeDef *htim);

/* Exported functions prototypes ---------------------------------------------*/
void Error_Handler(void);

/* USER CODE BEGIN EFP */

/* USER CODE END EFP */

/* Private defines -----------------------------------------------------------*/
#define BLUE_BUTTON_Pin GPIO_PIN_13
#define BLUE_BUTTON_GPIO_Port GPIOC
#define LED_GREEN_Pin GPIO_PIN_7
#define LED_GREEN_GPIO_Port GPIOC
#define LED_RED_Pin GPIO_PIN_9
#define LED_RED_GPIO_Port GPIOA
#define ACCEPT_VMAX_Pin GPIO_PIN_0
#define ACCEPT_VMAX_GPIO_Port GPIOD
#define ACCEPT_VMAX_EXTI_IRQn EXTI0_IRQn
#define ACCEPT_MASS_Pin GPIO_PIN_1
#define ACCEPT_MASS_GPIO_Port GPIOD
#define ACCEPT_MASS_EXTI_IRQn EXTI1_IRQn
#define DIG_CLK_Pin GPIO_PIN_3
#define DIG_CLK_GPIO_Port GPIOD
#define DIG_DATA_Pin GPIO_PIN_4
#define DIG_DATA_GPIO_Port GPIOD
#define SEG_CLK_Pin GPIO_PIN_5
#define SEG_CLK_GPIO_Port GPIOD
#define SEG_DATA_Pin GPIO_PIN_6
#define SEG_DATA_GPIO_Port GPIOD
#define COM_LATCH_Pin GPIO_PIN_7
#define COM_LATCH_GPIO_Port GPIOD
#define LED_BLUE_Pin GPIO_PIN_7
#define LED_BLUE_GPIO_Port GPIOB

/* USER CODE BEGIN Private defines */

/* USER CODE END Private defines */

#ifdef __cplusplus
}
#endif

#endif /* __MAIN_H */
