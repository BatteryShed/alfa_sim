/*
 * core.c
 *
 * Created: 12/8/17 12:25:03 pm
 *  Author: bldh
 */

#include <avr/io.h>
#include "core.h"
#include "util.h"

void init_core(){
	//Chapter 10 Pg 48
	//Set bits in CLKPR to enable prescaler and set to 1/8
	set_bit(CLKPR, CLKPCE);
	set_bit(CLKPR, CLKPS1);
	set_bit(CLKPR, CLKPS0);

	//Chapter 17 Pg 133
	//Set timer prescalers to 1/256 for pwm output
	set_bit(TCCR3B, CS31);
	set_bit(TCCR4B, CS41);

	//Set FastPWM
	//Timer 3
	set_bit(TCCR3A, WGM31);
	set_bit(TCCR3B, WGM32);
	set_bit(TCCR3B, WGM33);

	//Timer 4
	set_bit(TCCR4A, WGM31);
	set_bit(TCCR4B, WGM32);
	set_bit(TCCR4B, WGM33);

	//Set TOP of timers
	ICR3 = 20000;
	ICR4 = 20000;
}
