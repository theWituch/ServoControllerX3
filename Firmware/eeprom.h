#ifndef EEPROM_H_
#define EEPROM_H_


typedef unsigned int address;
typedef unsigned int block;

void setup_EEPROM(void);

int data_read_EEPROM(address ee_addr, int *ee_data);
int data_write_EEPROM(address ee_addr, int ee_data);

#endif