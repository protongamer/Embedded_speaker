#include "localFunctions.h"


void Enable_WatchDog(uint8_t time_preset)
{
  MCUSR = 0; //reset status register
  WDTCSR = (1 << WDE) | time_preset; //Enable watchdog - and set preset on prescaler
}




void showResetCause(char *_localStr) //80 characters max
{
  uint8_t resetReg = MCUSR;

  sprintf(_localStr, "RESET CAUSE : %s %s %s %s\n\r", (resetReg & WDR_FLAG) == WDR_FLAG ? WDR_MESSAGE : ".", 
                                                      (resetReg & BOR_FLAG) == BOR_FLAG ? BOR_MESSAGE : ".", 
                                                      (resetReg & EXR_FLAG) == EXR_FLAG ? EXR_MESSAGE : ".", 
                                                      (resetReg & POR_FLAG) == POR_FLAG ? POR_MESSAGE : "."
                                                      );
}




