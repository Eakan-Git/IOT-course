# Simple car parking assistant
## Features:
- When car in range > 150cm from the wall: Blue led turned on.
- When car in range <=150cm && >50cm from the wall: Red led blink and buzzer beeping.
- When car in range <= 50cm from the wall: 3 leds blink together, buzzer too. But the closer the car to the wall, the faster leds blinking.
## Optional:
- Make frequency of buzzer higher when car get closer to the wall.
## Wanted but undone: (Never do)
- When the car is parked, stop all. Because of noise.
Simple idea for this problem: When the car is not moving (getDistance() returned same value, set the counter +=1, then reach defined maxCounter, set the system to parked state.)
But because of lack of accuracy, the getDistance() function returned sometime +-n cm value. So that you have to set the error value and check in error range to regconize the car is not moving.
