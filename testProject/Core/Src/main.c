/* USER CODE BEGIN Header */
/**
  ******************************************************************************
  * @file           : main.c
  * @brief          : Main program body
  ******************************************************************************
  * @attention
  *
  * <h2><center>&copy; Copyright (c) 2022 STMicroelectronics.
  * All rights reserved.</center></h2>
  *
  * This software component is licensed by ST under BSD 3-Clause license,
  * the "License"; You may not use this file except in compliance with the
  * License. You may obtain a copy of the License at:
  *                        opensource.org/licenses/BSD-3-Clause
  *
  ******************************************************************************
  */
/* USER CODE END Header */
/* Includes ------------------------------------------------------------------*/
#include "main.h"
#include "practicalFunctions.h"
#include "leds.h"

#include "main.h"
#include "stm32f3xx_hal.h"
#include "usb_device.h"


typedef struct packet_t
{
	short Gx;
	short Gy;
	short Gz;
	short t;
	short Gx_int;
	short Gy_int;
	short Gz_int;
}packet_t;

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
  /* USER CODE BEGIN 2 */

  setupFlash();
  setupPll();
  powerOn();
//  setupLight();
  setupI2C1();
  setupSpi1();

  setupGyroscope();
  char accData[10];
  short ax, ay, az;
  packet_t buf;


  char data[10]; //массив с переданными или полученными данными
  //настраиваем блок акселерометров
  data[0] = 0x20; //обращаемся к регистру CTRL_REG1_A по адресу 20h//запоминаем адрес регистра
  data[1] = 0x57; //заполняем регистр//записываем данные
  writeAcc(0x19, data, 2, 1);//подключаемся к акселерометру, настраиваем параметры обмена информацией
  char buffer[128];
  /* USER CODE END 2 */

  /* Infinite loop */
  /* USER CODE BEGIN WHILE */
  while (1)
  {
    /* USER CODE END WHILE */
//	  clock();
	  if(GPIOE->IDR & 2)
	  {

	  		 // CDC_Transmit_FS("sss", 3);
	  //		  buf.t = 44 - readGyroscopeRegister(0x26);
//		  readGyroscopeData(&buf.Gx, &buf.Gy, &buf.Gz);
	      getAcc(accData);
	      ax = (accData[1] << 8) + accData[0];
	      ay = (accData[3] << 8) + accData[2];
	      az = (accData[5] << 8) + accData[4];

//	      displayDown(ax, ay);
	      displayLevel(ax, ay);
//	      sprintf(buffer, "sync,%d,%d,%d,%d,%d,%d\r\n", buf.Gx, buf.Gy, buf.Gz, ax, ay, az);
	      sprintf(buffer, "sync,%d,%d,%d\r\n", ax, ay, az);
	  	  CDC_Transmit_FS(buffer, strlen(buffer));

	  		  //temp = readGyroscopeRegister(0x25);
	  		  //sprintf(buffer,"%d\r\n",(int)temp);
	  		  //CDC_Transmit_FS(buffer, strlen(buffer));
	  		  //HAL_Delay(1000);
	  }
    /* USER CODE BEGIN 3 */
  }
  /* USER CODE END 3 */
}

void myTimerInterruptHandler(void)
{
//	SwitchLed(13);
//	TIM1->SR &= ~1;
}

/**
  * @brief System Clock Configuration
  * @retval None
  */
void SystemClock_Config(void)
{
  RCC_OscInitTypeDef RCC_OscInitStruct = {0};
  RCC_ClkInitTypeDef RCC_ClkInitStruct = {0};

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

/************************ (C) COPYRIGHT STMicroelectronics *****END OF FILE****/
