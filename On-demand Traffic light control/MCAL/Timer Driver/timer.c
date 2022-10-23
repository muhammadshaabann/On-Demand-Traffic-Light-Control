/*
 * timer.c
 *
 * Created: 12/10/2022 02:14:31
 *  Author: Muhammed
 */ 

#include "timer.h"
#include <math.h>
#include "../../Utilities/bit_manipulation.h"

void TIMER_init()
{
	TCCR0 = 0x00; //normal mode
}
void TIMER_delay(uint16_t millisec)
{
	uint16_t No_Of_Overflows, Timer_initialValue;
	double Timer_maxdelay, Timer_tick;
	uint32_t overflowcounter=0;
	
	/*max delay 256 micro second at 1MHz, 256 prescaler */
	
	Timer_tick = 256.0/1000.0; //ms    Timer_tick     = Presc/FCPU
	Timer_maxdelay= 65.536;    //ms	   Timer_maxdelay = Ttick * 2^8
	
	if(millisec<Timer_maxdelay)
	{
		Timer_initialValue = (Timer_maxdelay-millisec)/Timer_tick;
		No_Of_Overflows   = 1;
		
	}
	else if(millisec == (int)Timer_maxdelay)
	{
	    Timer_initialValue = 0;
		No_Of_Overflows   = 1;
	}
	else
	{
		No_Of_Overflows    = ceil((double)millisec/Timer_maxdelay);
		Timer_initialValue = (1<<8) - ((double)millisec/Timer_tick)/No_Of_Overflows;
		
	}
	
	TCNT0 = Timer_initialValue;
	SET_BIT(TCCR0,2); //set 256 prescaler
	while(overflowcounter < No_Of_Overflows)
	{
		//busy wait
		while(READ_BIT(TIFR,0)==0);
		//clear overflow flag
		SET_BIT(TIFR,0);
		//increment counter
		overflowcounter++;
	}
	//Timer stop
	TCCR0 = 0x00;
}