#ifndef MEMORY_H_
#define MEMORY_H_

#include "system.h

/* ----------------------- Platform includes --------------------------------*/
#include "io/port.h
#include "pid/port.h

/* ----------------------- Modules includes ---------------------------------*/
#include "io/io.h
#include "pid/pid.h

/* ----------------------- Other includes -----------------------------------*/
#include "eeprom/eeprom.h

/* ----------------------- Type definitions ---------------------------------*/

/* ----------------------- Constant variables -------------------------------*/

/* Struct for store all memory significant data */
struct
{
    /* Discrete Inputs */
    struct
    __attribute__ ((aligned(2)))
    {
        __DIO_t         B0;
        __DIO_t         B1;
    }
    DI;

    /* Discrete Outputs */
    struct
    __attribute__ ((aligned(2)))
    {
        __DIO_t         B0;
        __DIO_t         B1;
    }
    DO;

    /* Analog Inputs */
    struct
    __attribute__ ((aligned(2)))
    {
    }
    AI;

    /* Analog Outputs */
    struct
    __attribute__ ((aligned(2)))
    {
        float32_t       fA0                     __attribute__ ((aligned(2)));
        float32_t       fA1                     __attribute__ ((aligned(2)));
        float32_t       fA2                     __attribute__ ((aligned(2)));
    }
    AO;

    /* Holding registers */
    struct
    __attribute__ ((aligned(2)))
    {
        uint16_t        ulSystemCycle           __attribute__ ((aligned(2)));
        uint16_t        ulLastPIDCycle          __attribute__ ((aligned(2)));

        STATUS_t        xSystemStatus           __attribute__ ((aligned(2)));
        REQUEST_t       xSystemRequest          __attribute__ ((aligned(2)));

        int32_t         lENCODER1               __attribute__ ((aligned(2)));
        int32_t         lENCODER2               __attribute__ ((aligned(2)));
        int32_t         lENCODER3               __attribute__ ((aligned(2)));

        int32_t         lPOS1                   __attribute__ ((aligned(2)));
        int32_t         lPOS2                   __attribute__ ((aligned(2)));
        int32_t         lPOS3                   __attribute__ ((aligned(2)));

        PID_t           xPID1                   __attribute__ ((aligned(2)));
        PID_t           xPID2                   __attribute__ ((aligned(2)));
        PID_t           xPID3                   __attribute__ ((aligned(2)));
    };
} MEMORY, *p_MEMORY = &MEMORY;


/* Struct for EEPROM data cells */
union
{
    EECell_t cells[3];
    struct
    {
        EECell_t EE_PID1Config;
        EECell_t EE_PID2Config;
        EECell_t EE_PID3Config;
    };
} EECELLS, *p_EECELLS = &EECELLS;

/* ----------------------- Static variables ---------------------------------*/

/* ----------------------- Function prototypes ------------------------------*/

#endif