#include <xc.h>

#include "system.h

void setup_SYSTEM(void)
{
    // Write Unlock Sequence to allow write access to CFGCON register
    SYSKEY = 0xAA996655;
    SYSKEY = 0x556699AA;

    CFGCONbits.PMDLOCK = 0;

    /* Disable not used peripherials */

    // ADCs
    PMD1bits.ADCMD = 1;

    // DACs
    PMD1bits.DAC1MD = 1;
    PMD1bits.DAC2MD = 1;
    PMD1bits.DAC3MD = 1;

    // Comaprator
    PMD2bits.CMP1MD = 1;
    PMD2bits.CMP2MD = 1;
    PMD2bits.CMP3MD = 1;
    PMD2bits.CMP4MD = 1;
    PMD2bits.CMP5MD = 1;

    // Operational amplifier
    PMD2bits.OPA1MD = 1;
    PMD2bits.OPA2MD = 1;
    PMD2bits.OPA3MD = 1;
    PMD2bits.OPA5MD = 1;

    // Input Compare
    PMD3bits.IC3MD = 1;
    PMD3bits.IC5MD = 1;
    PMD3bits.IC6MD = 1;
    PMD3bits.IC7MD = 1;
    PMD3bits.IC8MD = 1;
    PMD3bits.IC9MD = 1;
    PMD3bits.IC10MD = 1;
    PMD3bits.IC11MD = 1;
    PMD3bits.IC12MD = 1;
    PMD3bits.IC13MD = 1;
    PMD3bits.IC14MD = 1;
    PMD3bits.IC15MD = 1;
    PMD3bits.IC16MD = 1;

    // Output Compare
    PMD3bits.OC1MD = 1;
    PMD3bits.OC2MD = 1;
    PMD3bits.OC3MD = 1;
    PMD3bits.OC4MD = 1;
    PMD3bits.OC5MD = 1;
    PMD3bits.OC6MD = 1;
    PMD3bits.OC7MD = 1;
    PMD3bits.OC8MD = 1;
    PMD3bits.OC9MD = 1;
    PMD3bits.OC10MD = 1;
    PMD3bits.OC11MD = 1;
    PMD3bits.OC12MD = 1;
    PMD3bits.OC13MD = 1;
    PMD3bits.OC14MD = 1;
    PMD3bits.OC15MD = 1;
    PMD3bits.OC16MD = 1;

    // PWM
    PMD4bits.PWM3MD = 1;
    PMD4bits.PWM5MD = 1;
    PMD4bits.PWM6MD = 1;
    PMD4bits.PWM9MD = 1;
    PMD4bits.PWM11MD = 1;
    PMD4bits.PWM12MD = 1;

    // UART
    PMD5bits.U1MD = 1;
    PMD5bits.U2MD = 1;
    PMD5bits.U3MD = 1;
    PMD5bits.U5MD = 1;
    PMD5bits.U6MD = 1;

    // SPI
    PMD5bits.SPI1MD = 1;
    PMD5bits.SPI2MD = 1;
    PMD5bits.SPI3MD = 1;
    PMD5bits.SPI4MD = 1;
    PMD5bits.SPI5MD = 1;
    PMD5bits.SPI6MD = 1;

    // USB
    PMD5bits.USB1MD = 1;
    PMD5bits.USB2MD = 1;

    // CAN
    PMD5bits.CAN1MD = 1;
    PMD5bits.CAN2MD = 1;
    PMD5bits.CAN3MD = 1;
    PMD5bits.CAN4MD = 1;

    // QEI
    PMD6bits.QEI3MD = 1;
    PMD6bits.QEI5MD = 1;
    PMD6bits.QEI6MD = 1;

    // Lock Write access to CFGCON register
    SYSKEY = 0;

}

/* Enable interrupts */
inline void
enableInterrupts(void)
{
    INTCONbits.MVEC = 1;
    asm volatile ("ei");
}

/* Disable interrupts */
inline void
disableInterrupts(void)
{
    asm volatile ("di");
}