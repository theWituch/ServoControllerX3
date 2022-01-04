#include <xc.h>

#include "system.h

void setup_QEI(void)
{
    /* Setup I/O ports for QEI */
    // QEI4 A on port E15
    ANSELEbits.ANSE15 = 0;                                                      //Set port E15 as digital
    TRISEbits.TRISE15 = 1;                                                      //Set port E15 as an input
    // QEI4 B on port A4
    ANSELAbits.ANSA4 = 0;                                                       //Set port A4 as digital
    TRISAbits.TRISA4 = 1;                                                       //Set port A4 as an input
    // QEI4 I on port A8
    ANSELAbits.ANSA8 = 0;                                                       //Set port A8 as digital
    TRISAbits.TRISA8 = 1;                                                       //Set port A8 as an input


    // QEI2 A on port C2
    ANSELCbits.ANSC2 = 0;                                                       //Set port C2 as digital
    TRISCbits.TRISC2 = 1;                                                       //Set port C2 as an input
    // QEI2 B on port C1
    ANSELCbits.ANSC1 = 0;                                                       //Set port C1 as digital
    TRISCbits.TRISC1 = 1;                                                       //Set port C1 as an input
    // QEI2 I on port B1
    ANSELBbits.ANSB1 = 0;                                                       //Set port B1 as digital
    TRISBbits.TRISB1 = 1;                                                       //Set port B1 as an input


    // QEI1 A on port A0
    ANSELAbits.ANSA0 = 0;                                                       //Set port A0 as digital
    TRISAbits.TRISA0 = 1;                                                       //Set port A0 as an input
    // QEI1 B on port A1
    ANSELAbits.ANSA1 = 0;                                                       //Set port A1 as digital
    TRISAbits.TRISA1 = 1;                                                       //Set port A1 as an input
    // QEI1 I on port B2
    ANSELBbits.ANSB2 = 0;                                                       //Set port B2 as digital
    TRISBbits.TRISB2 = 1;                                                       //Set port B2 as an input


    /* Peripherial pin select for QEI */
    // Encoder 1
    QEA4R = 0b1000;  // RPE15
    QEB4R = 0b0010;  // RPA4
    INDX4R = 0b0101; // RPA8

    // Encoder 2
    QEA2R = 0b0110;  // RPC2
    QEB2R = 0b0110;  // RPC1
    INDX2R = 0b0010; // RPB1

    // Encoder 3
    QEA1R = 0b0000;  // RPA0
    QEB1R = 0b0000;  // RPA1
    INDX1R = 0b0100; // RPB2


    QEI4CON =  QEI2CON =  QEI1CON = 0x0;    // Disable QEI Module

    POS4CNT = POS2CNT = POS1CNT = 0;        // Reset position counter

    QEI4IOCbits.FLTREN = 1;                 // Enable filters
    QEI2IOCbits.FLTREN = 1;                 // Enable filters
    QEI1IOCbits.FLTREN = 1;                 // Enable filters

}

void start_QEI(void)
{
    QEI4CONbits.QEIEN = 1;      // Enable QEI4
    QEI2CONbits.QEIEN = 1;      // Enable QEI2
    QEI1CONbits.QEIEN = 1;      // Enable QEI1
}

void stop_QEI(void)
{
    QEI4CONbits.QEIEN = 0;      // Disable QEI4
    QEI2CONbits.QEIEN = 0;      // Disable QEI2
    QEI1CONbits.QEIEN = 0;      // Disable QEI1
}