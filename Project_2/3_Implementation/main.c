#include "MyStm32f407xx.h"
#include <stdint.h>

#define BUTTON7_PRESSED ENABLE

void glass(void); 
void buzzer(void);
void battery(void);
void car_door(void);
void bmw(void);
void bmw_2(void);
void bmw_3(void);
void bmw_4(void);


/**
 * @brief This function is to enable debouncing delay of blue switch
 */


void delay(void)
{
	for(uint32_t i=0; i<30000000; i++);
}

int main(void)
{

	GPIO_Handle_t GpioLed, GPIOBtn; 							//Initialisation for blue switch and LED
	/**
	 * 
	 *
	 * @brief Setup for LEDs
	 *
	 * 
	 */
	
	
	
	GpioLed.pGPIOx = GPIOD;
	GpioLed.GPIO_PinConfig.GPIO_PinNumber = GPIO_PIN_NO_12 ;	//Green LED
	GpioLed.GPIO_PinConfig.GPIO_PinMode = GPIO_MODE_OUT;
	GpioLed.GPIO_PinConfig.GPIO_PinSpeed = GPIO_SPEED_FAST;
	GpioLed.GPIO_PinConfig.GPIO_PinOPType = GPIO_OP_TYPE_PP;
	GPIO_PeriClockControl(GPIOD, ENABLE);
	GPIO_Init(&GpioLed);

 	GpioLed.pGPIOx = GPIOD;
	GpioLed.GPIO_PinConfig.GPIO_PinNumber = GPIO_PIN_NO_13;		//Orange LED
	GpioLed.GPIO_PinConfig.GPIO_PinMode = GPIO_MODE_OUT;
	GpioLed.GPIO_PinConfig.GPIO_PinSpeed = GPIO_SPEED_FAST;
	GpioLed.GPIO_PinConfig.GPIO_PinOPType = GPIO_OP_TYPE_PP;
	GPIO_PeriClockControl(GPIOD, ENABLE);
	GPIO_Init(&GpioLed);

	GpioLed.pGPIOx = GPIOD;
	GpioLed.GPIO_PinConfig.GPIO_PinNumber = GPIO_PIN_NO_14;		//Red LED
	GpioLed.GPIO_PinConfig.GPIO_PinMode = GPIO_MODE_OUT;
	GpioLed.GPIO_PinConfig.GPIO_PinSpeed = GPIO_SPEED_FAST;
	GpioLed.GPIO_PinConfig.GPIO_PinOPType = GPIO_OP_TYPE_PP;
	GPIO_PeriClockControl(GPIOD, ENABLE);
	GPIO_Init(&GpioLed);

	GpioLed.pGPIOx = GPIOD;
	GpioLed.GPIO_PinConfig.GPIO_PinNumber = GPIO_PIN_NO_15;		//Blue LED
	GpioLed.GPIO_PinConfig.GPIO_PinMode = GPIO_MODE_OUT;
	GpioLed.GPIO_PinConfig.GPIO_PinSpeed = GPIO_SPEED_FAST;
	GpioLed.GPIO_PinConfig.GPIO_PinOPType = GPIO_OP_TYPE_PP;
	GPIO_PeriClockControl(GPIOD, ENABLE);
	GPIO_Init(&GpioLed);
	/**
	 * @brief Setup for Blue Switch
	 *
	 */
	GPIOBtn.pGPIOx = GPIOA;
    GPIOBtn.GPIO_PinConfig.GPIO_PinNumber = GPIO_PIN_NO_0;
	GPIOBtn.GPIO_PinConfig.GPIO_PinMode = GPIO_MODE_IN;
	GPIOBtn.GPIO_PinConfig.GPIO_PinSpeed = GPIO_SPEED_FAST;
	GPIOBtn.GPIO_PinConfig.GPIO_PinPuPdControl = GPIO_NO_PUPD;
	GPIO_PeriClockControl(GPIOA, ENABLE);
	GPIO_Init(&GPIOBtn);

	while(1)
	{
		bmw();				    //encryption for glass function

		bmw_2();				//encryption for buzzer function

		bmw_3();				//encryption for battery function

		bmw_4();				//encryption for car_door function

	}

}
/**
 * @brief encryption for glass function
 *
 */
