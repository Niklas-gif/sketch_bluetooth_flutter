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

void BluetoothInit(SoftwareSerial *BTSerial) {
  BTSerial->begin(38400);
}

void setup() {
  lcdInit(&lcd);
  pinMode(9, OUTPUT);
  digitalWrite(9, HIGH);
  Serial.begin(38400);
  BluetoothInit(&BTSerial);
  lcd.print("Hello, world!");
}

void loop() {
  // put your main code here, to run repeatedly:

}
