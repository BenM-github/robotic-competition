
#include "ISRs.h"

ISR(ADC){
    PORTC ^= (1<<PC1);
}
