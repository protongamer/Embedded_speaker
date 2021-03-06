/*
 * bm64.cpp
 *
 * Created: 13/02/2022 13:42:19
 *  Author: enzo
 */ 

#include "bm64.h"




//////////////////////////////

void bm64_init(void)
{
	
	uint8_t _localBuffer_cmd1[] = {BM64_START_BYTE, BM64_CMD1_BYTE1, BM64_CMD1_BYTE2, BM64_CMD1_BYTE3, BM64_CMD1_BYTE4, BM64_CMD1_BYTE5, BM64_CMD1_BYTE6};
	uint8_t _localBuffer_cmd2[] = {BM64_START_BYTE, BM64_CMD2_BYTE1, BM64_CMD2_BYTE2, BM64_CMD2_BYTE3, BM64_CMD2_BYTE4, BM64_CMD2_BYTE5, BM64_CMD2_BYTE6};
	
	
	////////////////////////////////////
	
	WriteIORegister(&PORTA, RX_IND, true);
	_delay_ms(250);
	_delay_ms(250);
	_delay_ms(250);
	WriteIORegister(&PORTA, RX_IND, false);
	
	///////////////////////////////////
	
	for(uint8_t i = 0; i < 20; i++) //wait 5 seconds
	{
		Reset_WDT();
		_delay_ms(250);
	}
		
		
	
	for(uint8_t i = 0; i < sizeof(_localBuffer_cmd1); i++)
	{
		USART_Transmit_0(_localBuffer_cmd1[i]);
		_delay_us(100);
	}
	for(uint8_t i = 0; i < sizeof(_localBuffer_cmd2); i++)
	{
		USART_Transmit_0(_localBuffer_cmd2[i]);
		_delay_us(100);
	}
	Reset_WDT(); //prevent timing ...
}




void bm64_pairing(void)
{
	uint8_t _localBuffer_cmd1[] = {BM64_START_BYTE, BM64_CMD3_BYTE1, BM64_CMD3_BYTE2, BM64_CMD3_BYTE3, BM64_CMD3_BYTE4, BM64_CMD3_BYTE5, BM64_CMD3_BYTE6};
	for(uint8_t i = 0; i < sizeof(_localBuffer_cmd1); i++)
	{
		USART_Transmit_0(_localBuffer_cmd1[i]);
		_delay_us(100);
	}
	
}




void bm64_sendCmd(uint8_t *buffer, uint8_t n)
{
	for(uint8_t i = 0; i < n; i++)
	{
		USART_Transmit_0(buffer[i]);
		_delay_us(100);
	}
}






int bm64_readCmd(uint8_t *buffer)
{
	uint8_t n = 0;
	while( ReadIORegister(&PINA, TX_IND) == 0 )
	{
		buffer[n] = USART_Receive_0();
		n++;
	}
	return n;
}



uint8_t bm64_checksum(uint8_t *buffer, uint8_t n)
{
	uint8_t chks = 0;
	
	for(uint8_t i = 1; i < n; i++) //skip first byte (see Audio UART doc p.7)
	{
		chks += buffer[i];
	}
	
	chks = (~chks) + 1; 
	
	return chks;
}