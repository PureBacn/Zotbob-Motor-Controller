#include <Arduino.h>
#include "BTS7960.h"

void setup() {
	Serial.begin(115200);
	pinMode(LED_BUILTIN, OUTPUT);
}

void loop() {
	digitalWrite(LED_BUILTIN, HIGH);
	Serial.println("On");
	delay(1000);
	digitalWrite(LED_BUILTIN, LOW);
	Serial.println("Off");
	delay(1000);
}
