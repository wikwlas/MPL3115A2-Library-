#include "twi.h"

void I2C_init(void) {
	DDRC &= ~((1 << SDA_PIN) | (1 << SCL_PIN));
	PORTC |= (1 << SDA_PIN) | (1 << SCL_PIN);

	TWBR = 12;
	TWSR &= ~((1 << TWPS0) | (1 << TWPS1));
}

uint8_t I2C_start(void) {
	TWCR = (1 << TWINT) | (1 << TWSTA) | (1 << TWEN);
	while (!(TWCR & (1 << TWINT)));
	return (TWSR & 0xF8);
}

void I2C_stop(void) {
	TWCR = (1 << TWINT) | (1 << TWSTO) | (1 << TWEN);
}

uint8_t I2C_write(uint8_t byte) {
	TWDR = byte;
	TWCR = (1 << TWINT) | (1 << TWEN);
	while (!(TWCR & (1 << TWINT)));
	return (TWSR & 0xF8);
}

uint8_t I2C_read(uint8_t *value, uint8_t ack) {
	if (ack)
		TWCR = (1 << TWINT) | (1 << TWEN) | (1 << TWEA);
	else
		TWCR = (1 << TWINT) | (1 << TWEN);

	while (!(TWCR & (1 << TWINT)));

	*value = TWDR;
	return (TWSR & 0xF8);
}
