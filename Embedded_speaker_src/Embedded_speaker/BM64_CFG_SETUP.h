/*
 * BM64_CFG_SETUP.h
 *
 * Created: 19/02/2022 15:57:28
 *  Author: enzo
 */ 


#ifndef BM64_CFG_SETUP_H_
#define BM64_CFG_SETUP_H_


///////////////////////////////
//Main write cmd
#define WRITE_CMD1	0x01
#define WRITE_CMD2	0x27
#define WRITE_CMD3	0xFC
///////////////////////////////


///////////////////////////////
//Codec setup
#define CODEC_CMD1	0x04	//Mean 4 bytes comes after this
#define CODEC_CMD2	0x01	//Most ADDR
#define CODEC_CMD3	0xFC	//Low ADDR
#define CODEC_CMD4	0x01	//Mean 1 byte come after this
#define CODEC_CMD5	0x06	//Value -> Internal Codec -> DAC out
//////////////////////////////


///////////////////////////////
//Bluetooth ID setup
#define BLID_CMD1	0x0F	//Mean 15 bytes comes after this
#define BLID_CMD2	0x05	//Most ADDR
#define BLID_CMD3	0x00	//Low ADDR
#define BLID_CMD4	0x0C	//Mean 12 bytes comes after this
#define BLID_CMD5	0x0B	//Name length (11 bytes)
#define BLID_CMD6	0x45	//Mean "E"
#define BLID_CMD7	0x45	//Mean "E"
#define BLID_CMD8	0x41	//Mean "A"
#define BLID_CMD9	0x5F	//Mean "_"
#define BLID_CMD10	0x45	//Mean "E"
#define BLID_CMD11	0x53	//Mean "S"
#define BLID_CMD12	0x45	//Mean "E"
#define BLID_CMD13	0x54	//Mean "T"
#define BLID_CMD14	0x5F	//Mean "_"
//for BLID_CMD15 & BLID_CMD16 --> see GoToConsole() -> ID_BUFFER[2]


//////////////////////////////



#endif /* BM64_CFG_SETUP_H_ */