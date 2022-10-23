/*
 * button.h
 *
 * Created: 12/10/2022 02:04:15
 *  Author: Muhammed
 */ 


#ifndef BUTTON_H_
#define BUTTON_H_

#include "../../MCAL/DIO Driver/dio.h"

//Button port and pin
#define BUTTON_PORT PORT_D
#define BUTTON_PIN  PIN2


//button state macros
#define LOW 0
#define HIGH 1

//initialize
void BUTTON_init(uint8_t buttonPort, uint8_t buttonPin);

//button read
void BUTTON_read(uint8_t buttonPort, uint8_t buttonPin,uint8_t* value);



#endif /* BUTTON_H_ */