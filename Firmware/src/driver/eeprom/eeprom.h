#ifndef EEPROM_H_
#define EEPROM_H_

#include "eeprom/port.h

/* ----------------------- Defines ------------------------------------------*/

/* ----------------------- Type definitions ---------------------------------*/

typedef enum
{
    EEPROM_HARDWARE,                    /*!< hardware mode. */
    EEPROM_SOFTWARE,                    /*!< software emulation mode. */
} eEEPROMMode;

/*! \ingroup eeprom
 * \brief Errorcodes used in PID module
 */
typedef enum
{
    EEPROM_ENOERR,                     /*!< no error */
    EEPROM_NOIMPLEMENTATION,            /*!< no implementation */
    EEPROM_CELLREGISTERED,              /*!< cell already registered */
    EEPROM_CELLNOTREGISTERED,           /*!< cell not registered */
    EEPROM_SIZEMISMATCH,                /*!< dest or source size mismatch */
} eEEPROMErrorCode;

/* EEPROM data cell structure */
typedef struct
__attribute__((packed))
{
    __uint32_t address;
    __uint32_t *object;
    __uint16_t size;
    __uint8_t  registered : 1;
}
EECell_t;

typedef uint32_t EEAddress_t;

/* ----------------------- Constant variables -------------------------------*/

/* ----------------------- Static variables ---------------------------------*/

/* ----------------------- Function prototypes ------------------------------*/

eEEPROMErrorCode eEEPROMSetup(eEEPROMMode eMode);

eEEPROMErrorCode eEEPROMRegisterEECell(EECell_t *cell, void *block,
                                       size_t size);

eEEPROMErrorCode eEEPROMReadEECell(EECell_t *cell);

eEEPROMErrorCode eEEPROMSaveEECell(EECell_t *cell);

eEEPROMErrorCode eEEPROMReadFromEECell(EECell_t *cell, void *destination,
                                       size_t destSize);

eEEPROMErrorCode eEEPROMSaveToEECell(EECell_t *cell, void *source,
                                     size_t sourceSize);

eEEPROMErrorCode eEEPROMReadAllEECells(EECell_t *cells, size_t quantity);

eEEPROMErrorCode eEEPROMSaveAllEECells(EECell_t *cells, size_t quantity);


eEEPROMErrorCode eEEPROMHardwareSetup(void);
eEEPROMErrorCode eEEPROMSoftwareSetup(void);

typedef eEEPROMErrorCode    (*peEEPROMDataRead_t)(EEAddress_t ee_addr,
                                                  uint32_t *ee_data);

typedef eEEPROMErrorCode    (*peEEPROMDataWrite_t)(EEAddress_t ee_addr,
                                                   uint32_t ee_data);

typedef eEEPROMErrorCode    (*peEEPROMDataBlockRead_t)(EEAddress_t addr,
                                                       void *block,
                                                       size_t size);

typedef eEEPROMErrorCode    (*peEEPROMDataBlockWrite_t)(EEAddress_t addr,
                                                        void *block,
                                                        size_t size);

extern peEEPROMDataRead_t         peEEPROMDataRead;
extern peEEPROMDataWrite_t        peEEPROMDataWrite;
extern peEEPROMDataBlockRead_t    peEEPROMDataBlockRead;
extern peEEPROMDataBlockWrite_t   peEEPROMDataBlockWrite;

eEEPROMErrorCode eEEPROMHardwareDataRead(EEAddress_t ee_addr,
                                         uint32_t *ee_data);

eEEPROMErrorCode eEEPROMHardwareDataWrite(EEAddress_t ee_addr,
                                          uint32_t ee_data);

eEEPROMErrorCode eEEPROMHardwareDataBlockRead(EEAddress_t addr,
                                              void *block, size_t size);

eEEPROMErrorCode eEEPROMHardwareDataBlockWrite(EEAddress_t addr,
                                               void *block, size_t size);


eEEPROMErrorCode eEEPROMSoftwareDataRead(EEAddress_t ee_addr,
                                         uint32_t *ee_data);

eEEPROMErrorCode eEEPROMSoftwareDataWrite(EEAddress_t ee_addr,
                                          uint32_t ee_data);

eEEPROMErrorCode eEEPROMSoftwareDataBlockRead(EEAddress_t addr,
                                              void *block, size_t size);

eEEPROMErrorCode eEEPROMSoftwareDataBlockWrite(EEAddress_t addr,
                                               void *block, size_t size);

#endif