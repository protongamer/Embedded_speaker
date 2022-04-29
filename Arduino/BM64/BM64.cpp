#include "BM64.h"


HBM64::HBM64(HardwareSerial *S, uint8_t pin)
{
  _serialObj = S;
  _RxiPin = pin;
}

SBM64::SBM64(SoftwareSerial *S, uint8_t pin)
{
  _serialObj = S;
  _RxiPin = pin;
}






void HBM64::pairing(void)
{
	do
	{
		for (uint8_t i = 0; i < sizeof(_bm64_cmd_pairing); i++)
		{
			_serialObj->write(pgm_read_byte(&_bm64_cmd_pairing[i]));
			delayMicroseconds(100);
		}
		delay(250);
	} while(!(_serialObj->available() > 0)) ;
	
	
	
	flushSerial();
	delay(100);
}




void HBM64::sendCmd(uint8_t *buffer, uint8_t n)
{
  for (uint8_t i = 0; i < n; i++)
  {
    _serialObj->write(buffer[i]);
    delayMicroseconds(100);
  }
}





uint8_t HBM64::checksum(uint8_t *buffer, uint8_t n)
{
  uint8_t chks = 0;

  for (uint8_t i = 1; i < n; i++) //skip first byte (see Audio UART doc p.7)
  {
    chks += buffer[i];
  }

  chks = (~chks) + 1;

  return chks;
}





void SBM64::pairing(void)
{
	while(!(_serialObj->available() > 0)) 
	{
		for (uint8_t i = 0; i < sizeof(_bm64_cmd_pairing); i++)
		{
			_serialObj->write(pgm_read_byte(&_bm64_cmd_pairing[i]));
			delayMicroseconds(100);
		}
		delay(250);
	}
	flushSerial();
	delay(100);
}




void SBM64::sendCmd(uint8_t *buffer, uint8_t n)
{
  for (uint8_t i = 0; i < n; i++)
  {
    _serialObj->write(buffer[i]);
    delayMicroseconds(100);
  }
}





uint8_t SBM64::checksum(uint8_t *buffer, uint8_t n)
{
  uint8_t chks = 0;

  for (uint8_t i = 1; i < n; i++) //skip first byte (see Audio UART doc p.7)
  {
    chks += buffer[i];
  }

  chks = (~chks) + 1;

  return chks;
}






//////////////////////////////
//Privates functions




void HBM64::init(uint32_t bauds, uint8_t cfg)
{
  _serialObj->begin(bauds); //init port
  pinMode(_RxiPin, OUTPUT);
  


  ////////////////////////////////////

  digitalWrite(_RxiPin, HIGH); //wake up module
  delay(750);
  digitalWrite(_RxiPin, LOW);

  ///////////////////////////////////

  delay(1000); //wait a bit (after a long snozze you know)

  //It is time now to launch process
  
  
  if(cfg == NO_CFG)
  {
	
	
	do
	{
		for (uint8_t i = 0; i < sizeof(_bm64_cmd_btn_press); i++)
		{
			_serialObj->write(pgm_read_byte(&_bm64_cmd_btn_press[i]));
			delayMicroseconds(100);
		}
		delay(250);
	}while(!(_serialObj->available() > 0)) ;
	
	delay(250);
	flushSerial(); //add reading bytes method
	delay(100);
	
	
	do
	{
		for (uint8_t i = 0; i < sizeof(_bm64_cmd_btn_unpress); i++)
		{
			_serialObj->write(pgm_read_byte(&_bm64_cmd_btn_unpress[i]));
			delayMicroseconds(100);
		}  
		delay(250);
	}while(!(_serialObj->available() > 0)) ;
	
	
	delay(250);
	flushSerial(); //add reading bytes method
	delay(100);
	
  }

}



void SBM64::init(uint32_t bauds, uint8_t cfg)
{
  _serialObj->begin(bauds); //init port
  pinMode(_RxiPin, OUTPUT);
  


  ////////////////////////////////////

  digitalWrite(_RxiPin, HIGH); //wake up module
  delay(750);
  digitalWrite(_RxiPin, LOW);

  ///////////////////////////////////

  delay(1000); //wait a bit (after a long snozze you know)

  //It is time now to launch process
  
  
  if(cfg == NO_CFG)
  {
	
	
	do
	{
		for (uint8_t i = 0; i < sizeof(_bm64_cmd_btn_press); i++)
		{
			_serialObj->write(pgm_read_byte(&_bm64_cmd_btn_press[i]));
			delayMicroseconds(100);
		}
		delay(250);
	}while(!(_serialObj->available() > 0)) ;
	
	delay(250);
	flushSerial(); //add reading bytes method
	delay(100);
	
	
	do
	{
		for (uint8_t i = 0; i < sizeof(_bm64_cmd_btn_unpress); i++)
		{
			_serialObj->write(pgm_read_byte(&_bm64_cmd_btn_unpress[i]));
			delayMicroseconds(100);
		}  
		delay(250);
	}while(!(_serialObj->available() > 0)) ;
	
	
	delay(250);
	flushSerial(); //add reading bytes method
	delay(100);
	
  }

}




void HBM64::write(uint8_t v)
{
  _serialObj->write(v);
}



void SBM64::write(uint8_t v)
{
  _serialObj->write(v);
}






int HBM64::read(void)
{
  return _serialObj->read();
}




int SBM64::read(void)
{
  return _serialObj->read();
}





void HBM64::readCmd(uint8_t *buffer)
{
  uint8_t n = 0;
  while ( _serialObj->available() > 0 )
  {
    buffer[n] = read();
    n++;
  }
  return n;
}






void SBM64::readCmd(uint8_t *buffer)
{
  uint8_t n = 0;
  while ( _serialObj->available() > 0 )
  {
    buffer[n] = read();
    n++;
  }
  return n;
}



////////////////////////////////////////
//method to dump serial buffer



void HBM64::flushSerial(void)
{
	while(_serialObj->available() > 0)
	{
		char dump = _serialObj->read(); 
	}
}




void SBM64::flushSerial(void)
{
	while(_serialObj->available() > 0)
	{
		char dump = _serialObj->read();
	}
}
