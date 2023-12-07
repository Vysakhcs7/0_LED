/*gpio led*/
#include "STM32F407xx.h"

#define led_Green_Pin 		24
#define led_Orange_Pin 		26
#define led_Red_Pin 		28
#define led_Blue_Pin 		30

void delay(void);

int main(void) {
	RCC->AHB1ENR |= (1 << 3);
	GPIOD->MODER |= (1 << led_Green_Pin);
	GPIOD->MODER |= (1 << led_Orange_Pin);
	GPIOD->MODER |= (1 << led_Red_Pin);
	GPIOD->MODER |= (1 << led_Blue_Pin);
	while (1) {

		for (int i = 12; i <= 15; i++) {
			GPIOD->BSRR |= (1 << i);
			delay();
		}
		for (int j = 28; j <= 31; j++) {
			GPIOD->BSRR |= (1 << j);
			delay();
		}
	}
	return 0;
}

void delay(void) {
	int i = 0;
	for (i = 0; i < 40000; i++);
}
