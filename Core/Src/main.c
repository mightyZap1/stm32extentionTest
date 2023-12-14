/* USER CODE BEGIN Header */
/**
  ******************************************************************************
  * @file           : main.c
  * @brief          : Main program body
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
/* Includes ------------------------------------------------------------------*/
#include "main.h"
#include "tim.h"
#include "usart.h"
#include "gpio.h"

/* Private includes ----------------------------------------------------------*/
/* USER CODE BEGIN Includes */
  uint8_t rxData[1];
/* USER CODE END Includes */

/* Private typedef -----------------------------------------------------------*/
/* USER CODE BEGIN PTD */

/* USER CODE END PTD */

/* Private define ------------------------------------------------------------*/
/* USER CODE BEGIN PD */
void HAL_UART_RxCpltCallback(UART_HandleTypeDef* huart) {
  if (huart->Instance == USART1) {
    HAL_UART_Transmit(&huart1, (uint8_t*)rxData, strlen(rxData), HAL_MAX_DELAY);
  }
  HAL_UART_Receive_IT(&huart1 , (uint8_t*)&rxData , 1);
}

/* USER CODE END PD */

/* Private macro -------------------------------------------------------------*/
/* USER CODE BEGIN PM */

/* USER CODE END PM */

/* Private variables ---------------------------------------------------------*/

/* USER CODE BEGIN PV */

/* USER CODE END PV */

/* Private function prototypes -----------------------------------------------*/
void SystemClock_Config(void);
/* USER CODE BEGIN PFP */

/* USER CODE END PFP */

/* Private user code ---------------------------------------------------------*/
/* USER CODE BEGIN 0 */

/* USER CODE END 0 */

/**
  * @brief  The application entry point.
  * @retval int
  */
