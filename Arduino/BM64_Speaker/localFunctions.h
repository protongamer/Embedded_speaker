#include <Arduino.h>
#include "routines.h"


#define SELECT_REFERENCE_VOLTAGE(x) ADMUXB = x
#define Reset_WDT(void)  asm("wdr")

#define SOFT_RESET asm("jmp 0x0000") //Oh c'est vilain :')


#ifdef __cplusplus
extern "C"
{
#endif

void Enable_WatchDog(uint8_t time_preset);
void showResetCause(char *_localStr);

#ifdef __cplusplus
}
#endif
