#ifndef SYSTEM_H_
#define SYSTEM_H_

#include <proc/p32mk1024mcf064.h>

#include "io.h

#define SOFT_VERSION                "0.0.1

#define SYS_FREQ                    100000000L     // 100 MHz
#define FCY                         SYS_FREQ
#define PBCLK3                      FCY/2


#define INPUT_ENABLE                DI1
#define INPUT_SERVOERROR            DI2
#define INPUT_RESET                 DI3

#define OUTPUT_READY                DO1
#define OUTPUT_ERROR                DO2

volatile unsigned short int RESET_FLAG;

void enableInterrupts();
void disableInterrupts();
void throwError(short errorcode, char message[]);

#endif

