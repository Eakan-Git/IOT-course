//...well, things
const int blueLed = 12;
const int redLed = 11;
const int orangeLed = 10;
const int buzzer = 9;

//for the ultrasonic sensor
const int trigger = 2;
const int echo = 3;
long duration;
int currentDistance;

//for buzzer and leds
const int maxDelay = 1000;

//for buzzer
const int frequency = 750;

//setup things, nothing to say
void setup()
{
	Serial.begin(9600);

	pinMode(blueLed, OUTPUT);
	pinMode(redLed, OUTPUT);
	pinMode(orangeLed, OUTPUT);

	pinMode(buzzer, OUTPUT);

	pinMode(trigger, OUTPUT);
	pinMode(echo, INPUT);
}

void loop()
{
	currentDistance = getDistance();

	if(currentDistance >= 150)
	{
		safeZone();
	}

	else if(currentDistance < 150 && currentDistance > 50)
	{
		warningZone(maxDelay, frequency);
	}
	
	else
	{
		currentDistance = getDistance();
		while(currentDistance <= 50)
		{
			int delayTime = 20 * currentDistance;
			int tempFrequency = 20 * (50 - currentDistance) + 1000;
			dangerZone(delayTime, tempFrequency);
			currentDistance = getDistance();
		}
	}
}

//calculate the distance from car (the sensor as well) to the wall
long getDistance()
{
	digitalWrite(trigger, LOW);
	delayMicroseconds(2);
	digitalWrite(trigger, HIGH);	
	delayMicroseconds(10);
	digitalWrite(trigger, LOW);
	duration = pulseIn(echo, HIGH);
	return duration * 0.034 / 2;
}

//action in safe zone
void safeZone()
{
	digitalWrite(blueLed, HIGH);
}

//actions in warning zone
void warningZone(int delayTime, int frequency)
{
	digitalWrite(blueLed, LOW);
	digitalWrite(orangeLed, LOW);

	digitalWrite(redLed, HIGH);
	tone(buzzer, frequency);

	delay(delayTime);

	digitalWrite(redLed, LOW);
	noTone(buzzer);
	delay(delayTime);
}

//actions in danger zone
void dangerZone(int delayTime, int frequency)
{ 
	digitalWrite(blueLed, HIGH);
	digitalWrite(redLed, HIGH);
	digitalWrite(orangeLed, HIGH);
	tone(buzzer, frequency);

	delay(delayTime);

	digitalWrite(blueLed, LOW);
	digitalWrite(redLed, LOW);
	digitalWrite(orangeLed, LOW);
	noTone(buzzer);

	delay(delayTime);
}