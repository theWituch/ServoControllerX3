#include <xc.h>
#include <sys/attribs.h>
#include <assert.h>
#include <stdbool.h>

#include "system.h
#include "memory.h

/* ----------------------- Platform includes --------------------------------*/
#include "pid/port.h

/* ----------------------- PID includes -------------------------------------*/
#include "pid/pid.h

/* ----------------------- Defines ------------------------------------------*/
#define STOP_TIMER_IN_IDLE_MODE     0x2000
#define TIMER_SOURCE_INTERNAL       0x0000
#define TIMER_SOURCE_EXTERNAL       0x0002
#define TIMER_ON                    0x8000
#define GATED_TIME_DISABLED         0x0000
#define TIMER_16BIT_MODE            0x0000
#define TIMER_32BIT_MODE            0x0004

#define TIMER_PRESCALER_1           0x0000
#define TIMER_PRESCALER_2           0x0010
#define TIMER_PRESCALER_4           0x0020
#define TIMER_PRESCALER_8           0x0030
#define TIMER_PRESCALER_16          0x0040
#define TIMER_PRESCALER_32          0x0050
#define TIMER_PRESCALER_64          0x0060
#define TIMER_PRESCALER_256         0x0070

/* ----------------------- Start implementation -----------------------------*/

/* Inicjalizacja timera sterujacego kontrola regulatora */
ePIDErrorCode
xPIDPortTimerInit(uint16_t usTim1Timerout1ms)
{
    ePIDErrorCode eStatus = PID_ENOERR;

    IPC6bits.T5IP = 5; // Timer interrupt priority     (1 lowest - 7 highest)
    IPC6bits.T5IS = 1; // Timer interrupt subpriority  (0 lowest - 3 highest)

    IFS0CLR = _IFS0_T5IF_MASK; // Clear interrupt flag

    // PR = (FREQUENCY(Hz) * TIME(s) / PRESCALER) * timeout(s)
    assert(((PBCLK2 / 1000 / 256) - 1) * usTim1Timerout1ms <= 0xFFFF);
    PR5 = ((PBCLK2 / 1000 / 256) - 1) * usTim1Timerout1ms;

    T5CONSET = STOP_TIMER_IN_IDLE_MODE |
            TIMER_SOURCE_INTERNAL |
            GATED_TIME_DISABLED |
            TIMER_16BIT_MODE |
            TIMER_PRESCALER_256;

    IEC0SET = _IEC0_T5IE_MASK;

    return eStatus;
}

/* Enable the timer with the timeout passed to xMBPortTimersInit( ) */
inline void
vPIDPortTimerEnable(void)
{
    TMR5 = 0;
    T5CONSET = _T5CON_ON_MASK;
}

/* Disable any pending timers. */
inline void
vPIDPortTimerDisable(void)
{
    T5CONCLR = _T5CON_ON_MASK;
}

/* Create an ISR which is called whenever the timer has expired. This function
 * must then call pxMBPortCBTimerExpired( ) to notify the protocol stack that
 * the timer has expired.
 */
static void
__ISR(_TIMER_5_VECTOR, IPL5AUTO)
prvvPIDPortTimerExpiredISR(void)
{
    // Clear interrupt Flag
    IFS0CLR = _IFS0_T5IF_MASK;

    // Mark PIDs as should be processed
    MEMORY.xPID1.xStatus.CycleState = 1;
    MEMORY.xPID2.xStatus.CycleState = 1;
    MEMORY.xPID3.xStatus.CycleState = 1;

    //Save PID cycle
    MEMORY.ulLastPIDCycle = MEMORY.ulSystemCycle - MEMORY.ulLastPIDCycle;
}
