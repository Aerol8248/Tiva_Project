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

void lcdkarakteryaz(unsigned char c);

void lcdfonksiyonayarla( unsigned char e);

void LCDilkayarlar();

void LCDgit(unsigned char row, unsigned char col);

void LCDSaatYaz(int sa, int dk, int sn);

#define DURATION_IN_SECONDS 86400
extern int totalSeconds;

#endif
