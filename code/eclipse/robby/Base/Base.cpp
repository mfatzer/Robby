// Do not remove the include below
#include "Base.h"
#include "Motor.h"
#include "TimerA.h"
#include "TimerC.h"
#include "Logger.h"


Logger setupLogger("setup()");
Logger loopLogger("loop()");

Motor motor1("Motor1", 10, 11, false, LeoTimer1);
Motor motor2("Motor2", 8, 9, true, LeoTimer3);


//The setup function is called once at startup of the sketch
void setup()
{
	Serial.begin(57600);
//	while (!Serial) {
//		;
//	}
	setupLogger.log("Start");
	motor1.setup();
	motor2.setup();
	motor1.setSpeed(200);
	motor2.setSpeed(200);
}

// The loop function is called in an endless loop
void loop()
{
//	motor1.setDirection(FORWARD);
//	motor2.setDirection(FORWARD);
//	motor1.setSpeed(255);
//	motor2.setSpeed(255);
//	delay(1000);

	motor1.setDirection(BACKWARD);
	motor2.setDirection(BACKWARD);
	delay(1000);

	motor1.setDirection(FORWARD);
	motor2.setDirection(FORWARD);
	delay(1000);

	//	motor1.setSpeed(0);
//	motor2.setSpeed(0);
//	delay(1000);

//	motor1.setDirection(BACKWARD);
//	motor2.setDirection(BACKWARD);
//	motor1.setSpeed(0);
//	motor2.setSpeed(0);
//	delay(1000);
}
