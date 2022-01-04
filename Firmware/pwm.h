#ifndef PWM_H_
#define PWM_H_

#define FPWM 20000                          // 20KHz

#define CH1_N PDC7                          // CH1 L PWM
#define CH1_P PDC1                          // CH1 H PWM

#define CH2_N PDC10                         // CH1 L PWM
#define CH2_P PDC4                          // CH1 H PWM

#define CH3_N PDC8                          // CH1 L PWM
#define CH3_P PDC2                          // CH1 H PWM

typedef enum { PWM_CH1, PWM_CH2, PWM_CH3 } PWMchannel;

void setup_PWM(void);
void start_PWM(void);
void stop_PWM(void);

void set_channel_PWM(PWMchannel channel, float output);

#endif