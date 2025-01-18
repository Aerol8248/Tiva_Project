#ifndef LCD_H_
#define LCD_H_

// LCD Pin Tanımları
#define LCDPORT    GPIO_PORTB_BASE
#define RS         GPIO_PIN_0
#define E          GPIO_PIN_1
#define D4         GPIO_PIN_4
#define D5         GPIO_PIN_5
#define D6         GPIO_PIN_6
#define D7         GPIO_PIN_7

void LCDTemizle();

void lcdkomut(unsigned char c);

void lcdilkayar();

void lcdkarakteryaz(unsigned char  );

void lcdfonksiyonayarla(unsigned char DL, unsigned char N,unsigned char F);

void LCDgit(unsigned char,unsigned char);

#endif
