/*	UT3 - EEA ESET 2022 
 *
 * Example how to flash BM64 module by usign a Microcontroller
 * to write EEPROM parameters to setup various parameters like :
 * -Codec (internal -> DAC; External -> I2S)
 * -Bluetooth ID
 *
 *	Written by Enzo Niro
 */


#include <BM64.h>
#include <SoftwareSerial.h>

#define RX_IND	3

#define RX_PIN	2
#define TX_PIN	1

SoftwareSerial mySerial(RX_PIN, TX_PIN);
SBM64 bm64(&mySerial, RX_IND);




///////////////////////////////
//Main write cmd
#define WRITE_CMD1	0x01
#define WRITE_CMD2	0x27
#define WRITE_CMD3	0xFC
///////////////////////////////


///////////////////////////////
//Main read cmd
#define READ_CMD1	0x01
#define READ_CMD2	0x29
#define READ_CMD3	0xFC
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
#define BLID_CMD15	'9'
#define BLID_CMD16	'7'
  
  uint8_t cfg_buffer_1[] = { 
			   WRITE_CMD1, WRITE_CMD2, WRITE_CMD3, BLID_CMD1, BLID_CMD2, BLID_CMD3, BLID_CMD4, BLID_CMD5,
               BLID_CMD6, BLID_CMD7, BLID_CMD8, BLID_CMD9, BLID_CMD10, BLID_CMD11, BLID_CMD12, BLID_CMD13,
               BLID_CMD14, BLID_CMD15, BLID_CMD16 };    //19 bytes
               
  uint8_t cfg_buffer_2[] = { WRITE_CMD1, WRITE_CMD2, WRITE_CMD3, CODEC_CMD1, CODEC_CMD2, CODEC_CMD3, CODEC_CMD4, CODEC_CMD5};   //8 bytes
  


void setup()
{
	Serial.begin(9600);

  while(!Serial);

  Serial.println("Send a character to Start the process");

  while(!(Serial.available() > 0));

  Serial.println("Write started");
  
	bm64.init(124000, CFG_MODE); //Mean 115200 in arduino

  
	//Write process
  
	
  
  
	Serial.println("Write Bluetooth ID...");
	bm64.sendCmd(cfg_buffer_1, 19);
  
	Serial.println("Write (internal)Codec...");
	bm64.sendCmd(cfg_buffer_1, 19);
	
	
	//Add read process (here)
	
  
	Serial.println("Done");
  
}



void loop()
{
	//Nothing todo here
}