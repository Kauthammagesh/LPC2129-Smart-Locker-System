#include "header.h"

void led1_on()
{
	IODIR0 |= 1 << 4;

	IOSET0 = 1 << 4;
	delay_milliseconds(1000);
	IOCLR0 = 1 << 4;
	delay_milliseconds(1000);
}

void led2_on()
{
	IODIR0 |= 1 << 5;

	IOSET0 = 1 << 5;
	delay_milliseconds(1000);
	IOCLR0 = 1 << 5;
	delay_milliseconds(1000);
}

void buzzer_on()
{
	IODIR0 |= 1 << 16;

	IOSET0 = 1 << 16;
	delay_milliseconds(1000);

	IOCLR0 = 1 << 16;
	delay_milliseconds(1000);
}
