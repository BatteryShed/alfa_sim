/*
 * pwm.h
 *
 * Created: 10/8/17 3:01:10 pm
 *  Author: bldh
 *  Email: brendan@bldh.tech
 */

#ifndef PWM_H_
#define PWM_H_

#define TIMER_TOP 20000
#define TIMER_MIN 1000
#define TIMER_MAX 2000

struct pwm_t{
    uint16_t* reg;
    uint16_t pulse_length;
};

void start_pwm();
pwm_t init_pwm(volatile uint16_t* reg, uint16_t start_pulse_length);
void set_pwm_value(pwm_t pwm, uint16_t pulse_length);

#endif /* PWM_H_ */
