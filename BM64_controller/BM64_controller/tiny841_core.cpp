/*
 * tiny841_core.cpp
 *
 * Created: 26/01/2022 23:31:45
 *  Author: gordon
 */ 
//////////////////////////////////////////
//Functions

//////////////////
//USART1 functions

#include "tiny841_core.h"



void USART_Init_0( uint16_t baud ) //fonction d'exemple de la doc (p.166)
{
	// Set baud rate on USART registers(datasheet p.186) 
	/*
	* UBRRH [11:8] -> Possibilité de R/W
	* UBRRL [7:0] -> Possibilité de R/W
	*/
	
	UBRR0H = (baud & 0xFF00) >>8; 
	UBRR0L = baud & 0xFF;
	// Enable receiver and transmitter (datasheet p.182)
	UCSR0B = (1<<RXEN0)|(1<<TXEN0);
	// Format trame : 8data, 2stop bit par défault dans la datasheet(p.184) -> à adapter en fonction du BM64
	UCSR0C = (1<<USBS0)|(3<<UCSZ00);
	
	
}

void USART_Transmit_0( uint8_t data )
{
	// On attend que le buffer soit vide (-> bit UDRE : USART Data Regiter Empty  -> p.181)
	while ( !( UCSR0A & (1<<UDRE0)) );
	// On charge la valeur dans le registre UDR
	UDR0 = data;
}


uint8_t USART_Receive_0( void )
{
	// En attente du flag RXC (Receive Complete p.181)
	while ( !(UCSR0A & (1<<RXC0)) );
	//Lecture du buffer dans le registre UDR
	return UDR0;
}




//////////////////
//USART2 functions





void USART_Init_1( uint16_t baud ) //fonction d'exemple de la doc (p.166)
{
	// Set baud rate on USART registers(datasheet p.186) 
	/*
	* UBRRH [11:8] -> Possibilité de R/W
	* UBRRL [7:0] -> Possibilité de R/W
	*/
	
	UBRR1H = (baud & 0xFF00) >>8; 
	UBRR1L = baud & 0xFF;
	// Enable receiver and transmitter (datasheet p.182)
	UCSR1B = (1<<RXEN1)|(1<<TXEN1);
	// Format trame : 8data, 2stop bit par défault dans la datasheet(p.184) -> à adapter en fonction du BM64
	UCSR1C = (1<<USBS1)|(3<<UCSZ10);
	
	
}

void USART_Transmit_1( uint8_t data )
{
	// On attend que le buffer soit vide (-> bit UDRE : USART Data Regiter Empty  -> p.181)
	while ( !( UCSR1A & (1<<UDRE1)) );
	// On charge la valeur dans le registre UDR
	UDR1 = data;
}


uint8_t USART_Receive_1( void )
{
	// En attente du flag RXC (Receive Complete p.181)
	while ( !(UCSR1A & (1<<RXC1)) );
	//Lecture du buffer dans le registre UDR
	return UDR1;
}







void print(const char *c)//Try to create an Aware function
{
	//Un warning concerne la conversion de String const vers char*, ceci dit, ça fonctionne...

	int i = 0;
	
	while(c[i] != '\0')
	{
	USART_Transmit_1(c[i]);
	i++;	
	}	
}



//////////////////////////
//Watch Dog Functions


void Enable_WatchDog(uint8_t time_preset)
{
	MCUSR = 0; //reset status register
	WDTCSR = (1<<WDE) | time_preset; //Enable watchdog - and set preset on prescaler
}




void showResetCause(void)
{
	uint8_t resetReg = MCUSR;
	print("MCUSR : ");
	for(uint8_t i = 0x40; i > 0; i>>=1)
	{
		switch(resetReg & i)
		{
			case WDR_FLAG:
			print(WDR_MESSAGE);
			break;
			
			case BOR_FLAG:
			print(BOR_MESSAGE);
			break;
			
			case EXR_FLAG:
			print(EXR_MESSAGE);
			break;
			
			case POR_FLAG:
			print(POR_MESSAGE);
			break;
		}
		if(resetReg & i)
		print("\n\r");
	}
}



//////////////////////////
//EEPROM Functions

uint8_t readEEPROM(uint8_t addr)
{
	// Check if there no process on eeprom
	while(EECR & (1<<EEPE));
	//Put Addess
	EEAR = addr;
	//Start read value on eeprom address -> that stored in EEDR
	EECR |= (1<<EERE);
	return EEDR; 
}




void writeEEPROM(uint8_t addr, uint8_t data)
{
	// Check if there no process on eeprom
	while(EECR & (1<<EEPE));
	//Set programming mode (Atomic mode here, operation time ~3.4ms ---> datasheet p.23)
	EECR = (0<<EEPM1)|(0<<EEPM0);
	//Put address and data
	EEAR = addr;
	EEDR = data;
	//Enable Write
	EECR |= (1<<EEMPE);
	//Write value
	EECR |= (1<<EEPE);
}




uint8_t checkEEPROM(void)
{
	uint8_t legalValues[] = {H2400_PRESET, H4800_PRESET, H9600_PRESET, H19200_PRESET, H38400_PRESET, H57600_PRESET, H115200_PRESET};
	uint8_t check = 1;
	uint8_t parameter = readEEPROM(SERIAL_PORT_PRESET);
	for(uint8_t i = 0; i < sizeof(legalValues); i++)
	{
		if(parameter != legalValues[i])
		check = 0;
		Reset_WDT(); //need this to prevent watchdog system reset (even we have speed sequence)
	}
	
	return check;
}