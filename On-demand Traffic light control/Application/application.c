/*
 * application.c
 *
 * Created: 12/10/2022 02:02:55
 *  Author: Muhammed
 */ 
#include "application.h"

uint8_t carLED         = GREEN ;      // Car led variable initiazlized with Green
uint8_t previousCarLED = YELLOW;      // Previous Cars led variable initialized with Yellow
uint8_t mode           = NORMAL;      //Start the program in Normal mode
uint8_t i;                            //variable to be used in for loops

void APP_init(void)
{
	//1. LED Initialization
	LED_init(LED_CAR_PORT,LED_CAR_G_PIN);
	LED_init(LED_CAR_PORT,LED_CAR_Y_PIN);
	LED_init(LED_CAR_PORT,LED_CAR_R_PIN);
	
	LED_init(LED_PED_PORT,LED_PED_G_PIN);
	LED_init(LED_PED_PORT,LED_PED_Y_PIN);
	LED_init(LED_PED_PORT,LED_PED_R_PIN);
	
	//2. Button Initialization
	BUTTON_init(BUTTON_PORT,BUTTON_PIN);
	
	//3. Timer Initialization
	TIMER_init();
	
	//4. Interrupt Initialization
	sei();            // Global Interrupt Enable
	SET_BIT(MCUCR,0); // Rising Edge Setup
	SET_BIT(MCUCR,1);
	SET_BIT(GICR ,6); // Enable INT0

}
void bothYellowBlink(void)
{
		for(i=0;i<5;i++)
		{
			LED_on(LED_CAR_PORT,LED_CAR_Y_PIN);
			LED_on(LED_PED_PORT,LED_PED_Y_PIN);
			TIMER_delay(390);
			LED_off(LED_CAR_PORT,LED_CAR_Y_PIN);
			LED_off(LED_PED_PORT,LED_PED_Y_PIN);
			TIMER_delay(190);
			LED_on(LED_CAR_PORT,LED_CAR_Y_PIN);
			LED_on(LED_PED_PORT,LED_PED_Y_PIN);
			TIMER_delay(390);
		}
}
void APP_start(void)
{
	//1. If the mode is Normal or there's a transition
	if( mode == NORMAL || carLED == GREEN || carLED == YELLOW)
	{
		if(mode!=NORMAL)
		{
			carLED=YELLOW;
		}
		
		//Configuring Pedestrian LEDs
		LED_off(LED_PED_PORT,LED_PED_G_PIN);
		LED_off(LED_PED_PORT,LED_PED_Y_PIN);
		
		switch(carLED)
		{
			//1.Case Green Car's Led
			case GREEN:
			LED_on(LED_CAR_PORT, LED_CAR_G_PIN);   //Car's Green LED is on while other 2 LEDs are off
			LED_off(LED_CAR_PORT,LED_CAR_Y_PIN);
			LED_off(LED_CAR_PORT,LED_CAR_R_PIN);
			for(i=0;i<50;i++)
			{
				TIMER_delay(68);
				if(mode!=NORMAL)break;             //check if ISR was called
			}
			carLED         = YELLOW;
			previousCarLED = GREEN;
			break;
			
			
			//2.Case Yellow Car's Led
			case YELLOW:
			//if we're in the Pedestrian mode then we need to blink both Yellow LEDs
			if(mode!=NORMAL)
			{
				if(previousCarLED != RED)
				{
					LED_on(LED_PED_PORT,LED_PED_R_PIN);
					//blink both yellow leds
					bothYellowBlink();
				}
				previousCarLED = YELLOW;            //to go to Ped lights logic
				carLED         = RED;
				LED_on(LED_CAR_PORT,LED_CAR_R_PIN);
			}
			else
			{
				//blink car yellow led
				for(i=0;i<5;i++)
				{
					 LED_on(LED_CAR_PORT,LED_CAR_Y_PIN);
					 TIMER_delay(380);
					 LED_off(LED_CAR_PORT,LED_CAR_Y_PIN);
					 TIMER_delay(180);
					 LED_on(LED_CAR_PORT,LED_CAR_Y_PIN);
				     TIMER_delay(380);
				     if(mode!=NORMAL)               //check if ISR was called
					 {
						 previousCarLED = YELLOW;
						 break;
					 }
				}
			}
			
			LED_off(LED_CAR_PORT,LED_CAR_Y_PIN);
			LED_off(LED_PED_PORT,LED_PED_Y_PIN);
			
			//Configure variables for correct switching
			if(previousCarLED==GREEN)
			{
				carLED =     RED;
				previousCarLED = YELLOW;
			}
			else if(previousCarLED==RED)
			{
				carLED =     GREEN;
				previousCarLED = YELLOW;
			}
			break;
			
			
			//3.Case RED LED
			case RED:
			LED_off(LED_CAR_PORT,LED_CAR_G_PIN);
			LED_off(LED_CAR_PORT,LED_CAR_Y_PIN);
			LED_on(LED_CAR_PORT,LED_CAR_R_PIN);
			for(i=0;i<50;i++)
			{
				TIMER_delay(68);
				if(mode!=NORMAL)break;
			}
			previousCarLED = RED;
			carLED =     YELLOW;
			break;
			
			default:  //Error Handling
			carLED =     RED;
			previousCarLED = YELLOW;
			break;
		}
	}
	
	else //2. if the mode is Pedestrian
	{
		    //Configure PED LEDs
		    LED_on(LED_PED_PORT,LED_PED_G_PIN);
		    LED_off(LED_PED_PORT,LED_PED_Y_PIN);
		    LED_off(LED_PED_PORT,LED_PED_R_PIN);
		
		    //Configure CAR LEDs
		    LED_off(LED_CAR_PORT,LED_CAR_G_PIN);
		    LED_off(LED_CAR_PORT,LED_CAR_Y_PIN);
		    LED_on(LED_CAR_PORT,LED_CAR_R_PIN);
		    TIMER_delay(5000);//5 sec delay
		
		    //make sure car red light is off
		    LED_off(LED_CAR_PORT,LED_CAR_R_PIN);
		
		    //blink both yellow while ped green is on
            bothYellowBlink();
		
		    //Turn off yellow LEDs
		    LED_off(LED_CAR_PORT,LED_CAR_Y_PIN);
		    LED_off(LED_PED_PORT,LED_PED_Y_PIN);
		
		    //turn on PED red LED
		    LED_on(LED_PED_PORT,LED_PED_R_PIN);
		
		    //reset normalmode
		    mode = NORMAL;
		
		    //Configure carLED variables
		    carLED =     GREEN;
		    previousCarLED = YELLOW;
	}
}

ISR(EXT_INT_0)
{
	mode = PEDESTRIAN;
}