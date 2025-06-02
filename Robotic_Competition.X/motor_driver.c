#include "motor_driver.h"
//Left Motor:   cost    --> PB2_L, PD6_L
//              Reverse --> PB2_L --> PWM, PD6_H
//              Forward --> PB2_H --> PWM, PD6_L
//              Break   --> PB2_H, PD6_H

//Right Motor:  cost    --> PB1_L, PD7_L
//              Reverse --> PB1_L --> PWM, PD7_H
//              Forward --> PB1_H --> PWM, PD7_L
//              Break   --> PB1_H, PD7_H


void motor_init(void){
    TCCR1A = (1<<COM1A1)|(1<<COM1B1)|(1<<WGM10);
    TCCR1B = (1<<WGM12)|(3<<CS10);
    DDRB |= (1<<LEFT_MOTOR_PWM_PIN)|(1<<RIGHT_MOTOR_PWM_PIN);
    DDRD |= (1<<LEFT_MOTOR_PIN)|(1<<RIGHT_MOTOR_PIN);
    PORTD &=~ (1<<LEFT_MOTOR_PIN)| (1<<RIGHT_MOTOR_PIN);
    PORTB &=~(1<<LEFT_MOTOR_PWM_PIN)| (1<<RIGHT_MOTOR_PWM_PIN);
}

void velocity(uint16_t velo_l, uint16_t velo_r){
    
    velo_l *= 6;
    velo_r *= 6;
    OCR1A = velo_r;
    OCR1B = velo_l;
}

void driving_direction(char direc_l, char direc_r){
    
    if(direc_l == 'F'){
        PORTB |= (LEFT_MOTOR_PWM_PIN);
        PORTD &=~ (LEFT_MOTOR_PIN);
    } else if(direc_l == 'R'){
        PORTB |= (LEFT_MOTOR_PWM_PIN);
        PORTD |= (LEFT_MOTOR_PIN);
    } else if(direc_l == 'S'){ //how do is stop it?
        PORTB &=~ (LEFT_MOTOR_PWM_PIN);
        PORTD &=~ (LEFT_MOTOR_PIN);
    }
    
    
     if(direc_r == 'F'){
        PORTB |= (RIGHT_MOTOR_PWM_PIN);
        PORTD &=~ (RIGHT_MOTOR_PIN);
    } else if(direc_r == 'R'){
        PORTB |= (RIGHT_MOTOR_PWM_PIN);
        PORTD |= (RIGHT_MOTOR_PIN);
    } else if(direc_r == 'S'){ //how do is stop it?
        PORTB &=~(RIGHT_MOTOR_PWM_PIN);
        PORTD &=~ (RIGHT_MOTOR_PIN);
    }
}
