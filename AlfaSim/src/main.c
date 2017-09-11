/*
 * AlfaSim.c
 *
 * Created: 5/8/17 11:08:24 pm
 * Author : bldh
 */ 

#include <avr/io.h>

#include "core.h"
#include "pwm.h"
#include "gpio.h"

uint8_t sleep();
uint8_t intro();

typedef enum state{
	SLEEP = 0,
	INTRO,
	OIL_PRESSURE,
	FUEL_PRESSURE,
	KEY_TURN,
	ADVANCE_RETARD,
	SET_FUEL_AIR,
	START_CAR,
	ADJUST_THROTTLE,
	RUNNING
}state_t;

state_t current_state = SLEEP;

uint8_t (*state_array[10]) ();

int main(void)
{
	uint8_t ret;
	init_core();
	
	//Store function pointers in state array
	state_array[0] = sleep;
	state_array[1] = intro;
	
	while (1){
		ret = (*state_array[current_state]) ();
		if(ret && ret+1 < 10){
			current_state += 1;
		}
		else{
			current_state = 0;
		}
	}
}

uint8_t sleep(){
	return 0;
}

uint8_t intro(){
	return 0;
}
