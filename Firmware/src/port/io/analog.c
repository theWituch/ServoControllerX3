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

inline bool
xIOPortAnalogSetupInputs(void)
{
    return false;
}

inline bool
xIOPortAnalogSetupOutputs(void)
{
    return false;
}

inline void
vIOPortAnalogInputsRead(void)
{
}

inline void
vIOPortAnalogOutputsWrite(void)
{
    set_CH1_PWM((float)MEMORY.AO.fA0);
    set_CH2_PWM((float)MEMORY.AO.fA1);
    set_CH3_PWM((float)MEMORY.AO.fA2);
}

