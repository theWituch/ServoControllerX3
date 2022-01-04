#include <xc.h>

#include <sys/attribs.h>

#include "system.h
#include "capture.h
#include "io.h


volatile long int POSITION_CH1;
volatile long int POSITION_CH2;
volatile long int POSITION_CH3;

void setup_CAPTURE(void)
{
    /* Reset position counter */
    POSITION_CH1 = 0;
    POSITION_CH2 = 0;
    POSITION_CH3 = 0;


    /* Setup I/O ports for CN */
    // CH1 STEP
    ANSELBbits.ANSB3 = 0;           //Set port B3 as digital
    TRISBbits.TRISB3 = 1;           //Set port B3 as an input
    // CH1 DIR
    ANSELCbits.ANSC0 = 0;           //Set port C0 as digital
    TRISCbits.TRISC0 = 1;           //Set port C0 as an input

    // CH2 STEP
    ANSELEbits.ANSE14 = 0;          //Set port E14 as digital
    TRISEbits.TRISE14 = 1;          //Set port E14 as an input
    // CH2 DIR
    TRISBbits.TRISB4 = 1;           //Set port B4 as an input

    // CH3 STEP
    ANSELBbits.ANSB0 = 0;           //Set port B0 as digital
    TRISBbits.TRISB0 = 1;           //Set port B0 as an input
    // CH3 DIR
    ANSELCbits.ANSC11 = 0;          //Set port C11 as digital
    TRISCbits.TRISC11 = 1;          //Set port C11 as an input


    /* Peripheral Pin Select */
    IC4R = 0b0001;           // IC4 to RB3  (CH1)
    IC1R = 0b1000;           // IC1 to RE14 (CH2)
    IC2R = 0b0010;           // IC2 to RB0  (CH3)


    /* Resed and disable IC modules */
    IC4CON = IC1CON = IC2CON = 0;

    /* Disable interrupts */
    IEC0bits.IC4IE = 0;
    IEC0bits.IC1IE = 0;
    IEC0bits.IC2IE = 0;

    /* Clean up any pending IF bits */
    IFS0bits.IC4IF = 0;
    IFS0bits.IC1IF = 0;
    IFS0bits.IC2IF = 0;

    /* assign Interrupt Priority to IPC Register  (4 is default)*/
    IPC5bits.IC4IP = 7;   // IC interrupt priority     (1 lowest - 7 highest)
    IPC5bits.IC4IS = 3;   // IC interrupt subpriority  (0 lowest - 3 highest)
    IPC1bits.IC1IP = 7;   // IC interrupt priority     (1 lowest - 7 highest)
    IPC1bits.IC1IS = 2;   // IC interrupt subpriority  (0 lowest - 3 highest)
    IPC2bits.IC2IP = 7;   // IC interrupt priority     (1 lowest - 7 highest)
    IPC2bits.IC2IS = 1;   // IC interrupt subpriority  (0 lowest - 3 highest)

    /* Capture Mode
     * Simple Capture Event mode ? every falling edge */
    IC4CONbits.ICM = IC1CONbits.ICM = IC2CONbits.ICM = 0b010;
    IC4CONbits.ICI = IC1CONbits.ICI = IC2CONbits.ICI = 0b01;

    /* Dummy read for mismatch state clear */
    IC4BUF;IC1BUF;IC2BUF;

    /* Enable interrupts */
    IEC0bits.IC4IE = 1;
    IEC0bits.IC1IE = 1;
    IEC0bits.IC2IE = 1;

}

void start_CAPTURE(void)
{
    IC4CONbits.ON = 1;
    IC1CONbits.ON = 1;
    IC2CONbits.ON = 1;
}

void stop_CAPTURE(void)
{
    IC4CONbits.ON = 0;
    IC1CONbits.ON = 0;
    IC2CONbits.ON = 0;
}


void __ISR(_INPUT_CAPTURE_4_VECTOR, IPL7AUTO) _IC4Interrupt(void)
{
    /* Dummy read for mismatch state clear */
    IC4BUF;

    /* Clear the interrupt flag */
    IFS0bits.IC4IF = 0;

    /* ISR-specific processing */
    if (!INPUT_ENABLE)
        return;

    if (PORTCbits.RC0)          // Step up
        POSITION_CH1 += 1;
    else                        // Step down
        POSITION_CH1 -= 1;
}

void __ISR(_INPUT_CAPTURE_1_VECTOR, IPL7AUTO) _IC1Interrupt(void)
{
    /* Dummy read for mismatch state clear */
    IC1BUF;

    /* Clear the interrupt flag */
    IFS0bits.IC1IF = 0;

    /* ISR-specific processing */
    if (!INPUT_ENABLE)
        return;

    if (PORTBbits.RB4)          // Step up
        POSITION_CH2 += 1;
    else                        // Step down
        POSITION_CH2 -= 1;
}

void __ISR(_INPUT_CAPTURE_2_VECTOR, IPL7AUTO) _IC2Interrupt(void)
{
    /* Dummy read for mismatch state clear */
    IC2BUF;

    /* Clear the interrupt flag */
    IFS0bits.IC2IF = 0;

    /* ISR-specific processing */
    if (!INPUT_ENABLE)
        return;

    if (PORTCbits.RC11)          // Step up
        POSITION_CH3 += 1;
    else                        // Step down
        POSITION_CH3 -= 1;
}