/* 
 * File:   USART.h
 * Author: Aaron Schnarr
 *
 * Created on 9. Mai 2025, 16:07
 */
#ifndef USART_H
#define	USART_H

#include <stdio.h>
#include <stdlib.h>
#include <avr/io.h>

#define FOSC 8000000
#define BAUD 2400
#define MYUBRR 207

void USART_init();

void USART_Transmit(unsigned char data);

unsigned char USART_Recieve();

#endif	/* USART_H */

