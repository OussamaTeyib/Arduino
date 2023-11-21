#include <LiquidCrystal_I2C.h>

LiquidCrystal_I2C lcd(0x27, 20, 4);

int thermo = A0;

void setup() {
  pinMode(thermo, INPUT);

  lcd.init();
  lcd.backlight();

  lcd.print("temperature :");
}

void loop() {
  valTemp = analogRead(thermo);
  temp = 0.1463 * valTemp - 51.713;

  lcd.setCursor(0, 1);
  lcd.print("Température: ");
  lcd.print(temp);
  lcd.print("°C")

  delay(5000);
}