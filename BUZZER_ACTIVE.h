/*
 * BUZZER_ACTIVE.h
 *
 * Created: 8/25/2022 8:18:45 PM
 *  Author: effic
 */ 


#ifndef BUZZER_ACTIVE_H_
#define BUZZER_ACTIVE_H_
#include "STD_MACROS.h"

#define BUZZER_INIT SET_BIT(DDRC,PORTC5),\
					CLR_BIT(PORTC,PORTC5)
					
					
					
#define BUZZER_ON  SET_BIT(PORTC,PORTC5)

#define BUZZER_OFF CLR_BIT(PORTC,PORTC5)



void BUZZER_init(void);

void BUZZER_run_1(void);

void BUZZER_run_3(void);


#endif /* BUZZER_ACTIVE_H_ */