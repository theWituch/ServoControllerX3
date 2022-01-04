/*
 * FreeModbus Libary: BARE Port
 * Copyright (C) 2006 Christian Walter <wolti@sil.at>
 *
 * This library is free software; you can redistribute it and/or
 * modify it under the terms of the GNU Lesser General Public
 * License as published by the Free Software Foundation; either
 * version 2.1 of the License, or (at your option) any later version.
 *
 * This library is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
 * Lesser General Public License for more details.
 *
 * You should have received a copy of the GNU Lesser General Public
 * License along with this library; if not, write to the Free Software
 * Foundation, Inc., 51 Franklin St, Fifth Floor, Boston, MA  02110-1301  USA
 *
 * File: $Id: portserial.c,v 1.1 2006/08/22 21:35:13 wolti Exp $
 */

#include <xc.h>

#include <sys/attribs.h>

#include "system.h

/* ----------------------- Platform includes --------------------------------*/
#include "modbus/port.h

/* ----------------------- Modbus includes ----------------------------------*/
#include "modbus/include/mb.h
#include "modbus/include/mbport.h

/* ----------------------- Static functions ---------------------------------*/
static void prvvMBPortSerialUARTRxISR(void);
static void prvvMBPortSerialUARTTxReadyISR(void);

/* ----------------------- Constant variables -------------------------------*/

/* ----------------------- Static variables ---------------------------------*/

/* ----------------------- Function implementation --------------------------*/

/* If xRXEnable enable serial receive interrupts. If xTxENable enable
 * transmitter empty interrupts. */
void
vMBPortSerialEnable(BOOL xRxEnable, BOOL xTxEnable)
{
    if (xRxEnable == TRUE)
    {
        IEC2SET = _IEC2_U4RXIE_MASK;
    } else
    {
        IEC2CLR = _IEC2_U4RXIE_MASK;
    }

    if (xTxEnable == TRUE)
    {
        IEC2SET = _IEC2_U4TXIE_MASK;
        IFS2SET = _IFS2_U4TXIF_MASK;
    } else
    {
        IEC2CLR = _IEC2_U4TXIE_MASK;
    }
}

BOOL
xMBPortSerialInit(UCHAR ucPORT, ULONG ulBaudRate, UCHAR ucDataBits, eMBParity eParity, eMBStopBits eStopBits)
{
    // Peripheral Pin Select
    TRISCbits.TRISC9 = 1; // Set port C9 as an input
    U4RXRbits.U4RXR = 0b0101; // RX to RC9

    TRISDbits.TRISD6 = 0; // Set port D6 as an output
    RPD6Rbits.RPD6R = 0b00010; // RD6 to TX

    // Baud rate = PBCLKx/16/BAUD_RATE-1
    U4BRG = PBCLK3 / 16 / ulBaudRate - 1;

    U4MODESET = 0x0000;
    U4STASET = 0x0000;

    U4STAbits.UTXSEL = 2;

    /* Parity mode */
    switch (eParity)
    {
        case MB_PAR_NONE:
            U4MODEbits.PDSEL = 0x0; // 8-bit data, no parity
            break;
        case MB_PAR_EVEN:
            U4MODEbits.PDSEL = 0x1; // 8-bit data, even parity
            break;
        case MB_PAR_ODD:
            U4MODEbits.PDSEL = 0x2; // 8-bit data, odd parity
            break;
    }

    /* Stop bits */
    switch (eStopBits)
    {
        case MB_STOPB_ONE:
            U4MODEbits.STSEL = 0x0; // 1 Stop bit
            break;
        case MB_STOPB_TWO:
            U4MODEbits.STSEL = 0x1; // 2 Stop bits
            break;
    }

    IPC16bits.U4RXIP = 2; // UART4 interrupt priority     (1 lowest - 7 highest)
    IPC16bits.U4RXIS = 1; // UART4 interrupt subpriority  (0 lowest - 3 highest)

    IPC16bits.U4TXIP = 1; // UART4 interrupt priority     (1 lowest - 7 highest)
    IPC16bits.U4TXIS = 1; // UART4 interrupt subpriority  (0 lowest - 3 highest)

    // Start UART
    U4MODEbits.UARTEN = 1;

    // Enable RX and TX
    U4STAbits.URXEN = 1;
    U4STAbits.UTXEN = 1;

    // Wait for UART is ready
    while (U4MODEbits.ACTIVE == 0);

    return TRUE;
}

/* Put a byte in the UARTs transmit buffer. This function is called
 * by the protocol stack if pxMBFrameCBTransmitterEmpty( ) has been
 * called. */
BOOL
xMBPortSerialPutByte(int8_t ucByte)
{
    U4TXREG = ucByte;
    return TRUE;
}

/* Return the byte in the UARTs receive buffer. This function is called
 * by the protocol stack after pxMBFrameCBByteReceived( ) has been called. */
BOOL
xMBPortSerialGetByte(int8_t * pucByte)
{
    int8_t uchar = U4RXREG;
    *pucByte = uchar;
    return TRUE;
}

/* Create an interrupt handler for the receive interrupt for your target
 * processor. This function should then call pxMBFrameCBByteReceived( ). The
 * protocol stack will then call xMBPortSerialGetByte( ) to retrieve the
 * character.
 */
void
__ISR(_UART4_RX_VECTOR, IPL2AUTO)
prvvMBPortSerialUARTRxISR(void)
{
    // Clear the RX interrupt Flag
    IFS2CLR = _IFS2_U4RXIF_MASK;

    // Process ModBUS
    pxMBFrameCBByteReceived();
}

/* Create an interrupt handler for the transmit buffer empty interrupt
 * (or an equivalent) for your target processor. This function should then
 * call pxMBFrameCBTransmitterEmpty( ) which tells the protocol stack that
 * a new character can be sent. The protocol stack will then call
 * xMBPortSerialPutByte( ) to send the character.
 */
void
__ISR(_UART4_TX_VECTOR, IPL1AUTO)
prvvMBPortSerialUARTTxReadyISR(void)
{
    // Clear the TX interrupt Flag
    IFS2CLR = _IFS2_U4TXIF_MASK;

    // Process ModBUS
    pxMBFrameCBTransmitterEmpty();

    //DEBUG

}

void
__ISR(_UART4_FAULT_VECTOR, IPL3AUTO)
prvvUARTErrorISR(void)
{
    // Clear the TX interrupt Flag
    IFS2CLR = _IFS2_U4EIF_MASK;

    // Process recive error to ModBUS
}