int main(void)
{
  /* USER CODE BEGIN 1 */

  /* USER CODE END 1 */

  /* MCU Configuration--------------------------------------------------------*/

  /* Reset of all peripherals, Initializes the Flash interface and the Systick. */
  HAL_Init();

  /* USER CODE BEGIN Init */

  /* USER CODE END Init */

  /* Configure the system clock */
  SystemClock_Config();

  /* USER CODE BEGIN SysInit */

  /* USER CODE END SysInit */

  /* Initialize all configured peripherals */
  MX_GPIO_Init();
  MX_TIM2_Init();
  MX_USART1_UART_Init();
  /* USER CODE BEGIN 2 */
  
  HAL_TIM_PWM_Start(&htim2 , TIM_CHANNEL_1);
  HAL_TIM_PWM_Start(&htim2 , TIM_CHANNEL_2);
  HAL_TIM_PWM_Start(&htim2 , TIM_CHANNEL_3);
  HAL_UART_Receive_IT(&huart1 , (uint8_t*)&rxData , 1);
  HAL_GPIO_WritePin(DRVRESET_GPIO_Port,DRVRESET_Pin,GPIO_PIN_SET);
  /* USER CODE END 2 */

  /* Infinite loop */
  /* USER CODE BEGIN WHILE */
  uint8_t hallValue[3];
    char uartData=0;
  while (1)
  {
    hallValue[0] = HAL_GPIO_ReadPin(GPIOA, HALL_U_Pin);
    hallValue[1] = HAL_GPIO_ReadPin(GPIOA, HALL_V_Pin);
    hallValue[2] =HAL_GPIO_ReadPin(GPIOA, HALL_W_Pin);

    // HAL_UART_Transmit(&huart1, &hallValue, sizeof(hallValue), HAL_MAX_DELAY);
  uint8_t data = hallValue[0]*100+hallValue[1]*10+hallValue[2];
  uint16_t dutyrate=800;

  char buffer[50];

  sprintf(buffer, "Hall Values: %d %d %d %d\r\n", hallValue[0], hallValue[1], hallValue[2],uartData);
  HAL_UART_Transmit(&huart1, (uint8_t*)buffer, strlen(buffer), HAL_MAX_DELAY);
  // HAL_UART_Receive_IT(&huart1 , (uint8_t*)&uartData , 1);
  // while (HAL_UART_Receive(&huart1, &uartData, sizeof(uartData), 0) != HAL_OK){};
  // HAL_UART_Receive(&huart1, &uartData, sizeof(uartData), 0);
  // HAL_UART_Transmit(&huart1, (uint8_t*)buffer, strlen(buffer), HAL_MAX_DELAY);
uartData =0;
  switch(uartData){
    case 1:
        __HAL_TIM_SET_COMPARE(&htim2,TIM_CHANNEL_1,0);
        __HAL_TIM_SET_COMPARE(&htim2,TIM_CHANNEL_2,dutyrate);
        __HAL_TIM_SET_COMPARE(&htim2,TIM_CHANNEL_3,0);
        HAL_GPIO_WritePin(EN_U_GPIO_Port,EN_U_Pin,GPIO_PIN_RESET);
        HAL_GPIO_WritePin(EN_V_GPIO_Port,EN_V_Pin,GPIO_PIN_SET);
        HAL_GPIO_WritePin(EN_W_GPIO_Port,EN_W_Pin,GPIO_PIN_SET);

      break;
    case 2:
      __HAL_TIM_SET_COMPARE(&htim2,TIM_CHANNEL_1,dutyrate);
      __HAL_TIM_SET_COMPARE(&htim2,TIM_CHANNEL_2,0);
      __HAL_TIM_SET_COMPARE(&htim2,TIM_CHANNEL_3,0);
      HAL_GPIO_WritePin(EN_U_GPIO_Port,EN_U_Pin,GPIO_PIN_SET);
      HAL_GPIO_WritePin(EN_V_GPIO_Port,EN_V_Pin,GPIO_PIN_RESET);
      HAL_GPIO_WritePin(EN_W_GPIO_Port,EN_W_Pin,GPIO_PIN_SET);
      break;
    case 3:
      __HAL_TIM_SET_COMPARE(&htim2,TIM_CHANNEL_1,dutyrate);
      __HAL_TIM_SET_COMPARE(&htim2,TIM_CHANNEL_2,0);
      __HAL_TIM_SET_COMPARE(&htim2,TIM_CHANNEL_3,0);
      HAL_GPIO_WritePin(EN_U_GPIO_Port,EN_U_Pin,GPIO_PIN_SET);
      HAL_GPIO_WritePin(EN_V_GPIO_Port,EN_V_Pin,GPIO_PIN_SET);
      HAL_GPIO_WritePin(EN_W_GPIO_Port,EN_W_Pin,GPIO_PIN_RESET);
      break;
    case 4:
      __HAL_TIM_SET_COMPARE(&htim2,TIM_CHANNEL_1,0);
      __HAL_TIM_SET_COMPARE(&htim2,TIM_CHANNEL_2,0);
      __HAL_TIM_SET_COMPARE(&htim2,TIM_CHANNEL_3,dutyrate);
      HAL_GPIO_WritePin(EN_U_GPIO_Port,EN_U_Pin,GPIO_PIN_RESET);
      HAL_GPIO_WritePin(EN_V_GPIO_Port,EN_V_Pin,GPIO_PIN_SET);
      HAL_GPIO_WritePin(EN_W_GPIO_Port,EN_W_Pin,GPIO_PIN_SET);
      break;
    case 5:
      __HAL_TIM_SET_COMPARE(&htim2,TIM_CHANNEL_1,0);
      __HAL_TIM_SET_COMPARE(&htim2,TIM_CHANNEL_2,0);
      __HAL_TIM_SET_COMPARE(&htim2,TIM_CHANNEL_3,dutyrate);
      HAL_GPIO_WritePin(EN_U_GPIO_Port,EN_U_Pin,GPIO_PIN_SET);
      HAL_GPIO_WritePin(EN_V_GPIO_Port,EN_V_Pin,GPIO_PIN_RESET);
      HAL_GPIO_WritePin(EN_W_GPIO_Port,EN_W_Pin,GPIO_PIN_SET);
      break;
    case 6:
      __HAL_TIM_SET_COMPARE(&htim2,TIM_CHANNEL_1,0);
      __HAL_TIM_SET_COMPARE(&htim2,TIM_CHANNEL_2,dutyrate);
      __HAL_TIM_SET_COMPARE(&htim2,TIM_CHANNEL_3,0);
      HAL_GPIO_WritePin(EN_U_GPIO_Port,EN_U_Pin,GPIO_PIN_SET);
      HAL_GPIO_WritePin(EN_V_GPIO_Port,EN_V_Pin,GPIO_PIN_SET);
      HAL_GPIO_WritePin(EN_W_GPIO_Port,EN_W_Pin,GPIO_PIN_RESET);
      break;
    // case 0:

  } 
  

  
    

   
    HAL_Delay(1000);

    
// 
    /* USER CODE END WHILE */

    /* USER CODE BEGIN 3 */
  }
  /* USER CODE END 3 */
}

