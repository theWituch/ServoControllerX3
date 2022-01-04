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
xIOPortDiscreteSetupInputs(void)
{
    // DI1 on port G6
    ANSELGbits.ANSG6 = DIGITAL; // Set port G6 as digital
    TRISGbits.TRISG6 = INPUT; // Set port G6 as an input

    // DI2 on port G7
    ANSELGbits.ANSG7 = DIGITAL; // Set port G7 as digital
    TRISGbits.TRISG7 = INPUT; // Set port G7 as an input

    // DI3 on port G8
    ANSELGbits.ANSG8 = DIGITAL; // Set port G8 as digital
    TRISGbits.TRISG8 = INPUT; // Set port G8 as an input

    // DI4 on port G9
    ANSELGbits.ANSG9 = DIGITAL; // Set port G9 as digital
    TRISGbits.TRISG9 = INPUT; // Set port G9 as an input

    return true;
}

inline bool
xIOPortDiscreteSetupOutputs(void)
{
    // DO1 on port C8
    IOPortDIRECTION_SET(C, 8, OUTPUT); // Set port C8 as an output

    // DO2 on port D5
    IOPortDIRECTION_SET(D, 5, OUTPUT); // Set port D5 as an output

    // DO3 on port A11
    IOPortTYPE_SET(A, 11, DIGITAL); // Set port A11 as digital
    IOPortDIRECTION_SET(A, 11, OUTPUT); // Set port A11 as an output

    // DO4 on port A12
    IOPortTYPE_SET(A, 12, DIGITAL); // Set port A12 as digital
    IOPortDIRECTION_SET(A, 12, OUTPUT); // Set port A12 as an output

    // DO5 on port B11
    IOPortDIRECTION_SET(B, 11, OUTPUT); // Set port B11 as an output

    // LED on port F0
    IOPortDIRECTION_SET(F, 0, OUTPUT); // Set port F0 as an output

    // DO5 on port F1
    IOPortDIRECTION_SET(F, 1, OUTPUT); // Set port F1 as an output

    // DO5 on port B10
    IOPortDIRECTION_SET(B, 10, OUTPUT); // Set port B10 as an output

    return true;
}

inline void
vIOPortDiscreteInputsRead(void)
{
    // DI1 on port G6
    IOPortSTATE_GET(G, 6, MEMORY.DI.B0.X0);

    // DI2 on port G7
    IOPortSTATE_GET(G, 7, MEMORY.DI.B0.X1);

    // DI3 on port G8
    IOPortSTATE_GET(G, 8, MEMORY.DI.B0.X2);

    // DI4 on port G9
    IOPortSTATE_GET(G, 9, MEMORY.DI.B0.X3);
}

inline void
vIOPortDiscreteOutputsWrite(void)
{
    // DO1 on port C8
    IOPortSTATE_SET(C, 8, DIGITAL_OUTPUT1);

    // DO2 on port D5
    IOPortSTATE_SET(D, 5, DIGITAL_OUTPUT2);

    // DO3 on port A12
    IOPortSTATE_SET(A, 12, DIGITAL_OUTPUT3);

    // DO4 on port A11
    IOPortSTATE_SET(A, 11, DIGITAL_OUTPUT4);

    // DO5 on port B11
    IOPortSTATE_SET(B, 11, RELAY_OUTPUT1);

    // LED on port F0
    IOPortSTATE_SET(F, 0, LED_READY);

    // DO5 on port F1
    IOPortSTATE_SET(F, 1, LED_STATE);

    // DO5 on port B10
    IOPortSTATE_SET(B, 10, LED_ERROR);
}

