/*
 * BM64_controller.cpp
 *
 * Created: 18/01/2022 19:56:32
 * Author : Enzo42
 * Target : Attiny2313A
 */ 

//Première approche pour controller le BM64 avec un Attiny2313A
//Possibilité d'une migration vers son successeur Attiny4313 ou Attiny841

//////////////////////////////////
//Routines

//Speed in Bps(bauds), not ms you fool !
#define FIXED_SPEED_1	2400
#define FIXED_SPEED_2	4800
#define FIXED_SPEED_3	9600
#define FIXED_SPEED_4	19200
#define FIXED_SPEED_5	38400
#define FIXED_SPEED_6	57600
#define FIXED_SPEED_7	115200



//At fist define CPU frequency
#define F_CPU	8000000UL
#define SERIAL_PORT_SPEED	FIXED_SPEED_3	//That sould be fine 

#define BAUDRATE_VALUE	F_CPU / SERIAL_PORT_SPEED / 16 - 1 //EQUAAAATION to calculate UBRR value (for UBRRL and UBRRH registers -> datasheet p.123) -> fosc / (16*Baud_value) - 1

///////////////////////////////////


#include <avr/io.h>
#include <util/delay.h> //might be useful as you know boy (unless you preffer use of asm("nop"); )


///////////////////////////////////////
//prototypes
void USART_Init( uint16_t baud );
void USART_Transmit( uint8_t data );
uint8_t USART_Receive( void );
void print(char *c);
///////////////////////////////////////







int main(void)
{


//uint8_t chr = 0;


USART_Init(BAUDRATE_VALUE); //Godlike tool is now ready (Well I hope...)
    
    while (1) 
    {
		/*USART_Transmit(0x41 + chr); //Gonna try a madness, like we said in french "une dinguerie"
		USART_Transmit(0x0D); //Gonna try a madness, like we said in french "une dinguerie"
		USART_Transmit(0x0A); //Gonna try a madness, like we said in french "une dinguerie"
		*/
		print("JC-VD C'est un mec AWARE\r\n"); //Try to call an Aware function
		_delay_ms(250);
		_delay_ms(250);
		/*chr++;
		if(chr >= 26)
			chr = 0;*/
    }
}





//////////////////////////////////////////
//Functions

void USART_Init( uint16_t baud ) //fonction d'exemple de la doc (p.126)
{
	// Set baud rate on USART registers(datasheet p.141) 
	/*
	* UBRRH [11:8] -> Possibilité de R/W
	* UBRRL [7:0] -> Possibilité de R/W
	*/
	
	UBRRH = (baud & 0xFF00) >>8; 
	UBRRL = baud & 0xFF;
	// Enable receiver and transmitter (datasheet p.139)
	UCSRB = (1<<RXEN)|(1<<TXEN);
	// Format trame : 8data, 2stop bit par défault dans la datasheet(p.140) -> à adapter en fonction du BM64
	UCSRC = (1<<USBS)|(3<<UCSZ0);
}





void print(char *c)//Try to create an Aware function
{
	//Un warning concerne la conversion de String const vers char*, ceci dit, ça fonctionne...

	int i = 0;
	
	while(c[i] != '\0')
	{
	USART_Transmit(c[i]);
	i++;	
	}	
}



void USART_Transmit( uint8_t data )
{
	// On attend que le buffer soit vide (-> UDRE : USART Data Regiter Empty  -> p.138)
	while ( !( UCSRA & (1<<UDRE)) );
	// On charge la valeur dans le registre UDR
	UDR = data;
}






uint8_t USART_Receive( void )
{
	// En attente du flag RXC (Receive Complete p.138)
	while ( !(UCSRA & (1<<RXC)) );
    //Lecture du buffer dans le registre UDR
	return UDR;
}
