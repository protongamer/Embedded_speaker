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
-Ajouter ADC (Si nécessaire, on verra le comportement du multiplexeur)
-Ajouter une console (voir main TODO)
-Réfléchir à combien d'octets nous pourrons utiliser si nous utilisons l'eeprom
pour l'envoi des octets du BM64... (octets optionnels evidemment !)

*/


//At fist define CPU frequency
#define F_CPU	8000000UL

#include <avr/io.h>
#include <stdlib.h>
#include <util/delay.h> //might be useful as you know boy (unless you preffer use of asm("nop"); )
#include "tiny841_core.h"




int main(void)
{
	
	Enable_WatchDog(SET_128K_CYCLES);
	Reset_WDT();
	
	showResetCause(); //Read what cause a reset on system ?
	
	
	USART_Init_0(BAUDRATE_VALUE); //Godlike tool is now ready (Well I hope...)
	
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
	

	
    while (1) 
    {
		
		////////////////////////////////////////////////////////////////////////
		//Main TODO
		/*
		Try to think here will be the console to setup new parameters for BM64
		that can be applied after reset(in setup mode of course)
		Otherwise, run application -> read ADC to switch on/off multiplexer gate
		*/
		
		
		/*USART_Transmit(0x41 + chr); //Gonna try a madness, like we said in french "une dinguerie"
		USART_Transmit(0x0D); //Gonna try a madness, like we said in french "une dinguerie"
		USART_Transmit(0x0A); //Gonna try a madness, like we said in french "une dinguerie"
		*/
		
		print("EEA en Morse donne ---> . . ._\r\n"); //Try to call an Aware function
		USART_Transmit_0(0x42);
		//USART_Transmit_1(0x41);
		while(1); //Pas bien mon brave
		
		Reset_WDT(); //Monsieur l'arbitre(pour vérifier que le programme n'est pas planté ^^)
    }
}











