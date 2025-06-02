
#include <stdio.h>
#include <stdlib.h>
#include "motor_driver.h"
#include "USART.h"
#include <util/delay.h>


#define F_CPU 8000000UL;
/*
 * 
 */
int main() {

    
        
    motor_init();
    
    while(1){

        for(uint16_t i = 0; i<10000; i++){
            velocity(i, i);
            driving_direction('F', 'F');
            _delay_ms(100);
            
            
        }
        
        driving_direction('S', 'S');
        velocity(0,0);
        _delay_ms(1000);
      
    
    }
    
    
    return(0);
}

