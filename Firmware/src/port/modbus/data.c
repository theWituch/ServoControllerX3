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
 * File: $Id: portevent.c,v 1.1 2006/08/22 21:35:13 wolti Exp $
 */

#include <xc.h>

#include "memory.h

/* ----------------------- Platform includes --------------------------------*/
#include "modbus/port.h

/* ----------------------- Modbus includes ----------------------------------*/
#include "modbus/include/mb.h
#include "modbus/include/mbport.h

/* ----------------------- Defines ------------------------------------------*/
#define NREGS(x)                (sizeof(x)/2)
//#define POS(x)                  ((int)&x-(int)&MEMORY)

#define REG_INPUT_START         (0)
#define REG_INPUT_NREGS         (NREGS(MEMORY.DI))

#define REG_HOLDING_START       (0)
#define REG_HOLDING_NREGS       (NREGS(MEMORY))

/* ----------------------- Start implementation -----------------------------*/

/* Odczyt całych rejestrów wejść cyfrowych */
eMBErrorCode
eMBRegInputCB(UCHAR * pucRegBuffer, USHORT usAddress, USHORT usNRegs)
{
    eMBErrorCode eStatus = MB_ENOERR;
    int iRegIndex;
    __uint16_t *pointer;
    pointer = (__uint16_t*) (&MEMORY.DI);

    if ((usAddress >= REG_INPUT_START)
        && (usAddress + usNRegs <= REG_INPUT_START + REG_INPUT_NREGS))
    {
        iRegIndex = (int) (usAddress - REG_INPUT_START);// - 1);
        while (usNRegs > 0)
        {
            *pucRegBuffer++ =
                    (unsigned char) (*(pointer + iRegIndex) >> 8);
            *pucRegBuffer++ =
                    (unsigned char) (*(pointer + iRegIndex) & 0xFF);
            iRegIndex++;
            usNRegs--;
        }
    } else
    {
        eStatus = MB_ENOREG;
    }

    return eStatus;
}

// Odczyt pojedynczych wejść cyfrowych

eMBErrorCode
eMBRegDiscreteCB(UCHAR * pucRegBuffer, USHORT usAddress, USHORT usNDiscrete)
{
    return MB_ENOREG;
}

// Odczyt/zapis do zakresu rejestrów

eMBErrorCode
eMBRegHoldingCB(UCHAR * pucRegBuffer, USHORT usAddress, USHORT usNRegs,
                eMBRegisterMode eMode)
{
    eMBErrorCode eStatus = MB_ENOERR;
    int iRegIndex;
    __uint16_t *pointer;
    pointer = (__uint16_t*) (&MEMORY);

    if ((usAddress >= REG_HOLDING_START) &&
        (usAddress + usNRegs <= REG_HOLDING_START + REG_HOLDING_NREGS))
    {
        iRegIndex = (int) (usAddress - REG_HOLDING_START);// - 1);
        switch (eMode)
        {
                /* Pass current register values to the protocol stack. */
            case MB_REG_READ:
                while (usNRegs > 0)
                {
                    *pucRegBuffer++ =
                            (unsigned char) (*(pointer + iRegIndex) >> 8);
                    *pucRegBuffer++ =
                            (unsigned char) (*(pointer + iRegIndex) & 0xFF);
                    iRegIndex++;
                    usNRegs--;
                }
                break;

                /* Update current register values with new values from the
                 * protocol stack. */
            case MB_REG_WRITE:
                while (usNRegs > 0)
                {
                    *(pointer + iRegIndex) = *pucRegBuffer++ << 8;
                    *(pointer + iRegIndex) |= *pucRegBuffer++;
                    iRegIndex++;
                    usNRegs--;
                }
        }
    } else
    {
        eStatus = MB_ENOREG;
    }
    return eStatus;
}

// Odczyt/zapis do wybranych rejestrów

eMBErrorCode
eMBRegSelectedHoldingCB(UCHAR * pucRegBuffer, USHORT * usAddresses, USHORT usNRegs,
                        eMBRegisterMode eMode)
{
    eMBErrorCode eStatus = MB_ENOERR;
    int iRegIndex, iAddressIndex;
    __uint16_t *pointer;

    pointer = (__uint16_t*) (&MEMORY);
    iAddressIndex = 0;

    while (usNRegs > 0)
    {
        USHORT usAddress = usAddresses[iAddressIndex] >> 8 |  usAddresses[iAddressIndex] << 8;
        iRegIndex = (int) (usAddress - REG_HOLDING_START);// - 1);

        if ((iRegIndex >= REG_HOLDING_START) &&
            (iRegIndex <= REG_HOLDING_START + REG_HOLDING_NREGS))
        {
            switch (eMode)
            {
                    /* Pass current register values to the protocol stack. */
                case MB_REG_READ:
                    *pucRegBuffer++ =
                            (unsigned char) (*(pointer + iRegIndex) >> 8);
                    *pucRegBuffer++ =
                            (unsigned char) (*(pointer + iRegIndex) & 0xFF);
                    break;

                    /* Update current register values with new values from the
                     * protocol stack. */
                case MB_REG_WRITE:
                    *(pointer + iRegIndex) = *pucRegBuffer++ << 8;
                    *(pointer + iRegIndex) |= *pucRegBuffer++;
            }

        } else
        {
            eStatus = MB_ENOREG;
            break;
        }

        iAddressIndex++;
        usNRegs--;
    }

    return eStatus;
}

// Odczyt/zapis do wyjśc cyfrowych

eMBErrorCode
eMBRegCoilsCB(UCHAR * pucRegBuffer, USHORT usAddress, USHORT usNCoils,
              eMBRegisterMode eMode)
{
    return MB_ENOREG;
}