/*
 * AlfaSim.c
 *
 * Created: 5/8/17 11:08:24 pm
 * Author : bldh
 */
# define F_CPU 1000000UL

#include <avr/io.h>
#include <util/delay.h>

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

gpio_t dash_led;

int main(void)
{
	init_core();

    dash_led = gpio_out_init(&PORTA, 0, &DDRA);
	//Store function pointers in state array

	while (1){
        gpio_set(dash_led);
        _delay_ms(1000);
        gpio_clear(dash_led);
        _delay_ms(1000);
    }
    return(0);
}

uint8_t sleep(){
	return(0);
}

uint8_t intro(){
	return(0);
}
