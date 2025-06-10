#include "ADC.h"

void ADC_init(){
    ADMUX = (1<<REFS0)|(1<<ADLAR)|3;
    ADCSRA = (1<<ADEN)|(1<<ADSC)|(1<<ADFR)|(1<<ADIE)5;
   
}

