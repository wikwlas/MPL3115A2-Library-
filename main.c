#include <avr/io.h>
#include <util/delay.h>
#include "mpl3115a2.h"
#include "lcd.h"
#include "rs232.h"

int main(void) {
	lcdinit();
	MPL3115A2_Init();

	char text[16];
	USART_init();
	sei();
	while (1) {
		float temperature = MPL3115A2_ReadTemp();
		float pressure = MPL3115A2_ReadPressure();

		lcd_clear();
		lcd_set_xy(0, 0);
		printf("Temp: %.2f C", temperature);

		lcd_set_xy(0, 1);
		printf("Pres: %.2fhPa", pressure);
		
		if(decode) {
			if (strncmp((void* )bufor, "temp", 4) == 0) {
				sprintf(text, "Temp: %.2f C\n", temperature);
				USART_send(text);
			} 
			else if (strncmp((void* )bufor, "press", 5) == 0) {
				sprintf(text, "Pres: %.2fhPa\n", pressure);
				USART_send(text);
			} 
			else USART_send("\r\nUnknown command\r\n");
			decode = 0;
			indeks = 0;
			memset((void *)bufor, 0, MAX_BUF);
		}
		_delay_ms(1000);
	}
	return 0;
}
