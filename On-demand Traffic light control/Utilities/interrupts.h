/*
 * interrupts.h
 *
 * Created: 12/10/2022 03:37:19
 *  Author: Muhammed
 */ 


#ifndef INTERRUPTS_H_
#define INTERRUPTS_H_

#include "bit_manipulation.h"
#include "registers.h"

//Interrupt vectors
#define EXT_INT_0 __vector_1
#define EXT_INT_1 __vector_2

//Enable interrupts
#define sei()  __asm__ __volatile__ ("sei" ::: "memory")
#define cli()  __asm__ __volatile__ ("cli" ::: "memory")


//ISR macro
#define ISR(INT_VECT) \
void INT_VECT(void) __attribute__ ((signal,used)); \
void INT_VECT(void)


#endif /* INTERRUPTS_H_ */