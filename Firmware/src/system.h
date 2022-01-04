#ifndef SYSTEM_H_
#define SYSTEM_H_

#include <proc/p32mk1024mcf064.h>

//#include "memory.h


#define SOFT_VERSION                "0.0.1

#define SYS_FREQ                    120000000L     // 120 MHz
#define FCY                         SYS_FREQ

#define PBCLK1                      FCY/2
#define PBCLK2                      FCY/2
#define PBCLK3                      FCY/2
#define PBCLK4                      FCY/2
#define PBCLK5                      FCY/2
#define PBCLK6                      FCY/4
#define PBCLK7                      FCY/1

#define LOG_LEVEL_NONE      0
#define LOG_LEVEL_INFO      1
#define LOG_LEVEL_WARNING   2
#define LOG_LEVEL_ERROR     3
#define LOG_LEVEL_DEBUG     4

//int LOG_LEVEL = LOG_LEVEL_DEBUG;

#define info(args ...)      if (SYS_CONFIG.LOG_LEVEL >= 1) printf(args)
#define warning(args ...)   if (SYS_CONFIG.LOG_LEVEL >= 2) printf(args)
#define error(args ...)     if (SYS_CONFIG.LOG_LEVEL >= 3) printf(args)
//#define debug(args ...)     if (SYS_CONFIG.LOG_LEVEL >= 4) printf(args)

/* Calculates number of elements of the array */
#define sizeofa(a)                  sizeof(a)/sizeof(a[0])


/*
 * must parenthesize (X) in order to preserve value if the result is
 * bit shifted
 */
#define BIN_TO_ASCIIHEX(X)    (((X & 0x0F) < 10) ? ((X & 0x0F) + '0') : \
                    ((X & 0x0F) - 10 +  'A'))

typedef struct
{
    __uint8_t LOG_LEVEL;
} SystemConfig_t;

typedef union __attribute__ ((packed, aligned(4))) {
    __uint16_t WORD;
    struct
    {
        __uint16_t LIFEBIT:1;
    };
} STATUS_t;

typedef union __attribute__ ((packed, aligned(4))) {
    __uint16_t WORD;
    struct
    {
        __uint16_t READ:1;
        __uint16_t SAVE:1;
    };
} REQUEST_t;


#define    INLINE                      inline
#define PR_BEGIN_EXTERN_C           extern "C" {
#define    PR_END_EXTERN_C             }




// MEMORY map to outputs and inputs
#define DIGITAL_INPUT1      MEMORY.DI.B0.X0
#define DIGITAL_INPUT2      MEMORY.DI.B0.X1
#define DIGITAL_INPUT3      MEMORY.DI.B0.X2
#define DIGITAL_INPUT4      MEMORY.DI.B0.X3

#define RELAY_OUTPUT1       MEMORY.DO.B0.X0

#define DIGITAL_OUTPUT1     MEMORY.DO.B0.X1
#define DIGITAL_OUTPUT2     MEMORY.DO.B0.X2
#define DIGITAL_OUTPUT3     MEMORY.DO.B0.X3
#define DIGITAL_OUTPUT4     MEMORY.DO.B0.X4

#define ANALOG_OUTPUT1      MEMORY.AO.fA0
#define ANALOG_OUTPUT2      MEMORY.AO.fA1
#define ANALOG_OUTPUT3      MEMORY.AO.fA2

#define LED_READY           MEMORY.DO.B0.X5
#define LED_STATE           MEMORY.DO.B0.X6
#define LED_ERROR           MEMORY.DO.B0.X7





#define ASMNAME(x) ASMNAME_(__USER_LABEL_PREFIX__, #x)
#define ASMNAME_(x,y) ASMNAME__(x, y)
#define ASMNAME__(x,y) __asm__(#x y)


volatile unsigned short int RESET_FLAG;

inline void enableInterrupts(void);
inline void disableInterrupts(void);
void throwError(short errorcode, char message[]);

#endif

