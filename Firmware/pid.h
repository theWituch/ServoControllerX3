#ifndef PID_H_
#define PID_H_

struct PID {
    long int command;    /* commanded value */
    long int feedback;    /* feedback value */
    float error;        /* command - feedback */
    float deadband;        /* param: deadband */
    float maxerror;        /* param: limit for error */
    float maxerror_i;    /* param: limit for integrated error */
    float maxerror_d;    /* param: limit for differentiated error */
    float maxcmd_d;        /* param: limit for differentiated cmd */
    float error_i;        /* opt. param: integrated error */
    float prev_error;    /* previous error for differentiator */
    float error_d;        /* opt. param: differentiated error */
    long int prev_cmd;    /* previous command for differentiator */
    float cmd_d;        /* opt. param: differentiated command */
    float bias;            /* param: steady state offset */
    float pgain;        /* param: proportional gain */
    float igain;        /* param: integral gain */
    float dgain;        /* param: derivative gain */
    float ff0gain;        /* param: feedforward proportional */
    float ff1gain;        /* param: feedforward derivative */
    float maxoutput;    /* param: limit for PID output */
    float output;        /* the output value */
    short enable;        /* enable input */
    short limit_state;    /* 1 if in limit, else 0 */
    short multiplier;    /* pc command multiplier */
    short ticksperservo;/* number of 100us ticks/servo cycle */
    short errorcode;    /* error code for error tracking */
    int cksum;          /* data block cksum used to verify eeprom */

    // vars used for detection of incremental motion
    unsigned short new_cmd;
    unsigned short last_cmd;
    unsigned short new_fb;
    unsigned short last_fb;
};

extern struct PID PID_CH1;
extern struct PID PID_CH2;
extern struct PID PID_CH3;

void init_PID(struct PID *pid);

float process_PID(struct PID *pid, long int position, long int encoder);

#endif