#ifndef UART_H_
#define UART_H_

#define BAUD_RATE 57600

extern short int SERIAL_READY;
extern char SERIAL_BUFFER[];

void setup_UART(void);
void start_UART(void);
void stop_UART(void);

void process_buffer_UART(void);
void reset_buffer_UART(void);

#endif