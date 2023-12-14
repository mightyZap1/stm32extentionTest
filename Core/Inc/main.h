/* USER CODE BEGIN Header */
/**
  ******************************************************************************
  * @file           : main.h
  * @brief          : Header for main.c file.
  *                   This file contains the common defines of the application.
  ******************************************************************************
  * @attention
  *
  * Copyright (c) 2023 STMicroelectronics.
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
#include "stm32f3xx_hal.h"

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

/* Exported functions prototypes ---------------------------------------------*/
void Error_Handler(void);

/* USER CODE BEGIN EFP */

/* USER CODE END EFP */

/* Private defines -----------------------------------------------------------*/
#define PWM_U_Pin GPIO_PIN_0
#define PWM_U_GPIO_Port GPIOA
#define PWM_V_Pin GPIO_PIN_1
#define PWM_V_GPIO_Port GPIOA
#define PWM_W_Pin GPIO_PIN_2
#define PWM_W_GPIO_Port GPIOA
#define HALL_U_Pin GPIO_PIN_8
#define HALL_U_GPIO_Port GPIOA
#define HALL_V_Pin GPIO_PIN_9
#define HALL_V_GPIO_Port GPIOA
#define HALL_W_Pin GPIO_PIN_10
#define HALL_W_GPIO_Port GPIOA
#define DRVRESET_Pin GPIO_PIN_11
#define DRVRESET_GPIO_Port GPIOA
#define EN_U_Pin GPIO_PIN_15
#define EN_U_GPIO_Port GPIOA
#define EN_V_Pin GPIO_PIN_3
#define EN_V_GPIO_Port GPIOB
#define EN_W_Pin GPIO_PIN_4
#define EN_W_GPIO_Port GPIOB

/* USER CODE BEGIN Private defines */

/* USER CODE END Private defines */

#ifdef __cplusplus
}
#endif

#endif /* __MAIN_H */
