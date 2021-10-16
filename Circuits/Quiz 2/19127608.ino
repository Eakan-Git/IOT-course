int LED = 2;
int LDR = A0;

void setup()
{
	pinMode(LED, OUTPUT);
	pinMode(LDR, INPUT);
}

void loop()
{
	int value = analogRead(LDR);
	if (value < 500)
	{
		digitalWrite(LED, HIGH);
	}
	else
	{
		digitalWrite(LED, LOW);
	}
}