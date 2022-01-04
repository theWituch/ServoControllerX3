#ifndef IO_H_
#define IO_H_

typedef union {
    __uint8_t BYTE;
    struct {
        __uint8_t X0:1;
        __uint8_t X1:1;
        __uint8_t X2:1;
        __uint8_t X3:1;
        __uint8_t X4:1;
        __uint8_t X5:1;
        __uint8_t X6:1;
        __uint8_t X7:1;
    };
} __DIO_t;

#endif