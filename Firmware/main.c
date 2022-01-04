#include <xc.h>

#include <stdlib.h>
#include <stdio.h>
#include <string.h>

#include "system.h
#include "uart.h
#include "eeprom_1.h
#include "io.h
#include "timer.h
#include "capture.h
#include "qei.h
#include "pwm.h
#include "pid.h


// System state mode
volatile unsigned short int MODE = 0;

// Error data
volatile unsigned short int ERRORCODE = 0;
char ERRORMESSAGE[255];

// System flags
volatile unsigned short int RESET_FLAG = 0;


void main()
{
    unsigned int result;

    /* Setup peripherials */
    setup_UART();
    printf("\r\nSystem powerup\r\n");
    printf("Serial communication setup - OK\r\n");

    printf("System setup - ");
    setup_SYSTEM();
    printf("OK\r\n");

    printf("I/O setup - ");
    setup_IO();
    printf("OK\r\n");

    printf("Position capture setup - ");
    setup_CAPTURE();
    printf("OK\r\n");

    printf("Quadrature encoders setup - ");
    setup_QEI();
    printf("OK\r\n");

    printf("PWM outputs setup - ");
    setup_PWM();
    printf("OK\r\n");

    printf("Timer 1 setup - ");
    setup_TMR1();
    printf("OK\r\n");

    /* Enable peripherials */
    start_CAPTURE();
    start_QEI();
    start_UART();
    start_PWM();
    start_TMR1();

    /* Init PID channels */
    init_PID(&PID_CH1);
    init_PID(&PID_CH2);
    init_PID(&PID_CH3);

    // System informations
    printf("ServoControllerX3\r\n");
    printf("Firmware: %s\r\n", SOFT_VERSION);

    /* Set ready output */
    OUTPUT_READY = 1;

    /* Enable system interrupts */
    enableInterrupts();

    while (1){

        /* Process LED states */
        if (TICK_LEDREADY == 0) {
            LED_READY = ~LED_READY;
            TICK_LEDREADY = TICK_LEDREADYSET;
        }

        if (TICK_LEDSTATE == 0) {
            LED_STATE = ~LED_STATE;
            TICK_LEDSTATE = TICK_LEDSTATESET;
        }

        if (TICK_LEDERROR == 0) {
            LED_ERROR = ~LED_ERROR;
            TICK_LEDERROR = TICK_LEDERRORSET;
        }

        //DEBUG
            if (INPUT_ENABLE){
                LED_READY = 0;
            } else
                LED_READY = 1;

        /* Process main program state */
        switch(MODE) {

            case 0: // LOCKED

                if (RESET_FLAG) //Need to be reseted
                {
                    disableInterrupts();

                    // Reset POSTION counters
                    POSITION_CH1 = POSITION_CH2 = POSITION_CH3 = 0;

                    // Reset ENCODER counters
                    ENCODER_CH1 = ENCODER_CH2 = ENCODER_CH3 = 0;

                    // Reset PID channels
                    init_PID(&PID_CH1);
                    init_PID(&PID_CH2);
                    init_PID(&PID_CH3);

                    // Clear error code and message
                    ERRORCODE = 0;
                    strncpy(ERRORMESSAGE, "", 255);

                    // Reset ERROR led
                    TICK_LEDERRORSET = -1;
                    LED_ERROR = 0;

                    // Enable ready output
                    OUTPUT_READY = 1;

                    // Unlock servo
                    MODE = 1;

                    // Clear RESET flag
                    RESET_FLAG = 0;

                    enableInterrupts();
                }
                break;

            case 1: // NORMAL

                if (TICK_SERVO == 0 && ERRORCODE == 0 && INPUT_ENABLE)
                {
                    // Process PID channels
                    process_PID(&PID_CH1, POSITION_CH1, ENCODER_CH1);
                    process_PID(&PID_CH2, POSITION_CH2, ENCODER_CH2);
                    process_PID(&PID_CH3, POSITION_CH3, ENCODER_CH3);

                    // Check for errors
                    if (ERRORCODE > 0)
                        break;

                    // Update PWM outputs
                    set_channel_PWM(PWM_CH1, PID_CH1.output);
                    set_channel_PWM(PWM_CH2, PID_CH2.output);
                    set_channel_PWM(PWM_CH3, PID_CH3.output);

                    // Reload SERVO tick
                    TICK_SERVO = TICK_SERVOSET;
                }
                break;

            case 2: // TUNING
                printf("TUNING MODE\r\n");

                // Init TUNER
                // Apply step force
                // Get samples
                // Calculate parameters
                // Repeat few times

                break;

            default:
                printf("Unknown state\r\n");
        }


        /* Process RS232 communication */
        if (SERIAL_READY)
        {
            process_buffer_UART();
        }
    }
}

/* Enable interrupts */
void enableInterrupts()
{
    INTCONbits.MVEC = 1;
    asm volatile ("ei");
}

/* Disable interrupts */
void disableInterrupts()
{
    asm volatile ("di");
}

/* Throw system error */
void throwError(short errorcode, char message[])
{
    disableInterrupts();

    // Copy error code and message
    ERRORCODE = errorcode;
    strncpy(ERRORMESSAGE, message, 255);

    /* Process error if needed */
    printf("Error occured! %d:%s\r\n", ERRORCODE, ERRORMESSAGE);

    // Set ERROR led
    TICK_LEDERRORSET = -1;
    LED_ERROR = 1;

    // Disable ready output
    OUTPUT_READY = 0;

    // Lock servo
    MODE = 0;

    // Reset PWM outputs
    set_channel_PWM(PWM_CH1, 0.0);
    set_channel_PWM(PWM_CH2, 0.0);
    set_channel_PWM(PWM_CH3, 0.0);

    enableInterrupts();
}