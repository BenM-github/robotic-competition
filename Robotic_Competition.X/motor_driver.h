
#ifndef motor_driver_H
#define	motor_driver_H

#include <stdio.h>
#include <stdlib.h>
#include <avr/io.h>

//Left Motor:   cost    --> PB2_L, PD6_L
//              Reverse --> PB2_L --> PWM, PD6_H
//              Forward --> PB2_H --> PWM, PD6_L
//              Break   --> PB2_H, PD6_H

//Right Motor:  cost    --> PB1_L, PD7_L
//              Reverse --> PB1_L --> PWM, PD7_H
//              Forward --> PB1_H --> PWM, PD7_L
//              Break   --> PB1_H, PD7_H

#define LEFT_MOTOR_PIN PD6
#define LEFT_MOTOR_PWM_PIN PB2
#define RIGHT_MOTOR_PIN PD7
#define RIGHT_MOTOR_PWM_PIN PB1
#define GAS_50_PERCENT 0x7F
#define GAS_0_PERCENT 0x00
#define GAS_100_PERCENT 0xFF
#define GAS_25_PERCENT 0x3F
#define GAS_37_PERCENT 0x61
#define GAS_31_PERCENT 0x48


void motor_init(void);

void velocity (uint8_t velo_l, uint8_t velo_r);

void driving_direction(char direc_l, char direc_r);

#endif	/* motor_driver_H */

