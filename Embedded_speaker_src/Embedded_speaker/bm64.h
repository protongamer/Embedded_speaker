/*
 * bm64.h
 *
 * Created: 13/02/2022 13:42:35
 *  Author: gordon
 */ 

#define F_CPU	8000000UL

#include "tiny841_core.h"
#include <util/delay.h>



#ifndef BM64_H_
#define BM64_H_

///////////////////////////////////////
//bm64 database
#define BM64_MAX_BYTES		16

#define BM64_START_BYTE		0xAA //each message, this is the first byte

//////////////////////////////////
//CMD1 - TOOGLE PRESS SWITCH BM64
#define BM64_CMD1_BYTE1		0x00	//Length most byte
#define BM64_CMD1_BYTE2		0x03	//Length low byte
#define BM64_CMD1_BYTE3		0x02	//OP code byte
#define BM64_CMD1_BYTE4		0x00	//value 1 (alway 0 here)
#define BM64_CMD1_BYTE5		0x51	//value 2 -> toogle press switch
#define BM64_CMD1_BYTE6		0xAA	//checksum

////////////////////////////////////
//CMD2 - TOOGLE UNPRESS SWITCH BM64
#define BM64_CMD2_BYTE1		0x00	//Length most byte
#define BM64_CMD2_BYTE2		0x03	//Length low byte
#define BM64_CMD2_BYTE3		0x02	//OP code byte
#define BM64_CMD2_BYTE4		0x00	//value 1 (alway 0 here)
#define BM64_CMD2_BYTE5		0x52	//value 2 -> toogle unpress switch
#define BM64_CMD2_BYTE6		0xA9	//checksum

////////////////////////////////
//CMD3 - FAST ENTER PAIRING MODE
#define BM64_CMD3_BYTE1		0x00	//Length most byte
#define BM64_CMD3_BYTE2		0x03	//Length low byte
#define BM64_CMD3_BYTE3		0x02	//OP code byte
#define BM64_CMD3_BYTE4		0x00	//value 1 (alway 0 here)
#define BM64_CMD3_BYTE5		0x5D	//value 2 -> toogle pairing
#define BM64_CMD3_BYTE6		0x9E	//checksum




void bm64_init(void);
void bm64_pairing(void);
//void bm64_sendCmd(uint8_t *buffer, uint8_t n);
//uint8_t bm64_status(void);
//uint8_t bm64_checksum(uint8_t *buffer, uint8_t n);


uint8_t _localStatusB_DEV;
uint8_t _bm64Buffer[BM64_MAX_BYTES];


#endif /* BM64_H_ */