/*
 * leds.h
 *
 *  Created on: 6 окт. 2022 г.
 *      Author: 4091
 */

#ifndef INC_LEDS_H_
#define INC_LEDS_H_

enum Leds
{
	LD3 = 9,
	LD4 = 8,
	LD5 = 10,
	LD6 = 15,
	LD7 = 11,
	LD8 = 14,
	LD9 = 12,
	LD10 = 13
};




void turnOffLed(int i);
void turnOnLed(int i);
void SwitchLed(int i);
void displayUp(short ax, short ay);
void displayLevel(short ax, short ay);
void displayDown(short ax, short ay);
void turnOffAllLeds();


#endif /* INC_LEDS_H_ */
