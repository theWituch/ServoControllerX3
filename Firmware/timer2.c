//---------------------------------------------------------------------
//    File:        timer2.c
//
//    Written By:    Mateusz Frydrych
//
// Purpose: routines to setup and use timer 2
//
//
//---------------------------------------------------------------------
//
// Revision History
//
// Nov 5 2005 -- first version
//----------------------------------------------------------------------
#include <xc.h>

#include <sys/attribs.h>

#include "system.h
#include "io.h


volatile unsigned short int cycle2 = 0;

void __ISR(_TIMER_2_VECTOR, IPL4AUTO) _T2Interrupt(void)
{
    /* Clear the cause of the interrupt (if required) */

    /* Clear the interrupt flag */
    IFS0bits.T2IF = 0;

    /* ISR-specific processing */

    cycle2++;
    if (cycle2 > 1000) {
        LED_STATE = ~LED_STATE;
        cycle2 = 0;
    }

}

/*********************************************************************
  Function:        void setupTMR2(void)

  PreCondition:    None.

  Input:           None.

  Output:          None.

  Side Effects:    None.

  Overview:        Initialization of timer 2 as a periodic interrupt
                   each 0.1 ms (10khz)

  Note:            None.
********************************************************************/

void setup_TMR2(void)
{
    IEC0bits.T2IE = 0;              // Disable timer interrupt
    IFS0bits.T2IF = 0;              // Clear interrupt flag

    T2CON = 0x0;                    // Stop timer and clear control register


    T2CONbits.TCKPS = 0b111;        // Timer prescaler of :256

    TMR2 = 0;                       // Clear timer register
    PR2 = (FCY/4/256/1000);          // 1 ms interrupts

    IPC2bits.T2IP = 4;              // Timer interrupt priority     (1 lowest - 7 highest)
    IPC2bits.T2IS = 0;              // Timer interrupt subpriority  (0 lowest - 3 highest)
    IEC0bits.T2IE = 1;              // Enable timer interrupt
}

void start_TMR2(void)
{
    T2CONbits.ON = 1;               // Start timer
}

void stop_TMR2(void)
{
    T2CONbits.ON = 0;               // Stop timer
}