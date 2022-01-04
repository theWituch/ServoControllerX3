#include <xc.h>

/* ----------------------- System includes ----------------------------------*/
#include "system.h

/* ----------------------- Platform includes --------------------------------*/
#include "eeprom/port.h

/* ----------------------- EEPROM includes ----------------------------------*/
#include "eeprom/eeprom.h

/* ----------------------- Defines ------------------------------------------*/

/* EEPROM unlock keys */
#define EEKEY1 0xEDB7
#define EEKEY2 0x1248

/* EEPROM errors */
#define EEPROM_NO_ERROR                     0
#define EEPROM_BULK_ERASE_ERROR             1
#define EEPROM_PAGE_ERASE_ERROR             1
#define EEPROM_WORD_PROGRAM_VERIFY_ERROR    1
#define EEPROM_INVALID_OPERATION_ERROR      2
#define EEPROM_MISSALIGNED_ADDRESS_ERROR    2
#define EEPROM_BOR_EVENT_ERROR              3

#define EEPROM_NOT_READY_ERROR              10
#define EEPROM_COMPARE_ERROR                11
#define EEPROM_INVALID_ADDRESS_ERROR        12

/* ----------------------- Constant variables -------------------------------*/

/* ----------------------- Static variables ---------------------------------*/

/* ----------------------- Function implementations -------------------------*/

eEEPROMErrorCode
eEEPROMHardwareSetup(void)
{
    /* Disable interrupts prior to unlock sequence */
    __builtin_disable_interrupts();

    /* Configure number of Wait states */
    CFGCON2bits.EEWS = 12; // for system clocks < 125MHz

    /* Turn on the EEPROM */
    EECONbits.ON = 1;

    /* Wait until EEPROM is ready */
    while (EECONbits.RDY == 0);

    EECONbits.CMD = 0b100; // Load CMD<2:0> with write command
    EECONbits.WREN = 1; // Access for write

    /* Write configuration register 0 */
    EEADDR = 0x00; // Addr 0x00 = DEVEE0;
    EEDATA = DEVEE0;
    EEKEY = EEKEY1; // Unlock the EEPROM to enable writing
    EEKEY = EEKEY2;
    EECONSET = _EECON_RW_MASK; // Execute write and wait for finish
    while (EECONbits.RW);

    /* Write configuration register 1 */
    EEADDR = 0x04; // Addr 0x04 = DEVEE1;
    EEDATA = DEVEE1;
    EEKEY = EEKEY1; // Unlock the EEPROM to enable writing
    EEKEY = EEKEY2;
    EECONSET = _EECON_RW_MASK; // Execute write and wait for finish
    while (EECONbits.RW);

    /* Write configuration register 2 */
    EEADDR = 0x08; // Addr 0x08 = DEVEE2;
    EEDATA = DEVEE2;
    EEKEY = EEKEY1; // Unlock the EEPROM to enable writing
    EEKEY = EEKEY2;
    EECONSET = _EECON_RW_MASK; // Execute write and wait for finish
    while (EECONbits.RW);

    /* Write configuration register 3 */
    EEADDR = 0x0C; // Addr 0x08 = DEVEE3;
    EEDATA = DEVEE3;
    EEKEY = EEKEY1; // Unlock the EEPROM to enable writing
    EEKEY = EEKEY2;
    EECONSET = _EECON_RW_MASK; // Execute write and wait for finish
    while (EECONbits.RW);

    /* Turn off writes */
    EECONbits.WREN = 0;

    /* Re-enable interrupts */
    __builtin_enable_interrupts();

    return EEPROM_ENOERR;
}

/*
 * Function returns ERR<1:0> bits or EEPROM_NOT_READY.
 * Requested data is stored in ee_data
 * Returns zero = no error occurred during the read cycle
 * non-zero = error occurred during the read cycle
 * or Data EEPROM is not ready
 */
