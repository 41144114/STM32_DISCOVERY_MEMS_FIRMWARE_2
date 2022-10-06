/*
 * leds.c
 *
 *  Created on: 6 окт. 2022 г.
 *      Author: 4091
 */
#include "stm32f3xx.h"
#include "leds.h"
#include <math.h>

void turnOnLed(int i)//включение диодов
{
	GPIOE->MODER &= ~(1 <<(i*2+1) );  	//Настраиваем режим ножки 01
	GPIOE->MODER |= (1 << i*2);
	GPIOE->ODR |= (1 << i);//включили
}

void turnOffLed(int i)
{
	GPIOE->MODER &= ~(1 << (i*2+1) );  	//Настраиваем режим ножки 01
	GPIOE->MODER |= (1 << i*2);
	GPIOE->ODR &= ~(1 << i);//выключили
}

void turnOffAllLeds()
{
	//выключаем отдельно каждый диод
	turnOffLed(9); //LD3
	turnOffLed(8); //LD4
	turnOffLed(10); //LD5
	turnOffLed(15); //LD6
	turnOffLed(11); //LD7
	turnOffLed(14); //LD8
	turnOffLed(12); //LD9
	turnOffLed(13); //LD10
}

void SwitchLed(int i)
{
	GPIOE->MODER &= ~(1 << (i*2+1) );  	//Настраиваем режим ножки 01
	GPIOE->MODER |= (1 << i*2);
	GPIOE->ODR ^= (1 << i);//выключили
}


void displayUp(short ax, short ay)
{
	turnOffAllLeds();//выключаем все диоды
	if(abs(ax) < 900 && abs(ay) < 900)//если очень маленькие значения, не обращать на них внимания
		return;

	float ugol = atan2(ay, ax)*57;//перевели в градусы

	if(ugol > -22.5 && ugol <= 22.5)
		turnOnLed(LD10);
	else if(ugol > 22.5 && ugol <= 67.5)
		turnOnLed(LD9);
	else if(ugol > 67.5 && ugol <= 112.5)
		turnOnLed(LD7);
	else if(ugol > 112.5 && ugol <= 157.5)
		turnOnLed(LD5);
	else if(ugol > 157.5 || ugol <= -157.5)
		turnOnLed(LD3);
	else if(ugol > -67.5 && ugol <= -22.5)
		turnOnLed(LD8);
	else if(ugol > -112.5 && ugol <= -67.5)
		turnOnLed(LD6);
	else if(ugol > -157.5 && ugol <= -112.5)
		turnOnLed(LD4);
}

void displayDown(short ax, short ay)
{
	turnOffAllLeds();//выключаем все диоды
	if(abs(ax) < 900 && abs(ay) < 900)//если очень маленькие значения, не обращать на них внимания
		return;

	float ugol = atan2(ay, ax)*57;//перевели в градусы

	if(ugol > -22.5 && ugol <= 22.5)
		turnOnLed(LD3);
	else if(ugol > 22.5 && ugol <= 67.5)
		turnOnLed(LD4);
	else if(ugol > 67.5 && ugol <= 112.5)
		turnOnLed(LD6);
	else if(ugol > 112.5 && ugol <= 157.5)
		turnOnLed(LD8);
	else if(ugol > 157.5 || ugol <= -157.5)
		turnOnLed(LD10);
	else if(ugol > -67.5 && ugol <= -22.5)
		turnOnLed(LD5);
	else if(ugol > -112.5 && ugol <= -67.5)
		turnOnLed(LD7);
	else if(ugol > -157.5 && ugol <= -112.5)
		turnOnLed(LD9);
}

void displayLevel(short ax, short ay)
{
	turnOffAllLeds();//выключаем все диоды
	if(abs(ax) < 900 && abs(ay) < 900)//если очень маленькие значения, не обращать на них внимания
		return;

	float ugol = atan2(ay, ax)*57;//перевели в градусы

	if(ugol > -22.5 && ugol <= 22.5)
	{
		turnOnLed(LD6);
		turnOnLed(LD7);
	}
	else if(ugol > 22.5 && ugol <= 67.5)
	{
		turnOnLed(LD5);
		turnOnLed(LD8);
	}
	else if(ugol > 67.5 && ugol <= 112.5)
	{
		turnOnLed(LD3);
		turnOnLed(LD10);
	}
	else if(ugol > 112.5 && ugol <= 157.5)
	{
		turnOnLed(LD9);
		turnOnLed(LD4);
	}
	else if(ugol > 157.5 || ugol <= -157.5)
	{
		turnOnLed(LD6);
		turnOnLed(LD7);
	}
	else if(ugol > -67.5 && ugol <= -22.5)
	{
		turnOnLed(LD9);
		turnOnLed(LD4);
	}
	else if(ugol > -112.5 && ugol <= -67.5)
	{
		turnOnLed(LD3);
		turnOnLed(LD10);
	}
	else if(ugol > -157.5 && ugol <= -112.5)
	{
		turnOnLed(LD5);
		turnOnLed(LD8);
	}
}
