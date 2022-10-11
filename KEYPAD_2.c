/*
 * KEYPAD_2.c
 *
 * Created: 8/25/2022 7:47:04 PM
 *  Author: effic
 */ 

#include "KEYPAD_2.h"

uint8 characters[]={	'7' , '8' , '9' , '/'  ,
						'4' , '5' , '6' , '*'   ,
						'1' , '2' , '3' , '-'   ,
						'C' , '0' , '=' , '+'  };


void KEYPAD_init(void){
	
	KEYPAD_INIT_PINs;
	KEYPAD_PULLUP;
}

uint8_t KEYPAD_read(void){
	OUT0(0) ; OUT1(1) ;OUT2(1); OUT3(1);
	if(IN0 == 0 ) return characters[0];
	if(IN1 == 0 ) return characters[1];
	if(IN2 == 0 ) return characters[2];
	if(IN3 == 0 ) return characters[3];
	
	_delay_ms(4);
	
	OUT0(1) ; OUT1(0) ;OUT2(1); OUT3(1);
	if(IN0 == 0 ) return characters[4];
	if(IN1 == 0 ) return characters[5];
	if(IN2 == 0 ) return characters[6];
	if(IN3 == 0 ) return characters[7];
	
	_delay_ms(4);
	
	OUT0(1) ; OUT1(1) ;OUT2(0); OUT3(1);
	if(IN0 == 0 ) return characters[8];
	if(IN1 == 0 ) return characters[9];
	if(IN2 == 0 ) return characters[10];
	if(IN3 == 0 ) return characters[11];
	
	_delay_ms(4);
	
	OUT0(1) ; OUT1(1) ;OUT2(1); OUT3(0);
	if(IN0 == 0 ) return characters[12];
	if(IN1 == 0 ) return characters[13];
	if(IN2 == 0 ) return characters[14];
	if(IN3 == 0 ) return characters[15];
	
	_delay_ms(4);
	
	return 0;
}