#include <xc.h>

#include <sys/attribs.h>

#include "system.h

void setup_IO(void)
{

     // = DIGITAL INPUTS ====================

    // DI1 on port G6
    ANSELGbits.ANSG6 = 0;                                                       // Set port G6 as digital
    TRISGbits.TRISG6 = 1;                                                       // Set port G6 as an input

    // DI2 on port G7
    ANSELGbits.ANSG7 = 0;                                                       // Set port G7 as digital
    TRISGbits.TRISG7 = 1;                                                       // Set port G7 as an input

    // DI3 on port G8
    ANSELGbits.ANSG8 = 0;                                                       // Set port G8 as digital
    TRISGbits.TRISG8 = 1;                                                       // Set port G8 as an input

    // DI4 on port G9
    ANSELGbits.ANSG9 = 0;                                                       // Set port G9 as digital
    TRISGbits.TRISG9 = 1;                                                       // Set port G9 as an input


    /* Setup CN mechanism for digital inputs */
    CNENGbits.CNIEG6 = 1;                                                       // Enable CN interrupt on RG6 pin
    CNENGbits.CNIEG7 = 1;                                                       // Enable CN interrupt on RG7 pin
    CNENGbits.CNIEG8 = 1;                                                       // Enable CN interrupt on RG8 pin
    CNENGbits.CNIEG9 = 1;                                                       // Enable CN interrupt on RG9 pin

    /* Disable CN interrupts */
    IEC1bits.CNGIE = 0;
    IFS1bits.CNGIF = 0;

    /* Set priorites for CN interrupts */
    IPC12bits.CNGIP = 3;                                                        // CN on port G interrupt priority     (1 lowest - 7 highest)
    IPC12bits.CNGIS = 0;                                                        // CN on port G interrupt subpriority  (0 lowest - 3 highest)

    /* Enable CN interrupts */
    IEC1bits.CNGIE = 1;

    /* Enable CN detecting */
    PORTG;
    CNCONGbits.ON = 1;


    // = DIGITAL OUTPUTS ====================

    // DO1 on port C8
    TRISCbits.TRISC8 = 0;                                                       //Set port C8 as an output

    // DO2 on port D5
    TRISDbits.TRISD5 = 0;                                                       //Set port D5 as an output

    // DO3 on port A12
    ANSELAbits.ANSA12 = 0;                                                       //Set port F0 as digital
    TRISAbits.TRISA12 = 0;                                                       //Set port A12 as an output

    // DO4 on port A11
    ANSELAbits.ANSA11 = 0;                                                       //Set port F0 as digital
    TRISAbits.TRISA11 = 0;                                                       //Set port A11 as an output


    // RO1 on port B11
    TRISBbits.TRISB11 = 0;                                                      //Set port B11 as an output


    // LED READY on port F0
    ANSELFbits.ANSF0 = 0;                                                       //Set port F0 as digital
    TRISFbits.TRISF0 = 0;                                                       //Set port F0 as an output
    LATFbits.LATF0 = 0;

    // LED STATE on port F1
    ANSELFbits.ANSF1 = 0;                                                       //Set port F0 as digital
    TRISFbits.TRISF1 = 0;                                                       //Set port F1 as an output
    LATFbits.LATF1 = 0;

    // LED ERROR on port B10
    TRISBbits.TRISB10 = 0;                                                      //Set port B10 as an output
    LATBbits.LATB10 = 0;

}



void __ISR(_CHANGE_NOTICE_G_VECTOR, IPL3AUTO) _CNGInterrupt(void)
{
    /* Clear the interrupt flag */
    IFS1bits.CNGIF = 0;

    /* ISR-specific processing */
    if (CNSTATGbits.CNSTATG6) {                                                 // CN on DI1 G6 pin
        if (!PORTGbits.RG6) {   // RISING edge
        } else {                // FALLING edge
        }
    }

    if (CNSTATGbits.CNSTATG7 && !PORTGbits.RG7) {                               // CN on DI2 G7 pin
        if (!PORTGbits.RG6) {   // RISING edge
        } else {                // FALLING edge
            throwError(10, "SERVOERROR");
        }
    }
    if (CNSTATGbits.CNSTATG8 && !PORTGbits.RG8) {                               // CN on DI3 G8 pin
        if (!PORTGbits.RG6) {   // RISING edge
            RESET_FLAG = 1;
        } else {                // FALLING edge
        }
    }
    if (CNSTATGbits.CNSTATG9 && !PORTGbits.RG9) {                               // CN on DI4 G9 pin
        if (!PORTGbits.RG6) {   // RISING edge
            RO1 = ~RO1;
            throwError(0, "Test");
        } else {                // FALLING edge
            LED_READY = ~LED_READY;
        }
    }
}