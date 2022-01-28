/*
 * tiny841_core.h
 *
 * Created: 26/01/2022 23:39:24
 *  Author: gordon
 */ 
#include <avr/io.h>
#include <avr/wdt.h>

#include "routines.h"

#ifndef TINY841_CORE_H_
#define TINY841_CORE_H_


///////////////////////////////////////
//prototypes

//USART 1
void USART_Init_0( uint16_t baud );
void USART_Transmit_0( uint8_t data );
uint8_t USART_Receive_0( void );

//USART 2
void USART_Init_1( uint16_t baud );
void USART_Transmit_1( uint8_t data );
uint8_t USART_Receive_1( void );
void print(const char *c);

//Watch Dog
void Enable_WatchDog(uint8_t time_preset);
void showResetCause(void);

#define Reset_WDT(void)	wdt_reset()

//EEPROM
uint8_t readEEPROM(uint8_t addr);
void writeEEPROM(uint8_t addr, uint8_t data);
uint8_t checkEEPROM(void);


///////////////////////////////////////


#endif /* TINY841_CORE_H_ */