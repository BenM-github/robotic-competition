
#include "ISRs.h"
#include "motor_driver.h"
#include "USART.h"
#include "ADC.h"
#include <util/delay.h>


#define F_CPU 8000000UL;
/*
 * 
 */
int main() {
    
    DDRC |= (1<<PC1);
    
    sei();
    
    ISR(TIMER_CAPT_vect){
        PORTC ^= (1<<PC1);
    }
/
    
    return(0);
}