/**
  * @brief System Clock Configuration
  * @retval None
  */
void SystemClock_Config(void)
{
  RCC_OscInitTypeDef RCC_OscInitStruct = {0};
  RCC_ClkInitTypeDef RCC_ClkInitStruct = {0};
  RCC_PeriphCLKInitTypeDef PeriphClkInit = {0};

  /** Initializes the RCC Oscillators according to the specified parameters
  * in the RCC_OscInitTypeDef structure.
  */
  RCC_OscInitStruct.OscillatorType = RCC_OSCILLATORTYPE_HSI;
  RCC_OscInitStruct.HSIState = RCC_HSI_ON;
  RCC_OscInitStruct.HSICalibrationValue = RCC_HSICALIBRATION_DEFAULT;
  RCC_OscInitStruct.PLL.PLLState = RCC_PLL_ON;
  RCC_OscInitStruct.PLL.PLLSource = RCC_PLLSOURCE_HSI;
  RCC_OscInitStruct.PLL.PLLMUL = RCC_PLL_MUL16;
  if (HAL_RCC_OscConfig(&RCC_OscInitStruct) != HAL_OK)
  {
    Error_Handler();
  }

  /** Initializes the CPU, AHB and APB buses clocks
  */
  RCC_ClkInitStruct.ClockType = RCC_CLOCKTYPE_HCLK|RCC_CLOCKTYPE_SYSCLK
                              |RCC_CLOCKTYPE_PCLK1|RCC_CLOCKTYPE_PCLK2;
  RCC_ClkInitStruct.SYSCLKSource = RCC_SYSCLKSOURCE_PLLCLK;
  RCC_ClkInitStruct.AHBCLKDivider = RCC_SYSCLK_DIV1;
  RCC_ClkInitStruct.APB1CLKDivider = RCC_HCLK_DIV2;
  RCC_ClkInitStruct.APB2CLKDivider = RCC_HCLK_DIV1;

  if (HAL_RCC_ClockConfig(&RCC_ClkInitStruct, FLASH_LATENCY_2) != HAL_OK)
  {
    Error_Handler();
  }
  PeriphClkInit.PeriphClockSelection = RCC_PERIPHCLK_USART1;
  PeriphClkInit.Usart1ClockSelection = RCC_USART1CLKSOURCE_PCLK1;
  if (HAL_RCCEx_PeriphCLKConfig(&PeriphClkInit) != HAL_OK)
  {
    Error_Handler();
  }
}

/* USER CODE BEGIN 4 */

/* USER CODE END 4 */

/**
  * @brief  This function is executed in case of error occurrence.
  * @retval None
  */
void Error_Handler(void)
{
  /* USER CODE BEGIN Error_Handler_Debug */
  /* User can add his own implementation to report the HAL error return state */
  __disable_irq();
  while (1)
  {
  }
  /* USER CODE END Error_Handler_Debug */
}

#ifdef  USE_FULL_ASSERT
/**
  * @brief  Reports the name of the source file and the source line number
  *         where the assert_param error has occurred.
  * @param  file: pointer to the source file name
  * @param  line: assert_param error line source number
  * @retval None
  */
void assert_failed(uint8_t *file, uint32_t line)
{
  /* USER CODE BEGIN 6 */
  /* User can add his own implementation to report the file name and line number,
     ex: printf("Wrong parameters value: file %s on line %d\r\n", file, line) */
  /* USER CODE END 6 */
}
#endif /* USE_FULL_ASSERT */
