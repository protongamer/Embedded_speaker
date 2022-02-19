/*
 * BM64_controller.cpp
 *
 * Created: 18/01/2022 19:56:32
 * Author : enzo
 * Target : Attiny841
 */ 



/*

TODO : 
-Test console
-Tester fonctions BM64 et compléter la lib BM64
*/


//At fist define CPU frequency
#define F_CPU	8000000UL

#include <avr/io.h>
#include <stdlib.h>
#include <stdio.h>
#include <util/delay.h> //might be useful as you know boy (unless you prefer use of asm("nop"); )
#include "tiny841_core.h"
#include "bm64.h"
#include "BM64_CFG_SETUP.h"


#define DAMPER_BUFFER	20 //Might not overflow 50(would be too slow...)
#if DAMPER_BUFFER > 255
#warning "Large buffer -> DAMPER_BUFFER ---> Take care of variable that use this buffer !"
#endif




//////////////////////////////////////////
//Prototypes

void goToConsole(void);


//////////////////////////////////////////




int main(void)
{
	
	char buf[50];
	
	uint8_t counter = 0;
	
	uint8_t bm64_buffer[BM64_MAX_BYTES];
	
	
	uint8_t ADC_BUFFER[DAMPER_BUFFER];
	uint16_t averageValue;
	uint8_t j;
	
	////////////////////////////////////////
	//Setup IO
	
	WriteIORegister(&DDRA, TX_IND, 0);
	WriteIORegister(&DDRA, RX_IND, 1);
	WriteIORegister(&DDRA, BUILTIN_LED, 1);
	
	//Pullup input
	WriteIORegister(&DDRB, BOOT_MODE, 1);
	WriteIORegister(&PORTB, BOOT_MODE, 1);
	
	WriteIORegister(&DDRB, TRIGGER_MUX, 1);
	
	//////////////////////////////////////////////
	//Boot up sequence
	
	//Show system waking up...
	for(uint8_t i = 0; i < 2; i++)
	{
		WriteIORegister(&PORTA, BUILTIN_LED, true);
		_delay_ms(100);
		WriteIORegister(&PORTA, BUILTIN_LED, false);
		_delay_ms(100);
	}
	
	Enable_WatchDog(SET_128K_CYCLES);
	Reset_WDT();
	USART_Init_0(BAUDRATE_VALUE); //Godlike tool is now ready (Well I hope...)
	//USART_Init_1(BAUDRATE_VALUE); //Godlike tool is now ready (Well I hope...)
	
	showResetCause(); //Read what cause a reset on system ?
	
	
	bm64_init();
	Reset_WDT();
	_delay_ms(250);
	_delay_ms(250);
	_delay_ms(250);
	bm64_pairing();
	Reset_WDT();
	_delay_ms(250);
	_delay_ms(250);
	_delay_ms(250);
	
	
	if(!checkEEPROM()) //check if our value respect the normalized values
	{
		//try to put warning sequence here !
		USART_Init_1(H9600_PRESET); //set default preset
		writeEEPROM(SERIAL_PORT_PRESET, H9600_PRESET); //write to avoid this issue (maybe remove this instruction)
	}
	else
	{
		USART_Init_1(readEEPROM(SERIAL_PORT_PRESET)); 
	}
	
	SELECT_ADC(ADC11_PIN);
	SELECT_REFERENCE_VOLTAGE(SET_VCC_REFERENCE);
	adc_init(ADC_CK_DIV128);
	
	
	
	
	for(j = 0; j < DAMPER_BUFFER; j++)
		ADC_BUFFER[j] = 0; //clear buffer first
	
	
	
	if(ReadIORegister(&PINB, BOOT_MODE) == 1)
		goToConsole();
    

	
	while (1) 
    {
		Reset_WDT(); //Monsieur l'arbitre(pour vérifier que le programme n'est pas planté ^^)
		
		WriteIORegister(&PORTA, BUILTIN_LED, counter < 127 ? 0 : 1); //blink state led
		
		
		ADC_BUFFER[0] = adc_read_8(); //fill buffer step by step
		j = DAMPER_BUFFER - 1;
		averageValue = 0; // reset value for new average value
		while(j > 0)
		{
			averageValue += ADC_BUFFER[j];
			ADC_BUFFER[j] = ADC_BUFFER[j-1];
			j--;
		}
		averageValue /= DAMPER_BUFFER; //divide might slow the loop...
		
		sprintf(buf, "EEA en Morse donne ---> . . ._\t %d  %d\r\n", averageValue, ADC_BUFFER[0]); //Gonna try a madness, like we said in french "une dinguerie"
		print(buf); //Try to call an Aware(cf. JC-VD) function
		_delay_ms(10);
		counter++;
    }
}




/////////////////////////////////////////////////////////////////
//Functions





void goToConsole(void)
{
	uint8_t userChoice;
	char ID_BUFFER[2] = {'0', '1'}; //default
	
	uint8_t cfg_buffer_1[] = { WRITE_CMD1, WRITE_CMD2, WRITE_CMD3, BLID_CMD1, BLID_CMD2, BLID_CMD3, BLID_CMD4, BLID_CMD5,
							 BLID_CMD6, BLID_CMD7, BLID_CMD8, BLID_CMD9, BLID_CMD10, BLID_CMD11, BLID_CMD12, BLID_CMD13,
							 BLID_CMD14, ID_BUFFER[0], ID_BUFFER[1] };		//19 bytes
							 
	uint8_t cfg_buffer_2[] = { WRITE_CMD1, WRITE_CMD2, WRITE_CMD3, CODEC_CMD1, CODEC_CMD2, CODEC_CMD3, CODEC_CMD4, CODEC_CMD5};		//8 bytes
		
		
	while(1)
	{
		print(CONSOLE_MESSAGE);
		userChoice = USART_Receive_1();	
		
		switch(userChoice)
		{
			case '1': //set id
			print("ID_BUFFER[0] : ");
			ID_BUFFER[0] = (char)USART_Receive_1();
			print("\nID_BUFFER[1] : ");
			ID_BUFFER[1] = (char)USART_Receive_1();
				break;
				
						
			case '2': //write cfg
			
			Reset_WDT(); 

			bm64_sendCmd(cfg_buffer_1, 19);
			for(int i = 0; i < 4; i++) 
					_delay_ms(250); //wait a bit
			
			
			Reset_WDT();
			
			bm64_sendCmd(cfg_buffer_2, 8);
			for(int i = 0; i < 4; i++)
				_delay_ms(250); //wait a bit
				
			print("done");
			
				break;
				
			
			default: //exit
				SOFT_RESET; //exit console -> reset device
				break;
		}
		
	}
}