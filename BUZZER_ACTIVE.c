/*
 * BUZZER_ACTIVE.c
 *
 * Created: 8/25/2022 8:19:04 PM
 *  Author: effic
 */ 
#include "BUZZER_ACTIVE.h"


void BUZZER_init(void){
	BUZZER_INIT ;
}

void BUZZER_run_1(void){
	BUZZER_ON;
	_delay_ms(100);
	BUZZER_OFF;
}

void BUZZER_run_3(void){
	BUZZER_ON;
	_delay_ms(3000);
	BUZZER_OFF;
}