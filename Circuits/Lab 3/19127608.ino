const int potentiometer = A0;
const int led = 2;
const int buzzer = 13;
const int pir = 3;
const int delayTime = 500;
const int buzzerFre = 1000;
int ledVal;

//pt range 0 - 254
//ptVal <= 127: day
//ptVal > 127: night
const int flag = 127;
void setup()
{
	//Serial.begin(9600);
	pinMode(potentiometer, INPUT);
	pinMode(led, OUTPUT);
	pinMode(buzzer, OUTPUT);
}

void loop()
{
	ledVal = getLedVal();
	Serial.println(ledVal);
	if(ledVal <= flag) day();
	else night();
	delay(delayTime);
}

int getLedVal()
{
	int ptVal = analogRead(potentiometer);
	return map(ptVal, 0, 1023, 0, 255);
}


//turn off the led
//moving object -> beeping
void day()
{	
	if(digitalRead(3) == LOW)
	{
		//Serial.println("day");
		digitalWrite(led, LOW);
	}
	else
	{
		//Serial.println("DAY");
		tone(buzzer, buzzerFre);
		delay(delayTime);
		noTone(buzzer);
	}
}

//turn on the led
//moving object -> blink + beeping
void night()
{
	if(digitalRead(3) == LOW)
	{
		//Serial.println("night");
		digitalWrite(led, ledVal);
	}
	else
	{
		//Serial.println("NIGHT");
		digitalWrite(led, ledVal);
		tone(buzzer, buzzerFre);
		delay(delayTime);
		digitalWrite(led, LOW);
		noTone(buzzer);
	}
}