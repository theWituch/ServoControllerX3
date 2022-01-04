#include <xc.h>

/* ----------------------- System includes ----------------------------------*/
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#include "system.h

/* ----------------------- Platform includes --------------------------------*/
#include "pid/port.h

/* ----------------------- PID includes -------------------------------------*/
#include "pid/pid.h

/* ----------------------- Constant variables -------------------------------*/
const PIDConfig_t xPIDCleanConfig
__attribute__((weak)) = {
                         0.0f, 0.0f, 0.0f, 0.0f, 0.0f,
                         0.0f, 0.0f, 0.0f,
                         0.0f, 0.0f, 0.0f, 0.0f,
                         -1
};

/* ----------------------- Static variables ---------------------------------*/

/* ----------------------- Function implementations -------------------------*/

/**
 *
 * @param xPIDObject
 * @param xPIDConfig
 *
 * @return eStatus
 */
ePIDErrorCode
ePIDInit(PID_t *xPIDObject, PIDConfig_t xPIDConfig)
{
    ePIDErrorCode eStatus = PID_ENOERR;

    if (&xPIDConfig != NULL)
    {
        xPIDObject->xConfig = xPIDConfig;
    } else
    {
        xPIDObject->xConfig.fPGain = 0.0f;
        xPIDObject->xConfig.fIGain = 0.0f;
        xPIDObject->xConfig.fDGain = 0.0f;
        xPIDObject->xConfig.fFF0Gain = 0.0f;
        xPIDObject->xConfig.fFF1Gain = 0.0f;
    }

    xPIDObject->xStatus.Enabled = 0;
    xPIDObject->xStatus.LimitState = 0;


    xPIDObject->lCommand = 0.0f;
    xPIDObject->lCommandPrevious = 0.0f;

    xPIDObject->lFeedback = 0.0f;
    xPIDObject->lFeedbackPrevious = 0.0f;

    xPIDObject->fError = 0.0f;
    xPIDObject->fErrorPrevious = 0.0f;

    xPIDObject->fOutput = 0.0f;

    return eStatus;
}

inline ePIDErrorCode
ePIDEnable(PID_t *xPIDObject)
{
    xPIDObject->xStatus.Enabled = 1;

    return PID_ENOERR;
}

inline ePIDErrorCode
ePIDDisable(PID_t *xPIDObject)
{
    xPIDObject->xStatus.Enabled = 0;

    return PID_ENOERR;
}

ePIDErrorCode
ePIDProcess(PID_t *xPIDObject)
{
    ePIDErrorCode eStatus = PID_ENOERR;

    float32_t tmp_fErrorAbs; // Temporary absolute error value
    float32_t tmp_fOutput; // Temporary output value
    float32_t tmp_dt = (float32_t) 5.0f / 1000.0f; // Temporary time (5ms)


    /* Check for regulator is enabled */
    if (xPIDObject->xStatus.Enabled == 0)
    {
        xPIDObject->fOutput = 0.0f;

        xPIDObject->xStatus.ucErrorCode = PID_DISABLED;
        return PID_ENOERR;
    }

    /* Check if regulator should be processed */
    if (xPIDObject->xStatus.CycleState == 0)
    {
        return PID_ENOERR;
    } else
    {
        xPIDObject->xStatus.CycleState = 0;
    }

    /* Calculate the regulation error */
    xPIDObject->fError = (float32_t) (xPIDObject->lCommand - xPIDObject->lFeedback);
    tmp_fErrorAbs = fabs(xPIDObject->fError);

    /* Check for a drive fault when (Error > ErrorLimit) */
    if ((xPIDObject->xConfig.fErrorLimit > 0.0f) &&
        (tmp_fErrorAbs > xPIDObject->xConfig.fErrorLimit))
    {
        xPIDObject->fOutput = 0.0f;

        xPIDObject->xStatus.ucErrorCode = PID_ERROREXCEED;
        return PID_ERROREXCEED;
    }

    /* Apply error deadband */
    //    if (tmp_fErrorAbs <= xPIDObject->xConfig.fDeadband)
    //    {
    //        xPIDObject->fError = 0.0f;
    //    }

    if (xPIDObject->fError > xPIDObject->xConfig.fDeadband)
    {
        xPIDObject->fError -= xPIDObject->xConfig.fDeadband;
    }
    else if (xPIDObject->fError < -xPIDObject->xConfig.fDeadband)
    {
        xPIDObject->fError += xPIDObject->xConfig.fDeadband;
    } else
    {
        xPIDObject->fError = 0.0f;
    }


    // Proportional term
    xPIDObject->fPOutput = (float32_t) (xPIDObject->xConfig.fPGain * xPIDObject->fError);

    // Integral term
    /* if output is in limit, don't let integrator wind up */
    if (xPIDObject->xStatus.LimitState == 0)
    {
        xPIDObject->fErrorIntegral += (float32_t) (((xPIDObject->fErrorPrevious + xPIDObject->fError) / 2.0f) * tmp_dt);
    }
    xPIDObject->fIOutput = (float32_t) (xPIDObject->xConfig.fIGain * xPIDObject->fErrorIntegral);

    // Derivative term
    xPIDObject->fErrorDerivative = (float32_t) ((xPIDObject->fError - xPIDObject->fErrorPrevious) / tmp_dt);
    xPIDObject->fDOutput = (float32_t) (xPIDObject->xConfig.fDGain * xPIDObject->fErrorDerivative);

    // FeedForward term
    xPIDObject->fFF0Output = xPIDObject->xConfig.fFF0Gain * xPIDObject->lCommand;
    xPIDObject->fFF1Output = xPIDObject->xConfig.fFF1Gain * xPIDObject->fErrorDerivative;

    // Apply PID total output bias
    tmp_fOutput = (float32_t) (xPIDObject->xConfig.fBias);

    // Calculate PID total output value
    tmp_fOutput += (float32_t) (xPIDObject->fPOutput + xPIDObject->fIOutput + xPIDObject->fDOutput);

    // Calculate FF total output value
    tmp_fOutput += (float32_t) (xPIDObject->fFF0Output + xPIDObject->fFF1Output);


    /* Apply output limits */
    if (xPIDObject->xConfig.fOutputLimit != 0.0f)
    {
        xPIDObject->xStatus.LimitState = 1;
        if (tmp_fOutput > xPIDObject->xConfig.fOutputLimit)
        {
            tmp_fOutput = xPIDObject->xConfig.fOutputLimit;
        } else
            if (tmp_fOutput < -xPIDObject->xConfig.fOutputLimit)
        {
            tmp_fOutput = -xPIDObject->xConfig.fOutputLimit;
        } else
        {
            xPIDObject->xStatus.LimitState = 0;
        }
    }


    xPIDObject->fOutput = tmp_fOutput;

    // Save error to previous error
    xPIDObject->lCommandPrevious = xPIDObject->lCommand;
    xPIDObject->lFeedbackPrevious = xPIDObject->lFeedback;
    xPIDObject->fErrorPrevious = xPIDObject->fError;

    xPIDObject->xStatus.ucErrorCode = PID_ENOERR;

    return eStatus;
}
