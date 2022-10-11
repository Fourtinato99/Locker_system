/*
 * KEYPAD_2.h
 *
 * Created: 8/25/2022 7:41:54 PM
 *  Author: effic
 */ 


#ifndef KEYPAD_2_H_
#define KEYPAD_2_H_

#include "STD_MACROS.h"

#define KEYPAD_INIT_PINs DDRD |= 0x0f
#define KEYPAD_PULLUP    PORTD |= 0xff;


#define OUT0(x) (x > 0 ? SET_BIT(PORTD,0) : CLR_BIT(PORTD,0) )
#define OUT1(x) (x > 0 ? SET_BIT(PORTD,1) : CLR_BIT(PORTD,1) )
#define OUT2(x) (x > 0 ? SET_BIT(PORTD,2) : CLR_BIT(PORTD,2) )
#define OUT3(x) (x > 0 ? SET_BIT(PORTD,3) : CLR_BIT(PORTD,3) )

#define IN0 READ_BIT(PIND , 4)
#define IN1 READ_BIT(PIND , 5)
#define IN2 READ_BIT(PIND , 6)
#define IN3 READ_BIT(PIND , 7)


void KEYPAD_init(void);
uint8_t KEYPAD_read(void);




#endif /* KEYPAD_2_H_ */