#include <xc.h>
#include <stdio.h>

#include "system.h
#include "pwm.h

void setup_PWM(void)
{

    // Write Unlock Sequence to allow write access to CFGCON register
    SYSKEY = 0xAA996655;
    SYSKEY = 0x556699AA;

    // Disable unused PWM channels
    CFGCONbits.PMDLOCK = 0;
    PMD4bits.PWM3MD = 1;        // Disable PWM3
    PMD4bits.PWM5MD = 1;        // Disable PWM5
    PMD4bits.PWM6MD = 1;        // Disable PWM6
    PMD4bits.PWM9MD = 1;        // Disable PWM9
    PMD4bits.PWM11MD = 1;       // Disable PWM11
    PMD4bits.PWM12MD = 1;       // Disable PWM12

    // Remap PWM pins
    CFGCONbits.PWMAPIN1=1;      // Remap PWM7H to PWM1L
    CFGCONbits.PWMAPIN2=1;      // Remap PWM8H to PWM2L
    CFGCONbits.PWMAPIN4=1;      // Remap PWM10H to PWM4L

    // Lock Write access to CFGCON register
    SYSKEY = 0;


    // PWM Module configuration
    PTCON = 0;                  // Reset PWM Module
    IOCON1 = IOCON2 = IOCON4 = IOCON7 = IOCON8 = IOCON10 = 0;

    // Set PWM Period on Primary Time Base */
    PTPER = FCY / FPWM;


    IOCON1bits.FLTMOD = 0b11;   // Disable PWM1 Fault mode
    IOCON1bits.PENH = 1;        // PWM module controls PWMxH pin
    IOCON2 =  IOCON4 =  IOCON7 =  IOCON8 =  IOCON10 = IOCON1;


    PWMCON1bits.DTC = 0b10;     // Disable Dead time compensation function
    PWMCON2 = PWMCON4 = PWMCON7 = PWMCON8 = PWMCON10 = PWMCON1;

    PDC1 = PDC2 = PDC4 = PDC7 = PDC8 = PDC10 = 0;       // Set 0 to outputs
}

void start_PWM(void)
{
    PTCONbits.PTEN = 1;
}

void stop_PWM(void)
{
    PTCONbits.PTEN = 0;
}


void set_channel_PWM(PWMchannel channel, float output)
{
    short dir = 1, negative = 0, positive = 0;

    // Get absolute value and identify direction
    if (output < 0.0)
    {
        output = -output;
        dir = 0;
    }

    // Limit max output
    if (output > 1.0)
    {
        output = 1.0;
    }

    // Depends on direction set PWM channels duty
    if (dir)
    {
        positive = PTPER*output;
    } else
    {
        negative = PTPER*output;
    }

    // Choose channel to set
    switch (channel)
    {
        case PWM_CH1:
            CH1_N = negative;
            CH1_P = positive;
            break;

        case PWM_CH2:
            CH2_N = negative;
            CH2_P = positive;
            break;

        case PWM_CH3:
            CH3_N = negative;
            CH3_P = positive;
            break;
    }
}

void set_CH1_PWM(float output)
{
    short temp_dir;
    long temp;

    if (output < 0.0 )
    {
        output = -output;
        temp_dir = 0;
    }
    else
        temp_dir = 1;

    if (output > 100.0)           // Limit max output
        output = 100.0;

    temp = PTPER*(output/100);
    if(temp > PTPER)
        temp = PTPER;          // 100% max PWM

    if ( temp_dir == 1 )
    {
        CH1_N = 0;              // 0V to first output
        CH1_P = temp;           // PWM to the other
    }
    else
    {
        CH1_N = temp;           // PWM to first output
        CH1_P = 0;              // 0V to the other
    }
}

void set_CH2_PWM(float output)
{
    short temp_dir;
    long temp;

    if (output < 0.0 )
    {
        output = -output;
        temp_dir = 0;
    }
    else
        temp_dir = 1;

    if (output > 100.0)           // Limit max output
        output = 100.0;

    temp = PTPER*(output/100);
    if(temp > PTPER)
        temp = PTPER;          // 100% max PWM

    if ( temp_dir == 1 )
    {
        CH2_N = 0;              // 0V to first output
        CH2_P = temp;           // PWM to the other
    }
    else
    {
        CH2_N = temp;           // PWM to first output
        CH2_P = 0;              // 0V to the other
    }
}

void set_CH3_PWM(float output)
{
    short temp_dir;
    long temp;

    if (output < 0.0 )
    {
        output = -output;
        temp_dir = 0;
    }
    else
        temp_dir = 1;

    if (output > 100.0)           // Limit max output
        output = 100.0;

    temp = PTPER*(output/100);
    if(temp > PTPER)
        temp = PTPER;          // 100% max PWM

    if ( temp_dir == 1 )
    {
        CH3_N = 0;              // 0V to first output
        CH3_P = temp;           // PWM to the other
    }
    else
    {
        CH3_N = temp;           // PWM to first output
        CH3_P = 0;              // 0V to the other
    }
}