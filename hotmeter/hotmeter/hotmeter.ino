/*
 Name:		hotmeter.ino
 Created:	12/30/2018 7:46:00 PM
 Author:	Gorat
*/
//Temperature Sensor

const int SensorPin = A0;
const float BaselineTemp_Celcius = 25.0;

//Simulate "Power Switch"
bool Power;

// the setup function runs once when you press reset or power the board
void setup() {
	
	//Initialize PowerSwitch pin
	pinMode(9, INPUT);
	
	//Open Ports
	Serial.begin(9600);

	//Assign PinNumbers and init output
	for (int pinNumber = 2; pinNumber <= 5; pinNumber++) {
		pinMode(pinNumber, OUTPUT);
		digitalWrite(pinNumber, LOW);
	}
}

// the loop function runs over and over again until power down or reset
void loop() {

	int SwitchValue = digitalRead(9);

	if (SwitchValue == HIGH && Power == true)
		Power = false;
	else if (SwitchValue == HIGH && Power == false) {
		Power = true;
	}
	
	Serial.print("PowerSwitch value: ");
	Serial.println(SwitchValue);
	Serial.print("Power value: ");
	Serial.println(Power);


	if (Power == true) {

		int SensorValue = analogRead(SensorPin);
		Serial.print("Sensor Value: ");
		Serial.print(SensorValue);

		float Voltage = (SensorValue / 1024.0)*5.0;

		Serial.print(" , Volts: ");
		Serial.print(Voltage);

		float Celcius = (Voltage - .5) * 100;
		float Farenheit = (Celcius * 9.0) / 5.0 + 32;

		Serial.print(" , degrees C: ");
		Serial.print(Celcius);

		Serial.print(" , degrees F: ");
		Serial.println(Farenheit);

		if (Celcius < BaselineTemp_Celcius) {
			digitalWrite(2, LOW);
			digitalWrite(3, LOW);
			digitalWrite(4, LOW);
		}
		else if (Celcius >= BaselineTemp_Celcius + 2 && Celcius < BaselineTemp_Celcius + 4) {
			digitalWrite(2, HIGH);
			digitalWrite(3, LOW);
			digitalWrite(4, LOW);
		}
		else if (Celcius >= BaselineTemp_Celcius + 4 && Celcius < BaselineTemp_Celcius + 6) {
			digitalWrite(2, HIGH);
			digitalWrite(3, HIGH);
			digitalWrite(4, LOW);
		}
		else if (Celcius >= BaselineTemp_Celcius + 6) {
			digitalWrite(2, HIGH);
			digitalWrite(3, HIGH);
			digitalWrite(4, HIGH);
		}

		Serial.println("");
		Serial.println("");
		Serial.println("");
	}
	else if (Power == false) {
		Serial.println("The device is \"off\"");
		Serial.println("");
		Serial.println("");
		Serial.println("");
	}
}
