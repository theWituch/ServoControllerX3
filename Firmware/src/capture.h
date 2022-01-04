#ifndef CAPTURE_H_
#define CAPTURE_H_

extern volatile long int POSITION_CH1;
extern volatile long int POSITION_CH2;
extern volatile long int POSITION_CH3;

void setup_CAPTURE(void);
void start_CAPTURE(void);
void stop_CAPTURE(void);

#endif