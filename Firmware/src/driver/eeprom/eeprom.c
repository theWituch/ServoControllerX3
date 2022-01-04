#include <xc.h>

/* ----------------------- System includes ----------------------------------*/
#include "system.h
#include "memory.h

/* ----------------------- Platform includes --------------------------------*/
#include "eeprom/port.h

/* ----------------------- EEPROM includes ----------------------------------*/
#include "eeprom/eeprom.h

/* ----------------------- Constant variables -------------------------------*/

/* ----------------------- Static variables ---------------------------------*/
static EEAddress_t xNextEEAddress = 0;

/* Functions pointer which are initialized in eEEPROMSetup(). Depending on the
 * mode (hardware or software) the are set to the correct implementations.
 */
peEEPROMDataRead_t          peEEPROMDataRead;
peEEPROMDataWrite_t         peEEPROMDataWrite;
peEEPROMDataBlockRead_t     peEEPROMDataBlockRead;
peEEPROMDataBlockWrite_t    peEEPROMDataBlockWrite;

/* ----------------------- Function implementations -------------------------*/

eEEPROMErrorCode
eEEPROMSetup(eEEPROMMode eMode)
{
    eEEPROMErrorCode eStatus = EEPROM_ENOERR;

    switch (eMode)
    {
#if EEPROM_HARDWARE_ENABLED > 0
        case EEPROM_HARDWARE:
            peEEPROMDataRead = eEEPROMHardwareDataRead;
            peEEPROMDataWrite = eEEPROMHardwareDataWrite;
            peEEPROMDataBlockRead = eEEPROMHardwareDataBlockRead;
            peEEPROMDataBlockWrite = eEEPROMHardwareDataBlockWrite;

            eStatus = eEEPROMHardwareSetup();
            break;
#endif
#if EEPROM_SOFTWARE_ENABLED > 0
        case EEPROM_SOFTWARE:
            peEEPROMDataRead = eEEPROMSoftwareDataRead;
            peEEPROMDataWrite = eEEPROMSoftwareDataWrite;
            peEEPROMDataBlockRead = eEEPROMSoftwareDataBlockRead;
            peEEPROMDataBlockWrite = eEEPROMSoftwareDataBlockWrite;

            eStatus = eEEPROMSoftwareSetup();
            break;
#endif
        default:
            eStatus = EEPROM_NOIMPLEMENTATION;
    }

    return eStatus;
}

eEEPROMErrorCode
eEEPROMRegisterEECell(EECell_t *cell, void *block, size_t size)
{
    eEEPROMErrorCode eStatus = EEPROM_ENOERR;

    //Check if cell already registered
    if (cell->registered != 0)
    {
        return EEPROM_CELLREGISTERED;
    }

    cell->address = xNextEEAddress;
    cell->object = block;
    cell->size = size;
    cell->registered = 1;

    //Increment next available cell address
    xNextEEAddress += size;

    return eStatus;
}

eEEPROMErrorCode
eEEPROMReadEECell(EECell_t *cell)
{
    eEEPROMErrorCode eStatus = EEPROM_ENOERR;

    //Check if cell is registered
    if (cell->registered == 0)
    {
        return EEPROM_CELLNOTREGISTERED;
    }

    eStatus = peEEPROMDataBlockRead(cell->address, cell->object, cell->size);

    return eStatus;
}

eEEPROMErrorCode
eEEPROMSaveEECell(EECell_t *cell)
{
    eEEPROMErrorCode eStatus = EEPROM_ENOERR;

    //Check if cell is registered
    if (cell->registered == 0)
    {
        return EEPROM_CELLNOTREGISTERED;
    }

    eStatus = peEEPROMDataBlockWrite(cell->address, cell->object, cell->size);

    return eStatus;
}

eEEPROMErrorCode
eEEPROMReadFromEECell(EECell_t *cell, void *destination, size_t destSize)
{
    eEEPROMErrorCode eStatus = EEPROM_ENOERR;

    //Check if cell is registered
    if (cell->registered == 0)
    {
        return EEPROM_CELLNOTREGISTERED;
    }

    //Check size match
    if (destSize != cell->size)
    {
        return EEPROM_SIZEMISMATCH;
    }

    eStatus = peEEPROMDataBlockRead(cell->address, destination, cell->size);

    return eStatus;
}

eEEPROMErrorCode
eEEPROMSaveToEECell(EECell_t *cell, void *source, size_t sourceSize)
{
    eEEPROMErrorCode eStatus = EEPROM_ENOERR;

    //Check if cell is registered
    if (cell->registered == 0)
    {
        return EEPROM_CELLNOTREGISTERED;
    }

    //Check size match
    if (sourceSize != cell->size)
    {
        return EEPROM_SIZEMISMATCH;
    }

    eStatus = peEEPROMDataBlockWrite(cell->address, source, cell->size);

    return eStatus;
}

eEEPROMErrorCode
eEEPROMReadAllEECells(EECell_t *cells, size_t quantity)
{
    eEEPROMErrorCode eStatus = EEPROM_ENOERR;

    while (quantity > 0)
    {
        eStatus = eEEPROMReadEECell(cells);

        if (eStatus != EEPROM_ENOERR)
            return eStatus;

        cells++;
        quantity--;
    }

    return eStatus;
}

eEEPROMErrorCode
eEEPROMSaveAllEECells(EECell_t *cells, size_t quantity)
{
    eEEPROMErrorCode eStatus = EEPROM_ENOERR;

    while (quantity > 0)
    {
        eStatus = eEEPROMSaveEECell(cells);

        if (eStatus != EEPROM_ENOERR)
            return eStatus;

        cells++;
        quantity--;
    }

    return eStatus;
}