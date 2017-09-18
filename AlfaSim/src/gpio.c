/*
 * gpio.c
 *
 * Created: 10/8/17 3:28:57 pm
 *  Author: bldh
 */

#include <stdbool.h>
#include <avr/io.h>
#include "gpio.h"
#include "util.h"

gpio_t gpio_out_init(volatile uint8_t* port, uint8_t pin, volatile uint8_t* dir_port){
	gpio_t new_gpio;

	new_gpio.port = port;
	new_gpio.pin = pin;

    //Enable pin for output
    set_bit(*dir_port, pin);

	return(new_gpio);
}

gpio_t gpio_in_init(volatile uint8_t* port, uint8_t pin, volatile uint8_t* pullup_reg, uint8_t pullup){
	gpio_t new_gpio;

	new_gpio.port = port;
	new_gpio.pin = pin;

    //Set pullup resistor
    if(pullup == true){
        set_bit(*pullup_reg, pin);
    }

    return(new_gpio);
}

uint8_t gpio_read(gpio_t gpio){
	int ret = read_bit(gpio.port, gpio.pin);
	return(ret);
}

void gpio_set(gpio_t gpio){
    set_bit(*(gpio.port), gpio.pin);
}

void gpio_clear(gpio_t gpio){
    clear_bit(*(gpio.port), gpio.pin);
}
