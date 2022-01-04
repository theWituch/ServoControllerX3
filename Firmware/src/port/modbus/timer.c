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
 * File: $Id: porttimer.c,v 1.1 2006/08/22 21:35:13 wolti Exp $
 */

#include <xc.h>
#include <sys/attribs.h>


#include "system.h

/* ----------------------- Platform includes --------------------------------*/
#include "modbus/port.h

/* ----------------------- Modbus includes ----------------------------------*/
#include "modbus/include/mb.h
#include "modbus/include/mbport.h
#include "modbus/rtu/mbrtu.h

/* ----------------------- Defines ------------------------------------------*/
#define STOP_TIMER_IN_IDLE_MODE     0x2000
#define TIMER_SOURCE_INTERNAL       0x0000
#define TIMER_SOURCE_EXTERNAL       0x0002
#define TIMER_ON                    0x8000
#define GATED_TIME_DISABLED         0x0000
#define TIMER_16BIT_MODE            0x0000
#define TIMER_32BIT_MODE            0x0004

#define TIMER_PRESCALER_1           0x0000
#define TIMER_PRESCALER_2           0x0010
#define TIMER_PRESCALER_4           0x0020
#define TIMER_PRESCALER_8           0x0030
#define TIMER_PRESCALER_16          0x0040
#define TIMER_PRESCALER_32          0x0050
#define TIMER_PRESCALER_64          0x0060
#define TIMER_PRESCALER_256         0x0070

/* ----------------------- Start implementation -----------------------------*/

/* Inicjalizacja timera sterujacego kontrola przeplywy ramek */
BOOL
xMBPortTimersInit(USHORT usTim1Timerout50us)
{
    IPC2bits.T2IP = 5; // Timer interrupt priority     (1 lowest - 7 highest)
    IPC2bits.T2IS = 0; // Timer interrupt subpriority  (0 lowest - 3 highest)

    IFS0CLR = _IFS0_T2IF_MASK; // Clear interrupt flag

    // PR = (FREQUENCY(Hz) * TIME(s) / PRESCALER) * timeout(s)
    assert(((PBCLK2 / 20000 / 8) - 1) * usTim1Timerout50us <= 0xFFFF);
    PR2 = ((PBCLK2 / 20000 / 8) - 1) * usTim1Timerout50us;

    T2CONSET = STOP_TIMER_IN_IDLE_MODE |
            TIMER_SOURCE_INTERNAL |
            GATED_TIME_DISABLED |
            TIMER_16BIT_MODE |
            TIMER_PRESCALER_8;

    IEC0SET = _IEC0_T2IE_MASK;

    return TRUE;
}

/* Enable the timer with the timeout passed to xMBPortTimersInit( ) */
INLINE void
vMBPortTimersEnable(void)
{
    TMR2 = 0;
    T2CONSET = _T2CON_ON_MASK;
}

/* Disable any pending timers. */
INLINE void
vMBPortTimersDisable(void)
{
    T2CONCLR = _T2CON_ON_MASK;
}

/* Create an ISR which is called whenever the timer has expired. This function
 * must then call pxMBPortCBTimerExpired( ) to notify the protocol stack that
 * the timer has expired.
 */
static void __ISR(_TIMER_2_VECTOR, IPL5AUTO)
prvvTIMERExpiredISR(void)
{
    // Clear interrupt Flag
    IFS0CLR = _IFS0_T2IF_MASK;

    // Process ModBUS
    pxMBPortCBTimerExpired();
}
