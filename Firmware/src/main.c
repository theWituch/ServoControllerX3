/*
 * Servo Controller: 3 axis STEP/DIR to analog +/-10V interface
 * 2019 Mateusz Frydrych <thewituch@gmail.com>
 */

#include <xc.h>

/* ----------------------- System includes ----------------------------------*/
#include <stdlib.h>
#include <stdio.h>
#include <string.h>

#include "system.h
#include "memory.h

/* ----------------------- EEPROM includes ----------------------------------*/
#include "eeprom/eeprom.h

/* ----------------------- IO includes --------------------------------------*/
#include "io/io.h

/* ----------------------- PID includes -------------------------------------*/
#include "pid/pid.h

/* ----------------------- Modbus includes ----------------------------------*/
#include "modbus/include/mb.h
#include "modbus/include/mbport.h

/* ----------------------- Other includes -----------------------------------*/
#include "qei.h
#include "capture.h
#include "pwm.h
#include "crc/crc.h

/* ----------------------- Defines ------------------------------------------*/
typedef enum
{
    SYS_BOOT,
    SYS_NORMAL,
    SYS_SAFESTOP,
    SYS_ERROR
} eSYSMode;

// A safe operation makro to immediately go to SAFE_STOP program
#define SAFE_OP(result, operation) \
            if(result = operation) goto SAFE_STOP

/* ----------------------- Constant variables -------------------------------*/

/* ----------------------- Static variables ---------------------------------*/
static volatile eSYSMode eSystemMode;

static ePIDErrorCode ePIDStatus;
static eMBErrorCode eMBStatus;
static eEEPROMErrorCode eEEPROMStatus;

/* ----------------------- Function prototypes ------------------------------*/
int main(void);
void app(void);

/* ----------------------- Function implementations -------------------------*/
int
main(void)
{
    /* Init boot mode at system start */
    eSystemMode = SYS_BOOT;

    while (1)
    {
        /* Maintain state machines of all polled MPLAB Harmony modules. */
        app();
    }

    /* Execution should not come here during normal operation */
    return (EXIT_FAILURE);
}

