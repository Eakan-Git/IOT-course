#include <LiquidCrystal.h>

LiquidCrystal lcd(12, 11, 5, 4, 3, 2);
//for switching lcd screen
unsigned int stateCounter = 0;
//pin
int tempPin = A0;
int buttonPin = 8;
//for button state checking
int buttonState;

void setup()
{
	lcd.begin(16, 2);
	pinMode(buttonPin, INPUT);
	pinMode(tempPin, INPUT);
}

void loop()
{
	if(digitalRead(buttonPin) == HIGH)
	{	
		while(digitalRead(buttonPin) == HIGH)
		{
			if(digitalRead(buttonPin) == LOW) break;
			display();
		};
		++stateCounter;
	}
	else
	{
		lcd.clear();
	}
}

void display()
{
	switch(stateCounter%3)
	{
		case 0:
		{
			lcd.setCursor(5, 0);
			lcd.print("CLASS");
			lcd.setCursor(1, 1);
			lcd.print("VLDC2 - 19CLC4");
			break;
		}
		case 1:
		{
			lcd.setCursor(3, 0);
			lcd.print("N.Q TRUONG");
			lcd.setCursor(4, 1);
			lcd.print("19127608");
			break;
		}
		case 2:
		{
			String str = "TEMP: " + String(getTempInCel());
			lcd.setCursor(3, 0);
			lcd.print(str);
			break;
		}
	};
}

//return temperature in Celcius
float getTempInCel()
{
	int val = analogRead(tempPin);
  	return ((val * 5.0/1023)/0.01) - 50;
}