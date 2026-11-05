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
	scan:
	rfid_read();
	
	if(strcmp("123456789ABC",(char*)rfid_buf)==0)
	{
		lcd_command(0x01);
		delay_milliseconds(2);
		lcd_command(0x80);
		lcd_string("Access Granted");
		delay_milliseconds(500);
		lcd_command(0x01);
		lcd_string("Enter Password");
		
	}
	else
	{
		lcd_command(0x01);
		delay_milliseconds(2);
		lcd_command(0x80);
		lcd_string("Access Denied");
		delay_milliseconds(500);
		lcd_command(0x01);
		lcd_string("Scan again");
		delay_milliseconds(500);
		goto scan;
	}
	
	while(1);
	
}
