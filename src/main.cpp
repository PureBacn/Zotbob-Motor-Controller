#include <Arduino.h>
#include "config.h"

void setup() {
	Serial.begin(115200);
	pinMode(LED_BUILTIN, OUTPUT);
}

void loop() {
	int stateA = digitalReadFast(EncLeftA);
	int stateB = digitalReadFast(EncLeftB);

	Serial.println("A: " + String(stateA) + ", B: " + String(stateB));
	delay(10);
}