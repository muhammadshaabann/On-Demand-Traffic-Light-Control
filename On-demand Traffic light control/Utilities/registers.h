/*
 * registers.h
 *
 * Created: 12/10/2022 02:13:26
 *  Author: Muhammed
 */ 


#ifndef REGISTERS_H_
#define REGISTERS_H_

#include "types.h"


/************************************************************************/
/*  DIO Registers                                                       */
/************************************************************************/

//PORTA Register
#define PORTA *((volatile uint8_t*)0x3B)
#define DDRA *((volatile uint8_t*)0x3A)
#define PINA *((volatile uint8_t*)0x39)

//PORTB Register
#define PORTB *((volatile uint8_t*)0x38)
#define DDRB *((volatile uint8_t*)0x37)
#define PINB *((volatile uint8_t*)0x36)

//PORTC Register
#define PORTC *((volatile uint8_t*)0x35)
#define DDRC *((volatile uint8_t*)0x34)
#define PINC *((volatile uint8_t*)0x33)

//PORTD Register
#define PORTD *((volatile uint8_t*)0x32)
#define DDRD *((volatile uint8_t*)0x31)
#define PIND *((volatile uint8_t*)0x30)


/************************************************************************/
/* Timer0 Registers                                                     */
/************************************************************************/

#define TCCR0 *((volatile uint8_t*)0x53)
#define TCNT0 *((volatile uint8_t*)0x52)
#define TIFR *((volatile uint8_t*)0x58)

/************************************************************************/
/* ADC Registers                                                     */
/************************************************************************/

#define ADMUX *((volatile uint8_t*)0x27)
#define ADCSRA *((volatile uint8_t*)0x26)
#define ADCH *((volatile uint8_t*)0x25)
#define ADCL *((volatile uint8_t*)0x24)

/************************************************************************/
/* Interrupts Registers                                                 */
/************************************************************************/

#define SREG (*(volatile uint8_t*)(0x5F))
#define GICR (*(volatile uint8_t*)(0x5B))
#define MCUCR (*(volatile uint8_t*)(0x55))


#endif /* REGISTERS_H_ */