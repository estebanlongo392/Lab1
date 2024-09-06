/* USER CODE BEGIN Header */
/**
  ******************************************************************************
  * @file           : main.c
  * @brief          : Main program body
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
/* Includes ------------------------------------------------------------------*/
#include "main.h"

/* Private includes ----------------------------------------------------------*/
/* USER CODE BEGIN Includes */

/* USER CODE END Includes */

/* Private typedef -----------------------------------------------------------*/
/* USER CODE BEGIN PTD */

/* USER CODE END PTD */

/* Private define ------------------------------------------------------------*/
/* USER CODE BEGIN PD */

/* USER CODE END PD */

/* Private macro -------------------------------------------------------------*/
/* USER CODE BEGIN PM */

/* USER CODE END PM */

/* Private variables ---------------------------------------------------------*/

/* USER CODE BEGIN PV */
uint8_t jugador1 = 0;
uint8_t jugador2 = 0;
uint8_t start = 0;
/* USER CODE END PV */

/* Private function prototypes -----------------------------------------------*/
void SystemClock_Config(void);
static void MX_GPIO_Init(void);
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
  /* USER CODE BEGIN 2 */

  /* USER CODE END 2 */

  /* Infinite loop */
  /* USER CODE BEGIN WHILE */
  while (1)
  {
	  if(HAL_GPIO_ReadPin(START_GPIO_Port, START_Pin) == 0){
		  start = 1;
		  HAL_GPIO_WritePin(RED_GPIO_Port, RED_Pin, GPIO_PIN_SET);
		  HAL_Delay(500);
		  HAL_GPIO_WritePin(RED_GPIO_Port, RED_Pin, GPIO_PIN_RESET);
		  HAL_GPIO_WritePin(YELLOW_GPIO_Port, YELLOW_Pin, GPIO_PIN_SET);
		  HAL_Delay(500);
		  HAL_GPIO_WritePin(YELLOW_GPIO_Port, YELLOW_Pin, GPIO_PIN_RESET);
		  HAL_GPIO_WritePin(GREEN_GPIO_Port, GREEN_Pin, GPIO_PIN_SET);
		  HAL_Delay(500);
	  }
	  	  while(start == 1){

			  if(HAL_GPIO_ReadPin(BTN1_GPIO_Port, BTN1_Pin) == 0){
				  jugador1 = jugador1 + 1;
				  HAL_Delay (500);
			  }
			  if(HAL_GPIO_ReadPin(BTN2_GPIO_Port, BTN2_Pin) == 0){
				  jugador2 = jugador2 + 1;
				  HAL_Delay (500);
			  }

			  switch (jugador1) {
				case 1:
					HAL_GPIO_WritePin(LED1_1_GPIO_Port, LED1_1_Pin, GPIO_PIN_SET);
					break;
				case 2:
					HAL_GPIO_WritePin(LED1_1_GPIO_Port, LED1_1_Pin, GPIO_PIN_RESET);
					HAL_GPIO_WritePin(LED1_2_GPIO_Port, LED1_2_Pin, GPIO_PIN_SET);
					break;
				case 3:
					HAL_GPIO_WritePin(LED1_2_GPIO_Port, LED1_2_Pin, GPIO_PIN_RESET);
					HAL_GPIO_WritePin(LED1_3_GPIO_Port, LED1_3_Pin, GPIO_PIN_SET);
					break;
				case 4:
					HAL_GPIO_WritePin(LED1_3_GPIO_Port, LED1_3_Pin, GPIO_PIN_RESET);
					HAL_GPIO_WritePin(LED1_4_GPIO_Port, LED1_4_Pin, GPIO_PIN_SET);
					break;
				case 5:
					HAL_GPIO_WritePin(LED1_4_GPIO_Port, LED1_4_Pin, GPIO_PIN_RESET);
					HAL_GPIO_WritePin(LED1_5_GPIO_Port, LED1_5_Pin, GPIO_PIN_SET);
					break;
				case 6:
					HAL_GPIO_WritePin(LED1_5_GPIO_Port, LED1_5_Pin, GPIO_PIN_RESET);
					HAL_GPIO_WritePin(LED1_6_GPIO_Port, LED1_6_Pin, GPIO_PIN_SET);
					break;
				case 7:
					HAL_GPIO_WritePin(LED1_6_GPIO_Port, LED1_6_Pin, GPIO_PIN_RESET);
					HAL_GPIO_WritePin(LED1_7_GPIO_Port, LED1_7_Pin, GPIO_PIN_SET);
					break;
				case 8:
					HAL_GPIO_WritePin(LED1_7_GPIO_Port, LED1_7_Pin, GPIO_PIN_RESET);
					HAL_GPIO_WritePin(LED1_8_GPIO_Port, LED1_8_Pin, GPIO_PIN_SET);
					break;
			}

			  switch (jugador2) {
			  	 case 1:
			  		HAL_GPIO_WritePin(LED2_1_GPIO_Port, LED2_1_Pin, GPIO_PIN_SET);
			  		break;
			  	 case 2:
			  		HAL_GPIO_WritePin(LED2_1_GPIO_Port, LED2_1_Pin, GPIO_PIN_RESET);
			  		HAL_GPIO_WritePin(LED2_2_GPIO_Port, LED2_2_Pin, GPIO_PIN_SET);
			  		break;
			     case 3:
			    	HAL_GPIO_WritePin(LED2_2_GPIO_Port, LED2_2_Pin, GPIO_PIN_RESET);
			  		HAL_GPIO_WritePin(LED2_3_GPIO_Port, LED2_3_Pin, GPIO_PIN_SET);
			  		break;
			  	 case 4:
			  		HAL_GPIO_WritePin(LED2_3_GPIO_Port, LED2_3_Pin, GPIO_PIN_RESET);
			  		HAL_GPIO_WritePin(LED2_4_GPIO_Port, LED2_4_Pin, GPIO_PIN_SET);
			  		break;
			  	 case 5:
			  		HAL_GPIO_WritePin(LED2_4_GPIO_Port, LED2_4_Pin, GPIO_PIN_RESET);
			  		HAL_GPIO_WritePin(LED2_5_GPIO_Port, LED2_5_Pin, GPIO_PIN_SET);
			  		break;
			  	 case 6:
			  		HAL_GPIO_WritePin(LED2_5_GPIO_Port, LED2_5_Pin, GPIO_PIN_RESET);
			  		HAL_GPIO_WritePin(LED2_6_GPIO_Port, LED2_6_Pin, GPIO_PIN_SET);
			  		break;
			  	 case 7:
			  		HAL_GPIO_WritePin(LED2_6_GPIO_Port, LED2_6_Pin, GPIO_PIN_RESET);
			  		HAL_GPIO_WritePin(LED2_7_GPIO_Port, LED2_7_Pin, GPIO_PIN_SET);
			  		break;
			  	 case 8:
			  		HAL_GPIO_WritePin(LED2_7_GPIO_Port, LED2_7_Pin, GPIO_PIN_RESET);
			  		HAL_GPIO_WritePin(LED2_8_GPIO_Port, LED2_8_Pin, GPIO_PIN_SET);
			  		break;
			  			}
			  if (jugador1 >= 9) {
				jugador2 = 0;
				start = 0;
				HAL_GPIO_WritePin(Gana2_GPIO_Port, Gana2_Pin, GPIO_PIN_SET);
				HAL_GPIO_WritePin(LED2_1_GPIO_Port, LED2_1_Pin, GPIO_PIN_RESET);
				HAL_GPIO_WritePin(LED2_2_GPIO_Port, LED2_2_Pin, GPIO_PIN_RESET);
				HAL_GPIO_WritePin(LED2_3_GPIO_Port, LED2_3_Pin, GPIO_PIN_RESET);
				HAL_GPIO_WritePin(LED2_4_GPIO_Port, LED2_4_Pin, GPIO_PIN_RESET);
				HAL_GPIO_WritePin(LED2_5_GPIO_Port, LED2_5_Pin, GPIO_PIN_RESET);
				HAL_GPIO_WritePin(LED2_6_GPIO_Port, LED2_6_Pin, GPIO_PIN_RESET);
				HAL_GPIO_WritePin(LED2_7_GPIO_Port, LED2_7_Pin, GPIO_PIN_RESET);
				HAL_GPIO_WritePin(LED2_8_GPIO_Port, LED2_8_Pin, GPIO_PIN_RESET);
			  }
			  if (jugador2 >= 9) {
			 	jugador1 = 0;
			 	start = 0;
			 	HAL_GPIO_WritePin(Gana1_GPIO_Port, Gana1_Pin, GPIO_PIN_SET);
			 	HAL_GPIO_WritePin(LED1_1_GPIO_Port, LED1_1_Pin, GPIO_PIN_RESET);
			 	HAL_GPIO_WritePin(LED1_2_GPIO_Port, LED1_2_Pin, GPIO_PIN_RESET);
			 	HAL_GPIO_WritePin(LED1_3_GPIO_Port, LED1_3_Pin, GPIO_PIN_RESET);
			 	HAL_GPIO_WritePin(LED1_4_GPIO_Port, LED1_4_Pin, GPIO_PIN_RESET);
			 	HAL_GPIO_WritePin(LED1_5_GPIO_Port, LED1_5_Pin, GPIO_PIN_RESET);
			 	HAL_GPIO_WritePin(LED1_6_GPIO_Port, LED1_6_Pin, GPIO_PIN_RESET);
			 	HAL_GPIO_WritePin(LED1_7_GPIO_Port, LED1_7_Pin, GPIO_PIN_RESET);
			 	HAL_GPIO_WritePin(LED1_8_GPIO_Port, LED1_8_Pin, GPIO_PIN_RESET);
			  }

	  }
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

  /** Configure the main internal regulator output voltage
  */
  __HAL_RCC_PWR_CLK_ENABLE();
  __HAL_PWR_VOLTAGESCALING_CONFIG(PWR_REGULATOR_VOLTAGE_SCALE3);

  /** Initializes the RCC Oscillators according to the specified parameters
  * in the RCC_OscInitTypeDef structure.
  */
  RCC_OscInitStruct.OscillatorType = RCC_OSCILLATORTYPE_HSI;
  RCC_OscInitStruct.HSIState = RCC_HSI_ON;
  RCC_OscInitStruct.HSICalibrationValue = RCC_HSICALIBRATION_DEFAULT;
  RCC_OscInitStruct.PLL.PLLState = RCC_PLL_NONE;
  if (HAL_RCC_OscConfig(&RCC_OscInitStruct) != HAL_OK)
  {
    Error_Handler();
  }

  /** Initializes the CPU, AHB and APB buses clocks
  */
  RCC_ClkInitStruct.ClockType = RCC_CLOCKTYPE_HCLK|RCC_CLOCKTYPE_SYSCLK
                              |RCC_CLOCKTYPE_PCLK1|RCC_CLOCKTYPE_PCLK2;
  RCC_ClkInitStruct.SYSCLKSource = RCC_SYSCLKSOURCE_HSI;
  RCC_ClkInitStruct.AHBCLKDivider = RCC_SYSCLK_DIV1;
  RCC_ClkInitStruct.APB1CLKDivider = RCC_HCLK_DIV1;
  RCC_ClkInitStruct.APB2CLKDivider = RCC_HCLK_DIV1;

  if (HAL_RCC_ClockConfig(&RCC_ClkInitStruct, FLASH_LATENCY_0) != HAL_OK)
  {
    Error_Handler();
  }
}

