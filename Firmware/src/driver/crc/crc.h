#ifndef CRC_H_
#define CRC_H_

/* ----------------------- Defines ------------------------------------------*/

/* ----------------------- Type definitions ---------------------------------*/

typedef enum
{
    CRC16_Modbus
} eCRCType;

/* ----------------------- Constant variables -------------------------------*/

/* ----------------------- Static variables ---------------------------------*/

/* ----------------------- Function prototypes ------------------------------*/

uint32_t ulCRCCalculate(eCRCType eType, void *pulInput, size_t xLength);

#endif