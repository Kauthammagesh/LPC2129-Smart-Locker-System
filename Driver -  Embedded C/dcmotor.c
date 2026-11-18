#include "header.h"

void motor_init()
{
	IODIR1 |= in1|in2;
	IOCLR1 = in1|in2;
}

void motor_rotates()
{
	IOSET1 = in1;
	IOCLR1 = in2;
								 
	delay_milliseconds(3000);

	IOCLR1 = in1;
	

}
