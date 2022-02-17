/*
 * BM64_controller.cpp
 *
 * Created: 18/01/2022 19:56:32
 * Author : gordon
 * Target : Attiny841
 */ 



/*

TODO : 
-Tester eeprom
-Tester watchdog
-Ajouter une console (voir main TODO)
-Réfléchir à combien d'octets nous pourrons utiliser si nous utilisons l'eeprom
pour l'envoi des octets du BM64... (octets optionnels evidemment !)
-Tester fonction BM64 et compléter la lib BM64
-Ajout d'une signature (voir doc p.221)
*/


//At fist define CPU frequency
#define F_CPU	8000000UL

#include <avr/io.h>
#include <stdlib.h>
#include <stdio.h>
#include <util/delay.h> //might be useful as you know boy (unless you prefer use of asm("nop"); )
#include "tiny841_core.h"
#include "bm64.h"


#define DAMPER_BUFFER	20 //Might not overflow 50(would be too slow...
#if DAMPER_BUFFER > 255
#warning "Large buffer -> DAMPER_BUFFER ---> Take care of variable that use this buffer !"
#endif



int main(void)
{
	
	char buf[50];
	
	
	
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
	
	
	
	
    while (1) 
    {
		Reset_WDT(); //Monsieur l'arbitre(pour vérifier que le programme n'est pas planté ^^)
		
		
		
		////////////////////////////////////////////////////////////////////////
		//Main TODO
		/*
		Try to think here will be the console to setup new parameters for BM64
		that can be applied after reset(in setup mode of course)
		Otherwise, run application -> read ADC to switch on/off multiplexer gate
		*/
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
		print(buf); //Try to call an Aware function
		_delay_ms(10);
		
		
		
    }
}