eEEPROMErrorCode
eEEPROMHardwareDataRead(EEAddress_t ee_addr, uint32_t *ee_data)
{
    /* Check address */
    if (ee_addr < 0x0000u || ee_addr > 0x0FFCu)
    {
        return EEPROM_INVALID_ADDRESS_ERROR;
    }

    //DEBUG
    //    printf("\r\nReading from EEPROM on adress %d\r\n", ee_addr);


    /* If Data EEPROM to be ready and no operation underway */
    if (EECONbits.RDY == 1 && EECONbits.RW == 0)
    {
        EEADDR = ee_addr & 0xFFC; // Set address on 32-bit boundary

        EECONbits.CMD = 0b000; // Load CMD<2:0> with read command
        EECONbits.WREN = 0; // Access for read

        __builtin_disable_interrupts();

        /* Unlock the EEPROM to enable reading? */
        //EEKEY = EEKEY1;
        //EEKEY = EEKEY2;

        /* Execute the read */
        EECONSET = _EECON_RW_MASK;

        __builtin_enable_interrupts();

        /* Wait for the read to finish */
        while (EECONbits.RW == 1);

        /* Read the data */
        *ee_data = EEDATA;

        return EECONbits.ERR;
    }

    return EEPROM_NOT_READY_ERROR;
}

eEEPROMErrorCode
eEEPROMHardwareDataBlockRead(EEAddress_t addr, void *block, size_t size)
{
    size_t i;
    uint32_t data = 0;
    uint32_t *ptr = (uint32_t*) block;
    for (i = 0; i < size >> 2; i++)
    {
        int result = eEEPROMHardwareDataRead((EEAddress_t) (addr + (i << 2)), &data);
        *(ptr++) = data;

        //DEBUG
        //        printf("\r\nData readed: ");
        //        while (data) {
        //            if (data & 1)
        //                printf("1");
        //            else
        //                printf("0");
        //            data >>= 1;
        //        }
        //        printf("\r\n");

        if (result)
            return result;
    }

    return EEPROM_NO_ERROR;
}

/*
 * Function returns ERR<1:0> bits
 * Returns zero = no error occurred during the write cycle
 * non-zero = error occurred during the write cycle
 * or Data EEPROM is not ready
 */
eEEPROMErrorCode
eEEPROMHardwareDataWrite(EEAddress_t ee_addr, uint32_t ee_data)
{
    /* Check address */
    if (ee_addr < 0x0000u || ee_addr > 0x0FFCu)
    {
        return EEPROM_INVALID_ADDRESS_ERROR;
    }

    uint32_t temp = 0x0000u;
    if (eEEPROMHardwareDataRead(ee_addr, &temp))
        return EEPROM_COMPARE_ERROR;

    /* Do nothing if old value is same as new */
    if (!(temp^ee_data))
    {
        //printf("\r\n* Same values, exiting");
        return EEPROM_NO_ERROR;
    }

    //DEBUG
    //printf("\r\n* Writing %d to EEPROM on adress %d\r\n", ee_data, ee_addr);

    /* If Data EEPROM to be ready and no operation underway */
    if (EECONbits.RDY == 1 && EECONbits.RW == 0)
    {
        EEADDR = ee_addr & 0xFFC; // Load address on a 32-bit boundary
        EEDATA = ee_data;

        //DEBUG
        //        printf("\r\nData written: ");
        //        while (ee_data) {
        //            if (ee_data & 1)
        //                printf("1");
        //            else
        //                printf("0");
        //            ee_data >>= 1;
        //        }
        //        printf("\r\n");

        EECONbits.CMD = 0b001; // Load CMD<2:0> with write command
        EECONbits.WREN = 1; // Access for write

        __builtin_disable_interrupts();

        /* Unlock the EEPROM to enable writing */
        EEKEY = EEKEY1;
        EEKEY = EEKEY2;

        /* Execute the write */
        EECONSET = _EECON_RW_MASK;

        __builtin_enable_interrupts();

        /* Wait for the write to finish */
        while (EECONbits.RW == 1);

        return EECONbits.ERR;
    }

    return EEPROM_NOT_READY_ERROR;
}

eEEPROMErrorCode
eEEPROMHardwareDataBlockWrite(EEAddress_t addr, void *block, size_t size)
{
    size_t i;
    uint32_t data = 0;
    for (i = 0; i < size >> 2; i++)
    {
        data = ((uint32_t *) block)[i];

        int result = eEEPROMHardwareDataWrite((EEAddress_t) (addr + (i << 2)), data);
        if (result)
            return result;
    }

    return EEPROM_NO_ERROR;
}