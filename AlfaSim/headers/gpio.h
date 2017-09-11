/*
 * gpio.h
 *
 * Created: 10/8/17 3:01:23 pm
 *  Author: bldh
 *  Email: brendan@bldh.tech
 *
 */ 

#ifndef GPIO_H_
#define GPIO_H_

typedef enum dir{
	INPUT = 0,
	OUTPUT = 1
}dir_t;
	
typedef struct gpio{
	dir_t dir;
	uint8_t* port;
	uint8_t pin;
}gpio_t;

gpio_t gpio_init(volatile uint8_t* port, uint8_t pin, uint8_t dir_port, dir_t dir);
uint8_t gpio_read(gpio_t gpio);
void gpio_set(gpio_t gpio);

#endif /* GPIO_H_ */