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

void testDisplay(LCD_I2C *lcd,char mode) {
  switch (mode) {
  case '1': {
    lcd->clear();
    lcd->println("Mode: 1");
    break;
    }
  case '2': {
    lcd->clear();
    lcd->println("Mode: 2");
    break;
  }
  case '3': {
    lcd->clear();
    lcd->println("Mode: 3");
    break;
  }
  case '4': {
    lcd->clear();
    lcd->println("Mode: 4");
    break;
  }
  default: {
    lcd->clear();
    lcd->println("None/INIT");
  }
  }
}

void setup() {
  lcdInit(&lcd);
  pinMode(9, OUTPUT); //<-- Connect Pin 9 to [ET] for configuration of the hc-05 moudle
  digitalWrite(9, HIGH);
  Serial.begin(38400);
  BTSerial.begin(38400);
  //lcd.print("Hello, world!");
  testDisplay(&lcd,'0');
}

void loop() {
  if (Serial.available()) {
       BTSerial.write(Serial.read());
    }
 
  if (BTSerial.available()) {
    char incomingChar = BTSerial.read();
      Serial.println(incomingChar);
       Serial.write(incomingChar);
       testDisplay(&lcd, '2');
    }

}