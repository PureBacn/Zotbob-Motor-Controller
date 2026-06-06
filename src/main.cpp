#include <Arduino.h>
#include "config.h"

#include "BTS7960.h"

BTS7960 LeftController(LeftEN, LeftLPWM, LeftRPWM);
BTS7960 RightController(RightEN, RightLPWM, RightRPWM);

struct MotorSpeeds {
	int l;
	int r;
};

void setup() {
	Serial.begin(115200);
	pinMode(LED_BUILTIN, OUTPUT);
}

void setSpeed(BTS7960& controller, int speed) {
	if (speed > 0)
		controller.TurnRight(speed);
	else if (speed < 0)
		controller.TurnLeft(-speed);
	else
		controller.Stop();
}

void move(MotorSpeeds&& speeds) {
	setSpeed(LeftController, speeds.l);
	setSpeed(RightController, speeds.r);
}

void loop() {
	digitalWrite(LED_BUILTIN, HIGH);
	Serial.println("On");
	delay(1000);
	digitalWrite(LED_BUILTIN, LOW);
	Serial.println("Off");
	delay(1000);

	move(MotorSpeeds{200, 200});
	delay(5000);
	move(MotorSpeeds{-200, -200});
	delay(5000);
	move(MotorSpeeds{0, 0});
}
