/*
 * gpio.c
 *
 * Created: 10/8/17 3:28:57 pm
 *  Author: bldh
 */

#include <avr/io.h>
#include "gpio.h"
#include "util.h"

gpio_t gpio_init(volatile uint8_t* port, uint8_t pin, uint8_t dir_port, dir_t dir, bool pullup){
	gpio_t new_gpio;

	new_gpio.port = port;
	new_gpio.pin = pin;
	new_gpio.dir = dir;

	//Write to registers to set pin DDRB and all that stuff


	return(new_gpio);
}

uint8_t gpio_read(gpio_t gpio){
	int ret = read_bit(gpio.port, gpio.pin);
	return(ret);
}

void gpio_set(gpio_t gpio){
    set_bit(*port, pin);
}
 void gpio_clear(gpio_t){
     clear_bit(*port, pin);
 }
