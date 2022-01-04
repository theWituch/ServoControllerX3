#ifndef QEI_H_
#define QEI_H_

#define ENCODER_CH1 POS4CNT
#define ENCODER_CH2 POS2CNT
#define ENCODER_CH3 POS1CNT

void setup_QEI(void);
void start_QEI(void);
void stop_QEI(void);

#endif