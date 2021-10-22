#include <LiquidCrystal.h>

LiquidCrystal lcd(12, 11, 5, 4, 3, 2);

int val;
int tempPin = 0;

void setup() {
  lcd.begin(16, 2);
}

void loop() {
  lcd.setCursor(1, 0);
  val = analogRead(tempPin);
  float cel = ((val * 5.0/1023)/0.01) - 50;

  lcd.print("TEMP = ");
  lcd.print(cel);
  lcd.print("*C");
  delay(1000);
}
 