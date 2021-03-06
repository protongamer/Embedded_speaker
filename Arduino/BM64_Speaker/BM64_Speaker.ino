/*************************************************************
	Embedded Speaker - Master EEA ESET Project
	Supposed to work on ATtiny841 (for now)
*													                              		 *
	Code written by Gordon Freeman
	Uh ? No ! Not freeman fool I am	:p
*															                               *
*															                               *
	Code written (for real) by Enzo Niro
*															                               *
*************************************************************/



#include <BM64.h>
#include "routines.h"
#include "localFunctions.h"


#define DAMPER_BUFFER  20 //Might not overflow 50(would be too slow...)
#if DAMPER_BUFFER > 255
#warning "Large buffer -> DAMPER_BUFFER ---> Take care of variable that use this buffer !"
#endif


#define THRESHOLD_TRIG    900



HBM64 bm64(&Serial, RX_IND);


char resetLog[52], buf[21];
uint8_t counter = 0;
uint16_t ADC_BUFFER[DAMPER_BUFFER];
uint16_t j;
uint16_t averageValue;


void setup()
{
  Serial1.begin(9600);
  //Serial.begin(124000);
  Reset_WDT(); //prevent watchdog reset during sequence
  showResetCause(resetLog);
  Serial1.println(resetLog);
  delay(500);

  SELECT_REFERENCE_VOLTAGE(SET_4V1_REFERENCE); //put 4.096v reference
  //set pins
  pinMode(TRIGGER_MUX, OUTPUT);
  pinMode(BUILTIN_LED, OUTPUT);
  pinMode(RX_IND, OUTPUT);
  pinMode(NSPK_PIN, INPUT_PULLUP);

  /*for (uint8_t i = 0; i < 2; i++)
    {
    digitalWrite(BUILTIN_LED, true);
    delay(100);
    digitalWrite(BUILTIN_LED, false);
    delay(100);
    }*/


  ////////////////////////////////////////////
  //Easter egg sequence
  digitalWrite(BUILTIN_LED, true);
  delay(50);
  digitalWrite(BUILTIN_LED, false);
  delay(500);

  digitalWrite(BUILTIN_LED, true);
  delay(50);
  digitalWrite(BUILTIN_LED, false);
  delay(100);
  digitalWrite(BUILTIN_LED, true);
  delay(50);
  digitalWrite(BUILTIN_LED, false);
  delay(100);
  digitalWrite(BUILTIN_LED, true);
  delay(50);
  digitalWrite(BUILTIN_LED, false);
  delay(500);

  digitalWrite(BUILTIN_LED, true);
  delay(50);
  digitalWrite(BUILTIN_LED, false);
  delay(500);

  digitalWrite(BUILTIN_LED, true);
  delay(250);
  digitalWrite(BUILTIN_LED, false);
  delay(500);
  ////////////////////////////////////////////

  Enable_WatchDog(SET_256K_CYCLES); //release the hounds (said mister burn)


  Reset_WDT(); //prevent watchdog reset during sequence
  bm64.init(BM64_PORT_SPEED, NO_CFG); //no need to configure parameters
  Reset_WDT(); //prevent watchdog reset during sequence
  bm64.pairing(); //Once ack is get, launch pairing
  delay(250);
  Reset_WDT(); //prevent watchdog reset during sequence

}



void loop()
{
  Reset_WDT(); //prevent reset you fool !
  digitalWrite(BUILTIN_LED, counter < 127 ? 0 : 1); //blink state led


  ADC_BUFFER[0] = analogRead(ANALOG_PIN); //fill buffer step by step
  j = DAMPER_BUFFER - 1;
  averageValue = 0; // reset value for new average value
  while (j > 0)
  {
    averageValue += ADC_BUFFER[j];
    ADC_BUFFER[j] = ADC_BUFFER[j - 1];
    j--;
  }
  averageValue /= DAMPER_BUFFER; //divide might slow the loop...
  //sprintf(buf, "EEA -> . . ._\t %d  %d\r\n", averageValue, ADC_BUFFER[0]);
  //Serial1.print(buf);
  counter++;
  Serial1.println(averageValue);
  if (averageValue >= THRESHOLD_TRIG) //switch to jack (with ULN2003)
  {
    digitalWrite(TRIGGER_MUX, LOW);
  }
  else
  {
    digitalWrite(TRIGGER_MUX, HIGH);
  }
  delay(10);
}