/**
  * @brief GPIO Initialization Function
  * @param None
  * @retval None
  */
static void MX_GPIO_Init(void)
{
  GPIO_InitTypeDef GPIO_InitStruct = {0};
/* USER CODE BEGIN MX_GPIO_Init_1 */
/* USER CODE END MX_GPIO_Init_1 */

  /* GPIO Ports Clock Enable */
  __HAL_RCC_GPIOC_CLK_ENABLE();
  __HAL_RCC_GPIOA_CLK_ENABLE();
  __HAL_RCC_GPIOB_CLK_ENABLE();

  /*Configure GPIO pin Output Level */
  HAL_GPIO_WritePin(GPIOC, LED1_1_Pin|LED1_2_Pin|LED1_3_Pin|LED1_4_Pin
                          |LED1_5_Pin|LED1_6_Pin|LED1_8_Pin|LED1_7_Pin, GPIO_PIN_RESET);

  /*Configure GPIO pin Output Level */
  HAL_GPIO_WritePin(GPIOA, RED_Pin|YELLOW_Pin|GREEN_Pin|Gana1_Pin
                          |Gana2_Pin, GPIO_PIN_RESET);

  /*Configure GPIO pin Output Level */
  HAL_GPIO_WritePin(GPIOB, LED2_1_Pin|LED2_2_Pin|LED2_3_Pin|LED2_4_Pin
                          |LED2_5_Pin|LED2_6_Pin|LED2_7_Pin|LED2_8_Pin, GPIO_PIN_RESET);

  /*Configure GPIO pins : LED1_1_Pin LED1_2_Pin LED1_3_Pin LED1_4_Pin
                           LED1_5_Pin LED1_6_Pin LED1_8_Pin LED1_7_Pin */
  GPIO_InitStruct.Pin = LED1_1_Pin|LED1_2_Pin|LED1_3_Pin|LED1_4_Pin
                          |LED1_5_Pin|LED1_6_Pin|LED1_8_Pin|LED1_7_Pin;
  GPIO_InitStruct.Mode = GPIO_MODE_OUTPUT_PP;
  GPIO_InitStruct.Pull = GPIO_NOPULL;
  GPIO_InitStruct.Speed = GPIO_SPEED_FREQ_LOW;
  HAL_GPIO_Init(GPIOC, &GPIO_InitStruct);

  /*Configure GPIO pins : RED_Pin YELLOW_Pin GREEN_Pin Gana1_Pin
                           Gana2_Pin */
  GPIO_InitStruct.Pin = RED_Pin|YELLOW_Pin|GREEN_Pin|Gana1_Pin
                          |Gana2_Pin;
  GPIO_InitStruct.Mode = GPIO_MODE_OUTPUT_PP;
  GPIO_InitStruct.Pull = GPIO_NOPULL;
  GPIO_InitStruct.Speed = GPIO_SPEED_FREQ_LOW;
  HAL_GPIO_Init(GPIOA, &GPIO_InitStruct);

  /*Configure GPIO pins : LED2_1_Pin LED2_2_Pin LED2_3_Pin LED2_4_Pin
                           LED2_5_Pin LED2_6_Pin LED2_7_Pin LED2_8_Pin */
  GPIO_InitStruct.Pin = LED2_1_Pin|LED2_2_Pin|LED2_3_Pin|LED2_4_Pin
                          |LED2_5_Pin|LED2_6_Pin|LED2_7_Pin|LED2_8_Pin;
  GPIO_InitStruct.Mode = GPIO_MODE_OUTPUT_PP;
  GPIO_InitStruct.Pull = GPIO_NOPULL;
  GPIO_InitStruct.Speed = GPIO_SPEED_FREQ_LOW;
  HAL_GPIO_Init(GPIOB, &GPIO_InitStruct);

  /*Configure GPIO pins : BTN1_Pin BTN2_Pin START_Pin */
  GPIO_InitStruct.Pin = BTN1_Pin|BTN2_Pin|START_Pin;
  GPIO_InitStruct.Mode = GPIO_MODE_INPUT;
  GPIO_InitStruct.Pull = GPIO_PULLUP;
  HAL_GPIO_Init(GPIOC, &GPIO_InitStruct);

/* USER CODE BEGIN MX_GPIO_Init_2 */
/* USER CODE END MX_GPIO_Init_2 */
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
