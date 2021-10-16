int red = 12;
int yellow = 11;
int green = 10;


void setup()
{
	pinMode(green, OUTPUT);
	pinMode(yellow, OUTPUT);
	pinMode(red, OUTPUT);
} 


void loop()
{
	digitalWrite(green, HIGH); //Turns on the green led
	delay(13000); //wait 13s
	digitalWrite(green, LOW); //Turns off the green led 
	delay(250); //wait 0.25s


	digitalWrite(yellow, HIGH); //Turns on the yellow led 
	delay(6000); //wait 6s
	digitalWrite(yellow, LOW); //Turns off the yellow led 
	delay(250); //wait 0.25s


	digitalWrite(red, HIGH); //Turns the red led 
	delay(9000); //wait 9s
	digitalWrite(red, LOW); //Turns off the red led
	delay(250); //wait 0.25s
}