void
app(void)
{
    switch (eSystemMode)
    {
        case SYS_BOOT:
        {
            /* Clear errors */
            ePIDStatus = PID_ENOERR;
            eMBStatus = MB_ENOERR;
            eEEPROMStatus = EEPROM_ENOERR;

            /* Disable system interrupts */
            disableInterrupts();

            /* Modbus
             * Init the Modbus peripherial, set slave id and enable protocol stack
             */
            SAFE_OP(eMBStatus, eMBInit(MB_RTU, 0x0A, 2, 115200,
                                       MB_PAR_EVEN, MB_STOPB_ONE));
            SAFE_OP(eMBStatus, eMBSetSlaveID(0x0A, TRUE,
                                             ucSlaveID, sizeofa(ucSlaveID)));
            SAFE_OP(eMBStatus, eMBEnable());

            /* LED
             * Set STATE and ERROR led and clear other
             */
            LED_READY = OFF;
            LED_STATE = ON;
            LED_ERROR = OFF;

            setup_SYSTEM();
            setup_QEI();
            start_QEI();
            setup_CAPTURE();
            start_CAPTURE();
            setup_PWM();
            start_PWM();


            /* IO
             * Setup IO system
             */
            eIOSetup();


            /* EEPROM
             * Setup eeprom memory and register EE cells
             */
            SAFE_OP(eEEPROMStatus, eEEPROMSetup(EEPROM_HARDWARE));

            // Register EEPROM cells
            SAFE_OP(eEEPROMStatus,
                    eEEPROMRegisterEECell(&EECELLS.EE_PID1Config,
                                          &MEMORY.xPID1.xConfig,
                                          sizeof (MEMORY.xPID1.xConfig)));
            SAFE_OP(eEEPROMStatus,
                    eEEPROMRegisterEECell(&EECELLS.EE_PID2Config,
                                          &MEMORY.xPID2.xConfig,
                                          sizeof (MEMORY.xPID2.xConfig)));
            SAFE_OP(eEEPROMStatus,
                    eEEPROMRegisterEECell(&EECELLS.EE_PID3Config,
                                          &MEMORY.xPID3.xConfig,
                                          sizeof (MEMORY.xPID3.xConfig)));


            /* PID
             * Setup PID channels and run timer
             */
            const PIDConfig_t xPIDCleanConfig = {
                                                 0.35, 0.015f, 0.01f, 0.005f, 0.005f,
                                                 1.0f, 0.0f, 100.0f,
                                                 10000.0f, 15.0f, 16.0f, 17.0f,
                                                 -14457
            };
            SAFE_OP(ePIDStatus, ePIDInit(&MEMORY.xPID1, xPIDCleanConfig));
            SAFE_OP(ePIDStatus, ePIDInit(&MEMORY.xPID2, xPIDCleanConfig));
            SAFE_OP(ePIDStatus, ePIDInit(&MEMORY.xPID3, xPIDCleanConfig));

            // Setup calculation timer
            SAFE_OP(ePIDStatus, xPIDPortTimerInit(1));
            vPIDPortTimerEnable();

            // Enable modules
            SAFE_OP(ePIDStatus, ePIDEnable(&MEMORY.xPID1));
            SAFE_OP(ePIDStatus, ePIDEnable(&MEMORY.xPID2));
            SAFE_OP(ePIDStatus, ePIDEnable(&MEMORY.xPID3));

            /* Enable system interrupts */
            enableInterrupts();

            /* End boot sequence, go to normal operation mode */
            eSystemMode = SYS_NORMAL;
        }

        case SYS_NORMAL:
        {
            /* System
             * Incerase system cycle counter
             */
            MEMORY.ulSystemCycle++;

            /* LED
             * Set STATE and ERROR led and clear other
             */
            LED_READY = ON;
            LED_STATE = OFF;
            LED_ERROR = OFF;

            /* IO
             * Read inputs on cycle start
             */
            eIOReadInputs();


            /* Memory
             * Copy values to memory struct
             */
            MEMORY.lENCODER1 = (int32_t) ENCODER_CH1;
            MEMORY.lENCODER2 = (int32_t) ((int32_t) ENCODER_CH2 / 40.0f); //TESTING VAL
            MEMORY.lENCODER3 = (int32_t) ENCODER_CH3;

            MEMORY.lPOS1 = (int32_t) POSITION_CH1;
            MEMORY.lPOS2 = (int32_t) POSITION_CH2;
            MEMORY.lPOS3 = (int32_t) POSITION_CH3;

            MEMORY.xPID1.lCommand = (int32_t) (MEMORY.lPOS1);
            MEMORY.xPID2.lCommand = (int32_t) (MEMORY.lPOS2);
            MEMORY.xPID3.lCommand = (int32_t) (MEMORY.lPOS3);

            MEMORY.xPID1.lFeedback = (float32_t) MEMORY.lENCODER1;
            MEMORY.xPID2.lFeedback = (float32_t) MEMORY.lENCODER2;
            MEMORY.xPID3.lFeedback = (float32_t) MEMORY.lENCODER3;


            /* PID
             * Process PIDs and write to outputs
             */
            SAFE_OP(ePIDStatus, ePIDProcess(&MEMORY.xPID1));
            SAFE_OP(ePIDStatus, ePIDProcess(&MEMORY.xPID2));
            SAFE_OP(ePIDStatus, ePIDProcess(&MEMORY.xPID3));

            ANALOG_OUTPUT1 = (float32_t) MEMORY.xPID2.fOutput; //TESTING VAL
            ANALOG_OUTPUT2 = (float32_t) MEMORY.xPID2.fOutput;
            ANALOG_OUTPUT3 = (float32_t) MEMORY.xPID3.fOutput;


            /* System
             * Parse requests
             */
            if (MEMORY.xSystemRequest.READ == 1)
            {
                eEEPROMReadEECell(&EECELLS.EE_PID1Config);

                peEEPROMDataBlockRead(EECELLS.EE_PID2Config.address,
                                      EECELLS.EE_PID2Config.object,
                                      EECELLS.EE_PID2Config.size);

                uint32_t tmp = 0;
                SAFE_OP(eEEPROMStatus, peEEPROMDataRead(128, &tmp));
                MEMORY.xSystemStatus.WORD = (uint16_t) tmp;

                MEMORY.xSystemRequest.READ = 0;
            }

            if (MEMORY.xSystemRequest.SAVE == 1)
            {
                uint16_t usCRC = ulCRCCalculate(CRC16_Modbus,
                                                &MEMORY.xPID1.xConfig,
                                                sizeof (MEMORY.xPID1.xConfig) -
                                                sizeof (MEMORY.xPID1.xConfig.ulCRC));
                MEMORY.xPID1.xConfig.ulCRC = (uint32_t) usCRC;
                eEEPROMSaveEECell(&EECELLS.EE_PID1Config);

                usCRC = ulCRCCalculate(CRC16_Modbus,
                                       &MEMORY.xPID2.xConfig,
                                       sizeof (MEMORY.xPID2.xConfig) -
                                       sizeof (MEMORY.xPID2.xConfig.ulCRC));
                MEMORY.xPID2.xConfig.ulCRC = (uint32_t) usCRC;
                peEEPROMDataBlockWrite(EECELLS.EE_PID2Config.address,
                                       EECELLS.EE_PID2Config.object,
                                       EECELLS.EE_PID2Config.size);

                uint32_t tmp = (uint32_t) MEMORY.xSystemStatus.WORD;
                SAFE_OP(eEEPROMStatus, peEEPROMDataWrite(128, tmp));

                MEMORY.xSystemRequest.SAVE = 0;
            }


            /* ModBUS
             * Poll protocol
             */
            eMBStatus = eMBPoll();


            /* System
             * Signal every 1000th cycle by STATE led toggle
             */
            if (MEMORY.ulSystemCycle % 1000 == 0)
            {
                LED_STATE = ~LED_STATE;
            }


            /* IO
             * Write outputs on cycle end
             */
            eIOWriteOutputs();

            break;
        }

SAFE_STOP:
        case SYS_SAFESTOP:
        {
            /* Safety
             * Perform a safe stop of all modules
             */

            /* LED
             * Set STATE and ERROR led and clear other
             */
            LED_READY = OFF;
            LED_STATE = ON;
            LED_ERROR = ON;

            // Reset outputs
            RELAY_OUTPUT1 = OFF;
            DIGITAL_OUTPUT1 = OFF;
            DIGITAL_OUTPUT2 = OFF;
            DIGITAL_OUTPUT3 = OFF;
            DIGITAL_OUTPUT4 = OFF;
            ANALOG_OUTPUT1 = 0.0f;
            ANALOG_OUTPUT2 = 0.0f;
            ANALOG_OUTPUT3 = 0.0f;
            eIOWriteOutputs();

            // Disable PID modules and timer
            ePIDDisable(&MEMORY.xPID1);
            ePIDDisable(&MEMORY.xPID2);
            ePIDDisable(&MEMORY.xPID3);
            vPIDPortTimerDisable();

            // Disable PWM
            stop_PWM();

            /* End safe stop sequence, go to system error mode */
            eSystemMode = SYS_ERROR;
        }

        case SYS_ERROR:
        {
            /* Lock in error */
            eSystemMode = SYS_ERROR;

            /* LED
             * Set ERROR led and clear other
             */
            LED_READY = OFF;
            LED_STATE = OFF;
            LED_ERROR = ON;

            eIOWriteOutputs();

            /* ModBUS
             * Poll protocol if error don't concern ModBUS module
             */
            if (eMBStatus == MB_ENOERR)
            {
                eMBStatus = eMBPoll();
            }

            break;
        }

        default:
        {
            /* No valid state, go to safe stop mode */
            eSystemMode = SYS_SAFESTOP;
        }
    }
}