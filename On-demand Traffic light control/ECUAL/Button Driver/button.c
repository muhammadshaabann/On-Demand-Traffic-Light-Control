/*
 * button.c
 *
 * Created: 12/10/2022 02:04:05
 *  Author: Muhammed
 */ 

#include "button.h"

void BUTTON_init(uint8_t buttonPort, uint8_t buttonPin)
{
	DIO_init(buttonPort,buttonPin,IN);
}

void BUTTON_read(uint8_t buttonPort, uint8_t buttonPin,uint8_t* value)
{
	DIO_read(buttonPort,buttonPin,value);
}