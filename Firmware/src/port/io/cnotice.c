#include <xc.h>

#include <sys/attribs.h>

#include <stdbool.h>

#include "system.h

/* ----------------------- Platform includes --------------------------------*/
#include "memory.h
#include "io/port.h

/* ----------------------- IO includes --------------------------------------*/
#include "io/io.h

/* ----------------------- Defines ------------------------------------------*/

static void
__ISR(_CHANGE_NOTICE_G_VECTOR, IPL1AUTO)
xIOPortDiscreteCNGInterrupt(void)
{
    /* Clear the interrupt flag */
    //IFS1bits.CNGIF = 0;
    IFS1CLR = _IFS1_CNGIF_MASK;

    /* ISR-specific processing */
    if (CNSTATGbits.CNSTATG6)
    { // CN on DI1 G6 pin
        if (!PORTGbits.RG6)
        { // RISING edge
            //RESET_FLAG = 1;
        } else
        { // FALLING edge
        }
    }

    if (CNSTATGbits.CNSTATG7 && !PORTGbits.RG7)
    { // CN on DI2 G7 pin
        if (!PORTGbits.RG6)
        { // RISING edge
        } else
        { // FALLING edge
            //throwError(10, "SERVOERROR");
        }
    }
    if (CNSTATGbits.CNSTATG8 && !PORTGbits.RG8)
    { // CN on DI3 G8 pin
        if (!PORTGbits.RG6)
        { // RISING edge
        } else
        { // FALLING edge
        }
    }
    if (CNSTATGbits.CNSTATG9 && !PORTGbits.RG9)
    { // CN on DI4 G9 pin
        if (!PORTGbits.RG6)
        { // RISING edge
        } else
        { // FALLING edge
        }
    }
}