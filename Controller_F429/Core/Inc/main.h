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
#include "stm32f4xx_hal.h"

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
#define ACCEPT_REF_Pin GPIO_PIN_2
#define ACCEPT_REF_GPIO_Port GPIOE
#define ACCEPT_REF_EXTI_IRQn EXTI2_IRQn
#define ACCEPT_GAIN_Pin GPIO_PIN_4
#define ACCEPT_GAIN_GPIO_Port GPIOE
#define ACCEPT_GAIN_EXTI_IRQn EXTI4_IRQn
#define COM_LATCH_Pin GPIO_PIN_0
#define COM_LATCH_GPIO_Port GPIOF
#define SEG_DATA_Pin GPIO_PIN_1
#define SEG_DATA_GPIO_Port GPIOF
#define SEG_CLK_Pin GPIO_PIN_2
#define SEG_CLK_GPIO_Port GPIOF
#define DIG_DATA_Pin GPIO_PIN_3
#define DIG_DATA_GPIO_Port GPIOF
#define DIG_CLK_Pin GPIO_PIN_4
#define DIG_CLK_GPIO_Port GPIOF

/* USER CODE BEGIN Private defines */

/* USER CODE END Private defines */

#ifdef __cplusplus
}
#endif

#endif /* __MAIN_H */
