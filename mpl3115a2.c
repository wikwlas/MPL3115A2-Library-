#include "mpl3115a2.h"
#include "lcd.h"
#include "twi.h"

#define MPL3115A2_ADDRESS 0x60


void MPL3115A2_Init(void) {
	I2C_init();
	I2C_start();
	I2C_write((MPL3115A2_ADDRESS << 1) | 0x00);
	I2C_write(0x26);
	I2C_write(0x39);;
	I2C_stop();
}

float MPL3115A2_ReadTemp(void) {
    uint8_t data[2];

    I2C_start();
    I2C_write((MPL3115A2_ADDRESS << 1) | 0x00);
    I2C_write(0x04);
    I2C_start();
    I2C_write((MPL3115A2_ADDRESS << 1) | 0x01);

    I2C_read(&data[0], ACK);
    I2C_read(&data[1], NO_ACK);
    I2C_stop();
	int16_t t;
	int16_t temp = (data[0] << 8) | data[1];
    return (float)temp / 256.0;
}

float MPL3115A2_ReadPressure(void) {
	uint8_t data[3];

	I2C_start();
	I2C_write((MPL3115A2_ADDRESS << 1) | 0x00);
	I2C_write(0x01);
	I2C_start();
	I2C_write((MPL3115A2_ADDRESS << 1) | 0x01);
	I2C_read(&data[0], ACK);
	I2C_read(&data[1], ACK);
	I2C_read(&data[2], NO_ACK);
	I2C_stop();

	uint32_t pressure = ((uint32_t)data[0] << 10) | ((uint32_t)data[1] << 2) | ((uint32_t)data[2] >> 6);
	uint32_t p_decimal = ((uint32_t)data[2] & 0x30) >> 4;
	pressure = ((float)pressure+(float)p_decimal/4.0)/100.0;
	return pressure;
}

