/*
Library to control BM64 from microchip with an Arduino 
Written by Enzo Niro
*/



#include <Arduino.h>
#include <SoftwareSerial.h>





///////////////////////////////////////
//bm64 database
#define BM64_MAX_BYTES    32

#define BM64_START_BYTE   0xAA //each message, this is the first byte

//////////////////////////////////
//CMD1 - TOOGLE PRESS SWITCH BM64
#define BM64_CMD1_BYTE1   0x00  //Length most byte
#define BM64_CMD1_BYTE2   0x03  //Length low byte
#define BM64_CMD1_BYTE3   0x02  //OP code byte
#define BM64_CMD1_BYTE4   0x00  //value 1 (alway 0 here)
#define BM64_CMD1_BYTE5   0x51  //value 2 -> toogle press switch
#define BM64_CMD1_BYTE6   0xAA  //checksum

////////////////////////////////////
//CMD2 - TOOGLE UNPRESS SWITCH BM64
#define BM64_CMD2_BYTE1   0x00  //Length most byte
#define BM64_CMD2_BYTE2   0x03  //Length low byte
#define BM64_CMD2_BYTE3   0x02  //OP code byte
#define BM64_CMD2_BYTE4   0x00  //value 1 (alway 0 here)
#define BM64_CMD2_BYTE5   0x52  //value 2 -> toogle unpress switch
#define BM64_CMD2_BYTE6   0xA9  //checksum

////////////////////////////////
//CMD3 - FAST ENTER PAIRING MODE
#define BM64_CMD3_BYTE1   0x00  //Length most byte
#define BM64_CMD3_BYTE2   0x03  //Length low byte
#define BM64_CMD3_BYTE3   0x02  //OP code byte
#define BM64_CMD3_BYTE4   0x00  //value 1 (alway 0 here)
#define BM64_CMD3_BYTE5   0x5D  //value 2 -> toogle pairing
#define BM64_CMD3_BYTE6   0x9E  //checksum


////////////////////////////////////////////
//Global variable for memory reasons
//BM64 power on commands
const uint8_t _bm64_cmd_btn_press[7] PROGMEM = {BM64_START_BYTE, BM64_CMD1_BYTE1, BM64_CMD1_BYTE2, BM64_CMD1_BYTE3, BM64_CMD1_BYTE4, BM64_CMD1_BYTE5, BM64_CMD1_BYTE6}; //press button cmd
const uint8_t _bm64_cmd_btn_unpress[7] PROGMEM = {BM64_START_BYTE, BM64_CMD2_BYTE1, BM64_CMD2_BYTE2, BM64_CMD2_BYTE3, BM64_CMD2_BYTE4, BM64_CMD2_BYTE5, BM64_CMD2_BYTE6}; //unpress button cmd
//BM64 Pairing command
const uint8_t _bm64_cmd_pairing[7] PROGMEM = {BM64_START_BYTE, BM64_CMD3_BYTE1, BM64_CMD3_BYTE2, BM64_CMD3_BYTE3, BM64_CMD3_BYTE4, BM64_CMD3_BYTE5, BM64_CMD3_BYTE6};


#define NO_CFG		false
#define CFG_MODE	true



class HBM64 {


  public:

    HBM64(HardwareSerial *S, uint8_t pin);
    
	void write(uint8_t v);
	void init(uint32_t bauds, uint8_t cfg);
	int read(void);
	void readCmd(uint8_t *buffer);
	
    void pairing(void);
    void sendCmd(uint8_t *buffer, uint8_t n);
    
    //uint8_t bm64_status(void);
    uint8_t checksum(uint8_t *buffer, uint8_t n);

	int toto(void);

  private:
	
	void flushSerial(void);
	
    HardwareSerial *_serialObj;
    uint8_t _RxiPin;
	uint8_t _serialType;
	
	
	

};



class SBM64 {


  public:

    SBM64(SoftwareSerial *S, uint8_t pin);
    
	void write(uint8_t v);
	void init(uint32_t bauds, uint8_t cfg);
	int read(void);
	void readCmd(uint8_t *buffer);
	
    void pairing(void);
    void sendCmd(uint8_t *buffer, uint8_t n);
    
    //uint8_t bm64_status(void);
    uint8_t checksum(uint8_t *buffer, uint8_t n);

	int toto(void);

  private:
  
	void flushSerial(void);

	SoftwareSerial *_serialObj;
    uint8_t _RxiPin;
	uint8_t _serialType;
	
	
	

};

