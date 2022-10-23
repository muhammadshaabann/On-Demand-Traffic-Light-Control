/*
 * dio.h
 *
 * Created: 12/10/2022 02:17:57
 *  Author: Muhammed
 */ 


#ifndef DIO_H_
#define DIO_H_

#include "../../Utilities/registers.h"
#include "../../Utilities/bit_manipulation.h"

//all internal driver typedefs
//all driver macros
#define PORT_A 'A'
#define PORT_B 'B'
#define PORT_C 'C'
#define PORT_D 'D'

#define PIN0 0
#define PIN1 1
#define PIN2 2
#define PIN3 3
#define PIN4 4
#define PIN5 5
#define PIN6 6
#define PIN7 7

#define IN 0
#define OUT 1

#define LOW 0
#define HIGH 1

//all driver functions prototypes
void DIO_init(uint8_t portNumber, uint8_t pinNumber, uint8_t direction); // initialize dio direction
void DIO_write(uint8_t portNumber, uint8_t pinNumber, uint8_t value);    // write data to dio
void DIO_toggle(uint8_t portNumber, uint8_t pinNumber);                  // toggle dio
void DIO_read(uint8_t portNumber, uint8_t pinNumber, uint8_t *value);    // read from dio

#endif /* DIO_H_ */