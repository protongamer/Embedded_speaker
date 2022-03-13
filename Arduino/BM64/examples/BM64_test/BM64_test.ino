/*	UT3 - EEA ESET 2022
 * 
 * Example how to start and play with BM64
 * 
 * Written by Enzo Niro
 */

#include <BM64.h>
#include <SoftwareSerial.h>

#define RX_IND	2

#define RX_PIN	3
#define TX_PIN	4

SoftwareSerial mySerial(RX_PIN, TX_PIN);
SBM64 bm64(&mySerial, RX_IND);
  


void setup()
{
	Serial.begin(9600);
	
	Serial.println("Hi ESET");
	
	Serial.print("Wakeup BM64...");
	
	bm64.init(124000, NO_MODE); //Mean 115200 in arduino
  
	Serial.print("Put BM64 in pairing...");

	bm64.pairing();
	
	//Add ack (here)
	  
	Serial.println("Done");
  
}



void loop()
{
	//Nothing todo here
}