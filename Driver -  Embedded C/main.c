#include "header.h"

int main()
{
	unsigned char res;
	unsigned char i;
	unsigned char password[5];
	unsigned char attempts = 0;

	motor_init();
	lcd_init();
	lcd_command(0x80);
	lcd_string("Smart Locker");

	delay_milliseconds(2000);

	lcd_command(0x01);
	lcd_string("Scan your Card");

scan:
	rfid_read();

	if (strcmp((char *)rfid_buf, "060068232A67") == 0)
	{
		lcd_command(0x01);
		delay_milliseconds(2);
		lcd_command(0x80);
		lcd_string("Access Granted");

		uart0_txstr("Access Granted through RFID Card\r\n");
		uart0_txstr("Factor I - Authentication Checked \r\n");

		delay_milliseconds(500);
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

	while (attempts <= 3)
	{

		lcd_command(0x80);
		lcd_string("Enter Password");
		uart0_txstr("Password\r\n");

		lcd_command(0xC0);

		for (i = 0; i < 4; i++)
		{
			res = keypad_scan();
			password[i] = res + '0';
			lcd_data('*');
		}
		password[4] = '\0';

		if (strcmp((char *)password, "4387") == 0)
		{
			lcd_command(0x01);
			delay_milliseconds(2);
			lcd_string("Correct Password");

			uart0_txstr("Correct Password \r\n");
			uart0_txstr("Factor II - Authentication Checked \r\n");

			led1_on();
			motor_rotates();
			return 0;
		}
		else
		{
			attempts++;

			lcd_command(0x01);
			delay_milliseconds(2);

			lcd_string("Wrong Password");
			uart0_txstr("Wrong Password \r\n");

			led2_on();

			if (attempts >= 3) // If tried attempt is reaches three attempt
			{
				lcd_command(0x01);
				lcd_command(0x80);
				lcd_string("Try Again later");
				uart0_txstr("Exceeded Attempts Try Again Later \r\n");
				return 0;
			}
		}
	}
	while (1)
		;
}
