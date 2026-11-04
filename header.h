#include<LPC21XX.H>
#include<string.h>


#define lcd_d 0xff<<6
#define rs 1<<14
#define e 1<<15


extern unsigned char rfid_buffer[13];

void delay_milliseconds(unsigned int);

void lcd_init(void);
void lcd_command(unsigned char);
void lcd_data(unsigned char);
void lcd_string(unsigned char *);

void uart0_config(void);
void uart0_tx(unsigned char);
unsigned char uart_rx(void);
void uart0_txstr(unsigned char *);

void rfid_read(void);
void keypad_scan(void);

void motor_open(void);
void motor_close(void);

void led_on(void);
void buzzer_on(void);

