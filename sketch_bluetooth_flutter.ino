#include <SoftwareSerial.h>
#include <LCD_I2C.h>

//Serial pins RX | TX
SoftwareSerial BTSerial(10,11);

//Display
LCD_I2C lcd(0x27);

void lcdInit(LCD_I2C *lcd) {
  lcd->begin();
  lcd->backlight();
}

void setup() {
  lcdInit(&lcd);
  lcd.print("Hello, world!");
}

void loop() {
  // put your main code here, to run repeatedly:

}
