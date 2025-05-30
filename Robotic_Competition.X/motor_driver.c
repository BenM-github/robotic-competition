
#include "USART.h"

void USART_init(){
    UBRRH = (unsigned char) (MYUBRR>>8);
    UBRRL = (unsigned char) MYUBRR;
    
    UCSRB = (1<<RXEN);
    
    UCSRC = (1<<URSEL)|(1<<USBS)|(3<<UCSZ0);
}

void USART_Transmit(unsigned char data){
    while(!(UCSRA&(1<<UDRE)));
    
    UDR = data;
}

unsigned char USART_Recieve(){
    
    while((UCSRA&(1<<RXC)) == 0);
    
   
    return UDR;
}