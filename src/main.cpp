#include <Arduino.h>
#include "config.h"

volatile int leftEncoderP = 0;

void readEncoder() {
	int stateA = digitalReadFast(EncLeftA);
	int stateB = digitalReadFast(EncLeftB);

	if (stateA == stateB) {
		leftEncoderP++;
	} else {
		leftEncoderP--;
	}
}

void setup() {
	Serial.begin(115200);
	pinMode(LED_BUILTIN, OUTPUT);
	attachInterrupt(digitalPinToInterrupt(EncLeftA), readEncoder, CHANGE);
}

void loop() {
	noInterrupts();
	int leftP = leftEncoderP;
	interrupts();

	Serial.println("Pos:" + String(leftP));
	delay(10);
}