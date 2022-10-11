/*
 * KEYPAD.c
 *
 * Created: 8/25/2022 5:11:09 PM
 *  Author: effic
 */ 
#include "KEYPAD.h"
#include "TIMER0.h"
#include "INTERRUPT.h"

volatile uint8 changer = 0x01;
extern uint8 ch;

uint8 characters[][4]={ {'7' , '8' , '9' , '/'  } ,
					    {'4' , '5' , '6' , '*'  } ,
					    {'1' , '2' , '3' , '-'  } ,
					    {'<' , '0' , '>' , '+'  }     };


void KEYPAD_init(void){
	
	KEYPAD_INIT_PINs;
	KEYPAD_PULLUP;
	
	// toggle ouput pins using timer normal mode 
	TIMER0_init_normal();
	
	
	
	//reading pins when any change on input pins using pin change interrupt
	INTERRUPT_PC_init(20);
	INTERRUPT_PC_init(21);
	INTERRUPT_PC_init(22);
	INTERRUPT_PC_init(23);
	
	//
	
}


ISR(TIMER0_OVF_vect){
	OUT0( (changer & 1 )) ;
	OUT1( (changer & 2 ));
	OUT2( (changer & 4 ));
	OUT3( (changer & 8 ));
	changer =  changer >= 8 ? 0x01 : changer*2 ; 
}

ISR(PCINT2_vect){
	TOG_BIT(PORTC,3);
	
	if(IN0 == 0)        ch = characters[ (uint8)(changer/2) ][0];
	else if (IN1 == 0)  ch = characters[ (uint8)(changer/2) ][1];
	else if (IN2 == 0)  ch = characters[ (uint8)(changer/2) ][2];
	else if (IN3 == 0)  ch = characters[ (uint8)(changer/2) ][3]; 
	
}
