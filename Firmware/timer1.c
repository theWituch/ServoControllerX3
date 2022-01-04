#include <xc.h>

#include <sys/attribs.h>
#include <stdio.h>

#include "system.h
#include "io.h
#include "qei.h


// Tick flags
volatile unsigned short int TICK_SERVO, TICK_SERVOSET = 100;

volatile short int TICK_LEDREADY, TICK_LEDREADYSET = 1000;
volatile short int TICK_LEDSTATE, TICK_LEDSTATESET = 500;
volatile short int TICK_LEDERROR, TICK_LEDERRORSET = 250;


void __ISR(_TIMER_1_VECTOR, IPL1AUTO) _T1Interrupt(void)
{
    /* Clear the cause of the interrupt (if required) */

    /* Clear the interrupt flag */
    IFS0bits.T1IF = 0;

    /* ISR-specific processing */

    if (TICK_SERVO > 0) {
        --TICK_SERVO;
    }

    if (TICK_LEDREADY > 0) {
        --TICK_LEDREADY;
    }

    if (TICK_LEDSTATE > 0) {
        --TICK_LEDSTATE;
    }

    if (TICK_LEDERROR > 0) {
        --TICK_LEDERROR;
    }
}


void setup_TMR1(void)
{
    IEC0bits.T1IE = 0;              // Disable timer interrupt
    IFS0bits.T1IF = 0;              // Clear interrupt flag

    T1CON = 0x0;                    // Stop timer and clear control register

    T1CONbits.TCKPS = 0b11;         // Timer prescaler of :256

    TMR1 = 0;                       // Clear timer register
    PR1 = (FCY/2/256/1000);         // 1ms interrupts

    IPC1bits.T1IP = 1;              // Timer interrupt priority     (1 lowest - 7 highest)
    IPC1bits.T1IS = 0;              // Timer interrupt subpriority  (0 lowest - 3 highest)
    IEC0bits.T1IE = 1;              // Enable Timer1 interrupt
}

void start_TMR1(void)
{
    T1CONbits.TON = 1;               // Start timer
}

void stop_TMR1(void)
{
    T1CONbits.TON = 0;               // Stop timer
}