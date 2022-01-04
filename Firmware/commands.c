#include <xc.h>
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#include "system.h
#include "pid.h
#include "qei.h
#include "capture.h
#include "uart.h
#include "nvm.h


extern volatile unsigned short int do_servo;
extern struct PID PID_CH1;

extern int save_setup( void );

void print_tuning(void)
{
    printf("\rCurrent Settings:\r\n");
    printf("servo enabled = %d\r\n",    PID_CH1.enable);
    printf("(p) = %f\r\n",        (double)PID_CH1.pgain);
    printf("(i) = %f\r\n",        (double)PID_CH1.igain);
    printf("(d) = %f\r\n",        (double)PID_CH1.dgain);
    printf("FF(0) = %f\r\n",    (double)PID_CH1.ff0gain);
    printf("FF(1) = %f\r\n",    (double)PID_CH1.ff1gain);
    printf("dead(b)and = %f\r\n",(double)PID_CH1.deadband);
    printf("(m)ax Output = %.2f%%\r\n",(double)PID_CH1.maxoutput);
    printf("(f)ault error = %f\r\n", (double)PID_CH1.maxerror);
    printf("(x)pc cmd multiplier = %hu\r\n", PID_CH1.multiplier);
    printf("(t)icks per servo cycle= %hu\r\n",PID_CH1.ticksperservo);

}

