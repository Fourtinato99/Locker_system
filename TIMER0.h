/*
 * TIMER0.h
 *
 * Created: 8/23/2022 4:23:29 PM
 *  Author: effic
 */ 


#ifndef TIMER0_H_
#define TIMER0_H_
#include "STD_MACROS.h"

#define TIMSK0_328P *((volatile uint8*) 0x6E) //timer/Counter Interrupt Mask Regist

#define TCNTR0_328P *((volatile uint8*) 0x46 )
#define TCCR0A_328P *((volatile uint8*) 0x44 )
#define TCCR0B_328P *((volatile uint8*) 0x45 )
#define OCR0A_328P *((volatile uint8*)  0x47 )
#define OCR0B_328P *((volatile uint8*)  0x48 )

#define TIMER0_INIT_NORMAL TCCR0A_328P = 0x00,\
						   TCCR0B_328P = 0x01,\
						   TIMSK0_328P = 0x01,\
						   SET_BIT(SREG,7)


void TIMER0_init_normal(void );


#endif /* TIMER0_H_ */