#include <xc.h>

#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#include "system.h
#include "pid.h
#include "io.h

struct PID PID_CH1;
struct PID PID_CH2;
struct PID PID_CH3;

float periodfp, periodrecip;
long period;

void init_PID(struct PID *pid)
{
    /* init all structure members */
    (*pid).enable = INPUT_ENABLE;        // mirror state of PIN
    (*pid).command = 0.0L;
    (*pid).feedback = 0.0L;
    (*pid).error = 0.0;
    (*pid).output = 0.0;
    (*pid).deadband = 0.0;
    (*pid).maxerror = 1000.0;
    (*pid).maxerror_i = 0.0;
    (*pid).maxerror_d = 0.0;
    (*pid).maxcmd_d = 0.0;
    (*pid).error_i = 0.0;
    (*pid).prev_error = 0.0;
    (*pid).error_d = 0.0;
    (*pid).prev_cmd = 0.0;
    (*pid).limit_state = 0;
    (*pid).cmd_d = 0.0;
    (*pid).bias = 0.0;
    (*pid).pgain = 0.0;
    (*pid).igain = 0.0;
    (*pid).dgain = 0.0;
    (*pid).ff0gain = 0.0;
    (*pid).ff1gain = 0.0;
    (*pid).maxoutput = 100;        // max PWM DC
    (*pid).multiplier = 1;
    (*pid).ticksperservo = 2;        // 1000us/servo calc
    (*pid).errorcode = 0;

    (*pid).new_cmd = 0;
    (*pid).last_cmd = 0;
    (*pid).new_fb = 0;
    (*pid).last_fb = 0;

    /* Precalculate timing constants */
    period = (*pid).ticksperservo * 100000;    // thread period in ns
    periodfp = period * 0.000000001;        // usually .001 sec
    periodrecip = 1.0 / periodfp;            // usually 1000.0
}

float process_PID(struct PID *pid, long int position, long int encoder)
{
    (*pid).new_cmd = position;
    (*pid).new_fb = encoder;

    (*pid).command  += (long int)((short)((*pid).new_cmd - (*pid).last_cmd));
    (*pid).feedback += (long int)((short)((*pid).new_fb  - (*pid).last_fb ));
    (*pid).last_cmd = (*pid).new_cmd;
    (*pid).last_fb = (*pid).new_fb;

    float tmp1;
    int enable;

    /* get the enable bit */
    enable = (*pid).enable;
    /* calculate the error */
    tmp1 = (float)((*pid).command - (*pid).feedback);

    (*pid).error = tmp1;

    // check for a drive fault ( posn error > allowed )
    if (( (*pid).maxerror > 0.0 ) &&
        ( fabs((float)(*pid).error) > (*pid).maxerror ))
    {

        (*pid).errorcode = 1;
        return 0;
    }

    /* apply error limits */
    if ((*pid).maxerror != 0.0)
    {
        if (tmp1 > (*pid).maxerror)
        {
            tmp1 = (*pid).maxerror;
        }
        else if (tmp1 < -(*pid).maxerror)
        {
            tmp1 = -(*pid).maxerror;
        }
    }
    /* apply the deadband */
    if (tmp1 > (*pid).deadband)
    {
        tmp1 -= (*pid).deadband;
    }
    else if (tmp1 < -(*pid).deadband)
    {
        tmp1 += (*pid).deadband;
    }
    else
    {
        tmp1 = 0;
    }

    /* do integrator calcs only if enabled */
    if (enable != 0)
    {
        /* if output is in limit, don't let integrator wind up */
        if ( (*pid).limit_state == 0 )
        {
            /* compute integral term */
            (*pid).error_i += tmp1 * periodfp;
        }
        /* apply integrator limits */
        if ((*pid).maxerror_i != 0.0)
        {
            if ((*pid).error_i > (*pid).maxerror_i)
            {
                (*pid).error_i = (*pid).maxerror_i;
            }
            else if ((*pid).error_i < -(*pid).maxerror_i)
            {
                (*pid).error_i = -(*pid).maxerror_i;
            }
        }
    }
    else
    {
        /* not enabled, reset integrator */
        (*pid).error_i = 0;
    }

    /* calculate derivative term */
    (*pid).error_d = (tmp1 - (*pid).prev_error) * periodrecip;
    (*pid).prev_error = tmp1;
    /* apply derivative limits */
    if ((*pid).maxerror_d != 0.0)
    {
        if ((*pid).error_d > (*pid).maxerror_d)
        {
            (*pid).error_d = (*pid).maxerror_d;
        }
        else if ((*pid).error_d < -(*pid).maxerror_d)
        {
            (*pid).error_d = -(*pid).maxerror_d;
        }
    }

    /* calculate derivative of command */
    (*pid).cmd_d = (float)((*pid).command - (*pid).prev_cmd) * periodrecip;
    (*pid).prev_cmd = (*pid).command;

    /* apply derivative limits */
    if ((*pid).maxcmd_d != 0.0)
    {
        if ((*pid).cmd_d > (*pid).maxcmd_d)
        {
            (*pid).cmd_d = (*pid).maxcmd_d;
        }
        else if ((*pid).cmd_d < -(*pid).maxcmd_d)
        {
            (*pid).cmd_d = -(*pid).maxcmd_d;
        }
    }

    /* do output calcs only if enabled */
    if (enable != 0)
    {
        /* calculate the output value */
        tmp1 =
            (*pid).bias + (*pid).pgain * tmp1 +
            (*pid).igain * (*pid).error_i +
            (*pid).dgain * (*pid).error_d;
        tmp1 += (*pid).command * (*pid).ff0gain + (*pid).cmd_d * (*pid).ff1gain;
        /* apply output limits */
        if ((*pid).maxoutput != 0.0)
        {
            if (tmp1 > (*pid).maxoutput)
            {
                tmp1 = (*pid).maxoutput;
                (*pid).limit_state = 1;
            }
            else if (tmp1 < -(*pid).maxoutput)
            {
                tmp1 = -(*pid).maxoutput;
                (*pid).limit_state = 1;
            }
            else
            {
                (*pid).limit_state = 0;
            }
        }
    }
    else
    {
        /* not enabled, force output to zero */
        tmp1 = 0.0;
        (*pid).limit_state = 0;
    }

    (*pid).output = tmp1;
    return tmp1;
    /* done */
}