void process_buffer_UART(void)
{
    switch( SERIAL_BUFFER[0] )
    {
    case 'b':
        if (SERIAL_BUFFER[1])
        {
            PID_CH1.deadband = atof(&SERIAL_BUFFER[1]);
            reset_buffer_UART();
            //save_setup();
        }
        reset_buffer_UART();
        printf("dead(b)and = %f\r\n",(double)PID_CH1.deadband);
        break;

    case 'p':
        if (SERIAL_BUFFER[1])
        {
            PID_CH1.pgain = atof(&SERIAL_BUFFER[1]);
            reset_buffer_UART();
            //save_setup();
        }
        printf("(p) = %f\r\n",        (double)PID_CH1.pgain);
        break;
    case 'i':
        if (SERIAL_BUFFER[1])
        {
            PID_CH1.igain = atof(&SERIAL_BUFFER[1]);
            reset_buffer_UART();
            PID_CH1.error_i = 0.0;    //reset integrator
            //save_setup();
        }
        printf("(i) = %f\r\n",        (double)PID_CH1.igain);
        break;
    case 'd':
        if (SERIAL_BUFFER[1])
        {
            PID_CH1.dgain = atof(&SERIAL_BUFFER[1]);
            reset_buffer_UART();
            //save_setup();
        }
        printf("(d) = %f\r\n",        (double)PID_CH1.dgain);
        break;
    case '0':
        if (SERIAL_BUFFER[1])
        {
            PID_CH1.ff0gain = atof(&SERIAL_BUFFER[1]);
            reset_buffer_UART();
            //save_setup();
        }
        printf("FF(0) = %f\r\n",    (double)PID_CH1.ff0gain);
        break;
    case '1':
        if (SERIAL_BUFFER[1])
        {
            PID_CH1.ff1gain = atof(&SERIAL_BUFFER[1]);
            reset_buffer_UART();
            //save_setup();
        }
        printf("FF(1) = %f\r\n",    (double)PID_CH1.ff1gain);
        break;
    case 'm':
        if (SERIAL_BUFFER[1])
        {
            PID_CH1.maxoutput = atof(&SERIAL_BUFFER[1]);
            reset_buffer_UART();
            if(PID_CH1.maxoutput>100)
                PID_CH1.maxoutput = 100;
            //save_setup();
        }
        printf("(m)ax Output = %.2f%%\r\n",(double)PID_CH1.maxoutput);
        break;

    case 'f':
        if (SERIAL_BUFFER[1])
        {
            PID_CH1.maxerror = atof(&SERIAL_BUFFER[1]);
            reset_buffer_UART();
            //save_setup();
        }
        printf("(f)ault error = %f\r\n", (double)PID_CH1.maxerror);
        break;

    case 'x':
        if (SERIAL_BUFFER[1])
        {
            PID_CH1.multiplier = (short)atof(&SERIAL_BUFFER[1]);
            reset_buffer_UART();
            if ( PID_CH1.multiplier < 1 ) PID_CH1.multiplier = 1;
            if ( PID_CH1.multiplier > 16 ) PID_CH1.multiplier = 16;
            //save_setup();
        }
        printf("(x)pc cmd multiplier = %hu\r\n", PID_CH1.multiplier);
        break;

    case 't':
        if (SERIAL_BUFFER[1])
        {
            PID_CH1.ticksperservo = (short)atof(&SERIAL_BUFFER[1]);
            reset_buffer_UART();
            if ( PID_CH1.ticksperservo < 2 ) PID_CH1.ticksperservo = 2;        // 200us/servo calc
            if ( PID_CH1.ticksperservo > 100 ) PID_CH1.ticksperservo = 100; // .1 sec/servo calc
            //save_setup();
        }
        printf("(t)icks per servo cycle= %hu\r\n",PID_CH1.ticksperservo);
        break;

//    case 'r':
//        testS.prediv = atoi(&SERIAL_BUFFER[1]);
//        if((SERIAL_BUFFER[2] == 'c') &&((testS.prediv < 10)&&(testS.prediv>=0)))
//            fire_curve(atoi(&SERIAL_BUFFER[3]));
//        break;

    case 'e':
        printf("\rencoder = 0x%04X = %ld\r\n",ENCODER_CH2, ENCODER_CH2);
        break;

    case 'l':
        print_tuning();
        break;

    case 's':
        printf("\rServo Loop Internal Calcs:\r\n");
        printf("command: %ld\r\n",PID_CH1.command);
        printf("feedback: %ld\r\n",PID_CH1.feedback);
        printf("error: %f\r\n",(double)PID_CH1.error);
        printf("error_i: %f\r\n",(double)PID_CH1.error_i);
        printf("error_d: %f\r\n",(double)PID_CH1.error_d);
        printf("output: %f\r\n",(double)PID_CH1.output);
        printf("limit_state: %d\r\n",(int)PID_CH1.limit_state);
        printf("servo enabled = %d\r\n",    PID_CH1.enable);
        break;

    case 'S':
        if (SERIAL_BUFFER[1])
        {
            double value = atof(&SERIAL_BUFFER[1]);

            if (value > 100.0) value = 100.0;
            if (value < -100.0) value = -100.0;

            printf("Nastawiono wyjscie CH1 na %f%\r\n",        (double)value);
            set_CH1_PWM(value);
        } else {
            printf("Podaj wartosc do nastawienia (-100 do 100)");
        }
        break;

    case 'A':
        if (SERIAL_BUFFER[1])
        {
            int value = atoi(&SERIAL_BUFFER[1]);

            printf("Nastawiono licznik CH2 na %d%\r\n", value);
            POSITION_CH2 = value;
        } else {
            printf("Podaj wartosc do nastawienia");
        }
        break;

    case 'R':
        POSITION_CH1 = 0;
        POSITION_CH2 = 0;
        POSITION_CH3 = 0;
        printf("Wyzerowano liczniki kanalow");
        break;

    case 'I':
        printf("Liczniki kanalow:\r\n");
        printf("CH1: %ld\r\n", POSITION_CH1);
        printf("CH2: %ld\r\n", POSITION_CH2);
        printf("CH3: %ld\r\n\n", POSITION_CH3);

        printf("Enkodery:\r\n");
        printf("CH1: %ld\r\n", ENCODER_CH1);
        printf("CH2: %ld\r\n", ENCODER_CH2);
        printf("CH3: %ld\r\n", ENCODER_CH3);
        break;

    default:
        printf("\r\nUSAGE:\r\n");
        printf("p x.x set proportional gain\r\n");
        printf("i x.x set integral gain\r\n");
        printf("d x.x set differential gain\r\n");
        printf("0 x.x set FF0 gain\r\n");
        printf("1 x.x set FF1 gain\r\n");
        printf("b x.x set deadband\r\n");
        printf("m x.x set max output current(amps)\r\n");
        printf("f x.x set max error before drive faults(counts)\r\n");
        printf("x n   set pc command multiplier (1-16)\r\n");
        printf("t n   set # of 100us ticks/per servo calc(2-100)\r\n");
        printf("e print current encoder count\r\n");
        printf("l print current loop tuning values\r\n");
        printf("s print internal loop components\r\n");
        printf("? print this help\r\n");
    }

    reset_buffer_UART();
}