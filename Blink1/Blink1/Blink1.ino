/*
  The documentation at http://arduino.cc
 */

void setup() {
  pinMode(3, OUTPUT);
  pinMode(4, OUTPUT);
  pinMode(5, OUTPUT);
  pinMode(2, INPUT);
}

void ControlLights() {
	digitalWrite(5, HIGH);   // turn the LED on (HIGH is the voltage level)
	delay(1000);              // wait for a second
	digitalWrite(5, LOW);    // turn the LED off by making the voltage LOW
	delay(1000);              // wait for a second

	digitalWrite(4, HIGH);   // turn the LED on (HIGH is the voltage level)
	delay(1000);              // wait for a second
	digitalWrite(4, LOW);    // turn the LED off by making the voltage LOW
	delay(1000);

	digitalWrite(3, HIGH);   // turn the LED on (HIGH is the voltage level)
	delay(1000);              // wait for a second
	digitalWrite(3, LOW);    // turn the LED off by making the voltage LOW
	delay(1000);
}

void loop() {
		while (true) {
		int switchstate = digitalRead(2);
		if (switchstate == HIGH) {
			ControlLights();
		}
	}
}
