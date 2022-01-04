#define DI1             ~PORTGbits.RG6
#define DI2             ~PORTGbits.RG7
#define DI3             ~PORTGbits.RG8
#define DI4             ~PORTGbits.RG9

#define DO1             LATCbits.LATC8
#define DO2             LATDbits.LATD5
#define DO3             LATAbits.LATA12
#define DO4             LATAbits.LATA11

#define RO1             LATBbits.LATB11

#define LED_READY       LATFbits.LATF0
#define LED_STATE       LATFbits.LATF1
#define LED_ERROR       LATBbits.LATB10