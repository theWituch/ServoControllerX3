#include <xc.h>
#include <stdio.h>

#include <sys/attribs.h>

#include "system.h
#include "uart.h


char SERIAL_BUFFER[255];            // Global RX buffer for serial data
char *rxbuffptr;
short int SERIAL_READY;             // Serial data ready flag

// STDOUT redirect to UART4
void _mon_putc (char c)
{
    while (U4STAbits.UTXBF);
    U4TXREG = c;
}


void __ISR(_UART4_RX_VECTOR, IPL2AUTO) _UART4RXInterrupt(void)
{

    IFS2bits.U4RXIF = 0;

    while (U4STAbits.URXDA)
    {
        char character = U4RXREG & 0xFF;

        if (character == 0x0a )    // LF character
            continue;

        if (character == 0x0d )    // CR character
        {
            printf("\r\n");
            SERIAL_READY = 1;
            break;
        }

        if (rxbuffptr < (&SERIAL_BUFFER[0] + sizeof(SERIAL_BUFFER) - 1 ))
        {
            *rxbuffptr++ = character;
            *rxbuffptr = 0;
            putchar(character);
        }
    }
}


void setup_UART(void)
{
    IEC2bits.U4RXIE = 0;
    IFS2bits.U4RXIF = 0;


    // Peripheral Pin Select
    TRISCbits.TRISC9 = 1;           // Set port C9 as an input
    U4RXRbits.U4RXR = 0b0101;       // RX to RC9

    TRISDbits.TRISD6 = 0;           // Set port D6 as an output
    RPD6Rbits.RPD6R = 0b00010;      // RD6 to TX

    // Baud rate
    U4BRG = ((PBCLK3/(16*BAUD_RATE))-1);

    U4MODE = 0;

    U4STA = 0x1400;

    U4STAbits.URXISEL = 0;

    rxbuffptr = &SERIAL_BUFFER[0];
    SERIAL_BUFFER[0] = 0;
    SERIAL_READY = 0;

    IPC16bits.U4RXIP = 2;           // UART4 interrupt priority     (1 lowest - 7 highest)
    IPC16bits.U4RXIS = 1;           // UART4 interrupt subpriority  (0 lowest - 3 highest)
    IEC2bits.U4RXIE = 1;            // Enable UART4 interrupt

    // Start UART
    U4MODEbits.ON = 1;

    // Wait for UART is ready
    while (U4MODEbits.ACTIVE == 0);
}

void start_UART(void)
{
    U4MODEbits.ON = 1;
}

void stop_UART(void)
{
    U4MODEbits.ON = 0;
}

void reset_buffer_UART(void)
{
    SERIAL_READY = 0;
    SERIAL_BUFFER[0] = 0;
    rxbuffptr = &SERIAL_BUFFER[0];
}