void bmw(void)
{
	p1:if(GPIO_ReadFromInputPin(GPIOA, GPIO_PIN_NO_0)== BUTTON7_PRESSED)
	{
		glass();
	}
	else
	goto p1;

}

/**
 * @brief encryption for buzzer function
 *
 */
void bmw_2(void)
{
	uint32_t i=0, count = 1;
	for(i=0;i<2;i++)
	{
	if(GPIO_ReadFromInputPin(GPIOA, GPIO_PIN_NO_0)== BUTTON7_PRESSED)
		count++;
	else
		i=0;
	}
	if(count==2)
		{

			buzzer();

		}
}
/**
 * @brief encryption for battery function
 *
 */
void bmw_3(void)
{
	uint32_t i=0, count = 1;
	for(i=0;i<3;i++)
	{
	if(GPIO_ReadFromInputPin(GPIOA, GPIO_PIN_NO_0)== BUTTON7_PRESSED)
		count++;
	else
		i=0;
	}
	if(count==3)
		{

			battery();

		}
}
/**
 * @brief encryption for the car_door function
 *
 */
void bmw_4(void)
{
	uint32_t i=0, count = 1;
	for(i=0;i<4;i++)
	{
	if(GPIO_ReadFromInputPin(GPIOA, GPIO_PIN_NO_0)== BUTTON7_PRESSED)
		count++;
	else
		i=0;
	}
	if(count==4)
		{

			car_door();

		}
}




/**
 * @brief glass function for glass status
 *
 */
void glass(void)
{
	delay();
	GPIO_ToggleOutputPin(GPIOD, GPIO_PIN_NO_12);
	GPIO_ToggleOutputPin(GPIOD, GPIO_PIN_NO_13);
	GPIO_ToggleOutputPin(GPIOD, GPIO_PIN_NO_14);
	GPIO_ToggleOutputPin(GPIOD, GPIO_PIN_NO_15);
}
/**
 * @brief buzzer function for buzzer status
 *
 */
void buzzer(void)
{
	delay();
	GPIO_WriteToOutputPin(GPIOD, GPIO_PIN_NO_12, 0);
	GPIO_WriteToOutputPin(GPIOD, GPIO_PIN_NO_13, 0);
	GPIO_WriteToOutputPin(GPIOD, GPIO_PIN_NO_14, 0);
	GPIO_WriteToOutputPin(GPIOD, GPIO_PIN_NO_15, 0);
}
/**
 * @brief battery function for battery info
 *
 */
void battery(void)
{
	delay();
	GPIO_ToggleOutputPin(GPIOD, GPIO_PIN_NO_12);
	delay();
	GPIO_ToggleOutputPin(GPIOD, GPIO_PIN_NO_13);
	delay();
	GPIO_ToggleOutputPin(GPIOD, GPIO_PIN_NO_14);
	delay();
	GPIO_ToggleOutputPin(GPIOD, GPIO_PIN_NO_15);
	delay();
	GPIO_WriteToOutputPin(GPIOD, GPIO_PIN_NO_12, 0);
	delay();
	GPIO_WriteToOutputPin(GPIOD, GPIO_PIN_NO_13, 0);
	delay();
	GPIO_WriteToOutputPin(GPIOD, GPIO_PIN_NO_14, 0);
	delay();
	GPIO_WriteToOutputPin(GPIOD, GPIO_PIN_NO_15, 0);
}
/**
 * @brief car_door function for car_door status
 *
 */
void car_door(void)
{
	delay();
	GPIO_ToggleOutputPin(GPIOD, GPIO_PIN_NO_12);
	delay();
	GPIO_ToggleOutputPin(GPIOD, GPIO_PIN_NO_15);
	delay();
	GPIO_ToggleOutputPin(GPIOD, GPIO_PIN_NO_14);
	delay();
	GPIO_ToggleOutputPin(GPIOD, GPIO_PIN_NO_13);
	delay();
	GPIO_WriteToOutputPin(GPIOD, GPIO_PIN_NO_12, 0);
	delay();
	GPIO_WriteToOutputPin(GPIOD, GPIO_PIN_NO_15, 0);
	delay();
	GPIO_WriteToOutputPin(GPIOD, GPIO_PIN_NO_14, 0);
	delay();
	GPIO_WriteToOutputPin(GPIOD, GPIO_PIN_NO_13, 0);
}
