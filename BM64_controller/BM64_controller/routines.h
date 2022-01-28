/*
 * routines.h
 *
 * Created: 26/01/2022 23:32:15
 *  Author: gordon
 */ 



#ifndef ROUTINES_H_
#define ROUTINES_H_






//////////////////////////////////
//Routines

//Speed in Bps(bauds), not ms you fool !
#define FIXED_SPEED_1	2400 //207
#define FIXED_SPEED_2	4800 //103
#define FIXED_SPEED_3	9600 //51
#define FIXED_SPEED_4	19200 //25
#define FIXED_SPEED_5	38400 //12
#define FIXED_SPEED_6	57600 //7
#define FIXED_SPEED_7	115200 //3

//Values calculated "a la mano" to store in EEPROM (Might print values calculated by uP)
#define H2400_PRESET	207
#define H4800_PRESET	103
#define H9600_PRESET	51
#define H19200_PRESET	25
#define H38400_PRESET	12
#define H57600_PRESET	7
#define H115200_PRESET	3

#define BM64_PORT_SPEED		FIXED_SPEED_3	//That sould be fine
#define BAUDRATE_VALUE	F_CPU / BM64_PORT_SPEED / 16 - 1 //EQUAAAATION to calculate UBRR value (for UBRRL and UBRRH registers -> datasheet p.163) -> fosc / (16*Baud_value) - 1

///////////////////////////////////



///////////////////////////////////////
//Watch Dog bit values

#define WDR_FLAG	0x08
#define BOR_FLAG	0x04
#define EXR_FLAG	0x02
#define POR_FLAG	0x01

//Watch Dog Reset Messages

#define WDR_MESSAGE "WATCH DOG RESET"
#define BOR_MESSAGE "BROWN-OUT RESET"
#define EXR_MESSAGE "EXTERTNAL RESET"
#define POR_MESSAGE "POWER-ON RESET"

//Watch Dog Presets (see datasheet p.48)

#define	SET_512_CYCLES		0
#define	SET_1K_CYCLES		(1<<WDP0)
#define	SET_2K_CYCLES		(1<<WDP1)
#define	SET_4K_CYCLES		(1<<WDP0) | (1<<WDP1)
#define	SET_8K_CYCLES		(1<<WDP2)
#define	SET_16K_CYCLES		(1<<WDP2) | (1<<WDP0)
#define	SET_32K_CYCLES		(1<<WDP2) | (1<<WDP1)
#define	SET_64K_CYCLES		(1<<WDP2) | (1<<WDP1) | (1<<WDP0)
#define	SET_128K_CYCLES		(1<<WDP3)
#define	SET_256K_CYCLES		(1<<WDP3) | (1<<WDP0)


//////////////////////////////////////


/////////////////////////////////////
//EEPROM ADDRESS

#define SERIAL_PORT_PRESET	0

/////////////////////////////////////



#endif /* INCFILE1_H_ */