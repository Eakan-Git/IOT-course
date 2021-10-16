const int buttonPin = 2;

const int redLed = 3;
const int greenLed = 4;
const int blueLed = 5;

const int orangeLed = 8;
const int whiteLed = 9;
const int yellowLed = 10;

int buttonState = 0;

unsigned long previousMillis;
unsigned long currentMillis;

unsigned long flag = 0;
const int holdingTime = 10000;
const int delayTime = 1000;

void setup()
{
	//Serial.begin(9600); //for debugging
	pinMode(buttonPin, INPUT);

	pinMode(redLed, OUTPUT); //led 1
	pinMode(greenLed, OUTPUT); //led 2
	pinMode(blueLed, OUTPUT); //led 3

	pinMode(orangeLed, OUTPUT); //led 4
	pinMode(whiteLed, OUTPUT); //led 5
	pinMode(yellowLed, OUTPUT); //led 6
}
void loop()
{
	buttonState = digitalRead(buttonPin);
	if(buttonState == HIGH) //push the button
	{
		previousMillis = millis(); //start timing
		currentMillis = millis();

		//leds 4, 5, and 6 turn on at the same time
		digitalWrite(orangeLed, HIGH);
		digitalWrite(whiteLed, HIGH);
		digitalWrite(yellowLed, HIGH);

		//turn off because of outter looping
		digitalWrite(redLed, LOW);
		digitalWrite(greenLed, LOW);
		digitalWrite(blueLed, LOW);

		//while not reach defined holding time
		//leds 1, 2 and 3 blink
		while((currentMillis - previousMillis < holdingTime) && digitalRead(buttonPin) == HIGH)
		{
			//String debug = "Pre: " +  String(previousMillis) + "  Cur: " + String(currentMillis) + '\n';
			//Serial.print(debug);
			blink();
			currentMillis = millis(); //update timing value
		};

		while((currentMillis - previousMillis >= holdingTime) && digitalRead(buttonPin) == HIGH)
		{
			//Serial.print("You pushed the button for 10s, all leds are turned on.\n");
			//holding time reach 10s
			//all leds turned on
			digitalWrite(redLed, HIGH);
			digitalWrite(greenLed, HIGH);
			digitalWrite(blueLed, HIGH);
			
			digitalWrite(orangeLed, HIGH);
			digitalWrite(whiteLed, HIGH);
			digitalWrite(yellowLed, HIGH);
		}
	}
	else
	{
		//release the button: 1, 2, and 3 turned on
		//4, 5, and 6 turned off
		digitalWrite(redLed, HIGH);
		digitalWrite(greenLed, HIGH);
		digitalWrite(blueLed, HIGH);

		digitalWrite(orangeLed, LOW);
		digitalWrite(whiteLed, LOW);
		digitalWrite(yellowLed, LOW);
	}
	//flag = 0; //reset next led memory
}

//flag % 3
//0: red
//1: green
//2: blue
void turnOnLed(int flag)
{
	switch(flag%3)
	{
		case 0:
		{
			digitalWrite(redLed, HIGH);
			if(digitalRead(buttonPin) == HIGH)
				delay(delayTime);
			digitalWrite(redLed, LOW);
			break;
		}
		case 1:
		{
			digitalWrite(greenLed, HIGH);
			if(digitalRead(buttonPin) == HIGH)
				delay(delayTime);
			digitalWrite(greenLed, LOW);
			break;
		}
		case 2:
		{
			digitalWrite(blueLed, HIGH);
			if(digitalRead(buttonPin) == HIGH)
				delay(delayTime);
			digitalWrite(blueLed, LOW);
			break;
		}
	};
}

//not reset the value of flag
//the leds keep memorizing which led gonna be turned on
void blink()
{
	turnOnLed(flag);
	flag += 1;
  	//String debug = "Flag value for blinking: " + String(flag) + '\n';
	//Serial.print(debug);
}
