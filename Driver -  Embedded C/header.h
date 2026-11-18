#include<LPC21XX.H>
#include<string.h>


#define lcd_d 0xff<<6
#define rs 1<<14
#define e 1<<15

#define c0 (IOPIN1 &(1<<23))
#define c1 (IOPIN1 &(1<<24))
#define c2 (IOPIN1 &(1<<25))
#define c3 (IOPIN1 &(1<<26))
#define r0 1<<27
#define r1 1<<28
#define r2 1<<29
#define r3 1<<30

#define in1 1<<18
#define in2 1<<19

extern unsigned char rfid_buf[13];

void delay_milliseconds(unsigned int);

void lcd_init(void);
void lcd_command(unsigned char);
void lcd_data(unsigned char);
void lcd_string(unsigned char *);

void uart0_config(void);
void uart0_tx(unsigned char);
unsigned char uart0_rx(void);
void uart0_txstr(unsigned char *);

void rfid_read(void);
unsigned int keypad_scan(void);

void motor_init(void);
void motor_rotates(void);

void led1_on(void);
void led2_on(void);

