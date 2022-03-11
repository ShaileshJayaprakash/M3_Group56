#include "MyStm32f407xx.h"
#include <stdint.h>

#define BUTTON7_PRESSED ENABLE

void Lock(void);
void Unlock(void);
void clockwise(void);
void anticlock(void);
void enc(void);
void enc_2(void);
void enc_3(void);
void enc_4(void);


void delay(void)
{
	for(uint32_t i=0; i<50000000; i++);
}

int main(void)
{

	GPIO_Handle_t GpioLed, GPIOBtn; 							//Initilize the Switch and LED pin

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


	GPIOBtn.pGPIOx = GPIOA;
    GPIOBtn.GPIO_PinConfig.GPIO_PinNumber = GPIO_PIN_NO_0;
	GPIOBtn.GPIO_PinConfig.GPIO_PinMode = GPIO_MODE_IN;
	GPIOBtn.GPIO_PinConfig.GPIO_PinSpeed = GPIO_SPEED_FAST;
	GPIOBtn.GPIO_PinConfig.GPIO_PinPuPdControl = GPIO_NO_PUPD;
	GPIO_PeriClockControl(GPIOA, ENABLE);
	GPIO_Init(&GPIOBtn);

	while(1)
	{
		enc();				//encryption for Lock function

		enc_2();				//encryption for Unlock function

		enc_3();				//encryption for clockwise function

		enc_4();				//encryption for anticlock function

	}

}

//Encryption for lock

void enc(void)
{
	p1:if(GPIO_ReadFromInputPin(GPIOA, GPIO_PIN_NO_0)== BUTTON7_PRESSED)
	{
		Lock();
	}
	else
		goto p1;

}


//Encryption for unlock

void enc_2(void)
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

			Unlock();

		}
}

//Encryption for clockwise

void enc_3(void)
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

			clockwise();

		}
}

// Encryption for anticlock

void enc_4(void)
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

			anticlock();

		}
}




//function for locking door
void Lock(void)
{
	delay();
	GPIO_ToggleOutputPin(GPIOD, GPIO_PIN_NO_12);
	GPIO_ToggleOutputPin(GPIOD, GPIO_PIN_NO_13);
	GPIO_ToggleOutputPin(GPIOD, GPIO_PIN_NO_14);
	GPIO_ToggleOutputPin(GPIOD, GPIO_PIN_NO_15);
}

// function for unlocking door
void Unlock(void)
{
	delay();
	GPIO_WriteToOutputPin(GPIOD, GPIO_PIN_NO_12, 0);
	GPIO_WriteToOutputPin(GPIOD, GPIO_PIN_NO_13, 0);
	GPIO_WriteToOutputPin(GPIOD, GPIO_PIN_NO_14, 0);
	GPIO_WriteToOutputPin(GPIOD, GPIO_PIN_NO_15, 0);
}

// Clockwise function for alarm
void clockwise(void)
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

// Anticlock function for approaching lights
void anticlock(void)
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


// Make file, linker file and startup file done by Shailesh Jayaprakash.
// Lock , unlock, clockwise and anticlock wise operations are done by Shailesh Jayaprakash and Savitha P through Webex call discussion.
