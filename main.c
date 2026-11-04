#include "header.h"

int main()
{
	
	lcd_init();
	lcd_command(0x80);
	lcd_string("Smart Locker");
	
	delay_milliseconds(2000);
	
	lcd_command(0x01);
	lcd_string("Scan your Card");
	
	//uart0_config();
	rfid_read();
	
	while(1);
}
