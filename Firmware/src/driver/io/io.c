#include <xc.h>

/* ----------------------- System includes ----------------------------------*/
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#include "system.h

/* ----------------------- Platform includes --------------------------------*/
#include "io/port.h

/* ----------------------- IO includes --------------------------------------*/
#include "io/io.h

/* ----------------------- Constant variables -------------------------------*/

/* ----------------------- Static variables ---------------------------------*/

/* ----------------------- Function implementations -------------------------*/


void
eIOSetup(void)
{
    xIOPortDiscreteSetupInputs();
    xIOPortDiscreteSetupOutputs();

    xIOPortAnalogSetupInputs();
    xIOPortAnalogSetupOutputs();
}

void
eIOReadInputs(void)
{
    vIOPortDiscreteInputsRead();
    vIOPortAnalogInputsRead();
}

void
eIOWriteOutputs(void)
{
    vIOPortDiscreteOutputsWrite();
    vIOPortAnalogOutputsWrite();
}