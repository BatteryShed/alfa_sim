/*
 * pwm.c
 *
 * Created: 18/9/17 2:18:18 pm
 *  Author: bldh
 */

#include "pwm.h"

//Enables pins for PWM, call after calling init_pwm pins
void start_pwm(){
    set_bit(TCCR3A, COM3A1);
    set_bit(TCCR4A, COM4A1);
}

//PWM expects pulse of between 1000MS and 2000MS
pwm_t init_pwm(volatile uint16_t* reg, uint16_t start_pulse_length){
    pwm_t new_pwm;

    new_pwm.reg = reg;
    new_pwm.pulse_length = start_pulse_length;

    *reg = start_pulse_length;

    return(new_pwm);
}

void set_pwm_value(pwm_t pwm, uint16_t pulse_length){
    *(pwm.reg) = pulse_length;
}
