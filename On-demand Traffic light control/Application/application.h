/*
 * application.h
 *
 * Created: 12/10/2022 02:03:06
 *  Author: Muhammed
 */ 


#ifndef APPLICATION_H_
#define APPLICATION_H_

//includes
#include "../ECUAL/LED Driver/led.h"
#include "../ECUAL/Button Driver/button.h"
#include "../MCAL/Timer Driver/timer.h"
#include "../Utilities/interrupts.h"

//functions prototypes
void APP_init(void);
void APP_start(void);

void carYellowBlink(void);
void bothYellowBlink(void);

//macros
#define NORMAL     1
#define PEDESTRIAN 0

#define GREEN      0
#define YELLOW     1
#define RED        2

#endif /* APPLICATION_H_ */