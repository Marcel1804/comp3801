#include <stdio.h>

#define SENSOR_LIMIT 2.60	// maximum reading distance of sensor in meters
#define LEFT_SECTION 0
#define RIGHT_SECTION 1
#define FRONT_SECTION 2
#define BACK_SECTION 3
#define FpinBuzzer 5
#define BUZZER_PIN FpinBuzzer


// global variables

//previous times
unsigned long prevTime[4] = { 0 };
// previous speeds
float prevDistance[4] = { 0.0f };
// jump filter
bool prevSignal[4] = { false };

// front section
int FpinRL = 4;
int FpinGL = 3;
int FpinUSecho = 9;
int FpinUStri = 13;

// left section 
int LpinRL = A0;          //Analog pin
int LpinGL = A3;          //Analog pin
int LpinUSecho = 8;
int LpinUStri = 12;

// right section
int RpinRL = A1;          //Analog pin
int RpinGL = A4;          //Analog pin
int RpinUSecho = 7;
int RpinUStri = 11;

// back section
int BpinRL = A2;          //Analog pin
int BpinGL = A5;          //Analog pin
int BpinUSecho = 6;
int BpinUStri = 10;

void setup()
{
	Serial.begin(9600);

	// buzzer
	pinMode(FpinBuzzer, OUTPUT);

	//front  board
	pinMode(FpinUStri, OUTPUT);
	pinMode(FpinUSecho, INPUT);
	pinMode(FpinGL, OUTPUT);
	pinMode(FpinRL, OUTPUT);

	//left  board
	pinMode(LpinUStri, OUTPUT);
	pinMode(LpinUSecho, INPUT);
	pinMode(LpinGL, OUTPUT);
	pinMode(LpinRL, OUTPUT);

	//rigth board
	pinMode(RpinUStri, OUTPUT);
	pinMode(RpinUSecho, INPUT);
	pinMode(RpinGL, OUTPUT);
	pinMode(RpinRL, OUTPUT);

	//back board
	pinMode(BpinUStri, OUTPUT);
	pinMode(BpinUSecho, INPUT);
	pinMode(BpinGL, OUTPUT);
	pinMode(BpinRL, OUTPUT);
}

void loop()
{
	double distance = 0.0f;
	float _time = 0.0f;
	float velc = 0.0f;
	unsigned long curTime = 0;
	bool s = false;

	// clear pin signals
	ResetAllPins();

	//front  board
	distance = ReadSensor(FpinUStri, FpinUSecho);
	if (distance < 0) {
		digitalWrite(FpinGL, LOW);
		digitalWrite(FpinRL, HIGH);
		Serial.println("Front section has echo.");
	}
	else {
		curTime = millis();
		_time = (float)(curTime - prevTime[FRONT_SECTION]) / 1000;
		velc = (prevDistance[FRONT_SECTION] - distance) / _time;
		prevDistance[FRONT_SECTION] = distance;
		prevTime[FRONT_SECTION] = curTime;
		/*Serial.print("distance[Front]: ");
		Serial.print(distance);
		Serial.println(" meters");
		Serial.print("velocity[Front]: ");
		Serial.print(velc);
		Serial.println(" m/s");*/
		if (distance <= 0.5 && velc >= 0.2) {
			s = true;
			if (s and prevSignal[FRONT_SECTION]) {
				tone(BUZZER_PIN, 500, 200);
			}
			//Serial.println("back CONTINUEOUS side trigger");
		}
		else if (distance < 1 && velc > 0.2) {
			s = true;
			if (s and prevSignal[FRONT_SECTION]) {
				tone(BUZZER_PIN, 500, 50);
			}
			//Serial.println("back side trigger");
		}
		prevSignal[FRONT_SECTION] = s;
	}

	//left  board
	s = false;
	distance = ReadSensor(LpinUStri, LpinUSecho);
	if (distance < 0) {
		digitalWrite(LpinGL, LOW);
		digitalWrite(LpinRL, HIGH);
		Serial.println("Left section has echo.");
	}
	else {
		curTime = millis();
		_time = (float)(curTime - prevTime[LEFT_SECTION]) / 1000;
		velc = (prevDistance[LEFT_SECTION] - distance) / _time;
		prevDistance[LEFT_SECTION] = distance;
		prevTime[LEFT_SECTION] = curTime;
		/*Serial.print("distance[Left]: ");
		Serial.print(distance);
		Serial.println(" meters");
		Serial.print("velocity[Left]: ");
		Serial.print(velc);
		Serial.println(" m/s");*/
		if (distance <= 0.5 && velc >= 0.2) {
			s = true;
			if (s and prevSignal[LEFT_SECTION]) {
				tone(BUZZER_PIN, 900, 200);
			}
			//Serial.println("back CONTINUEOUS side trigger");
		}
		else if (distance < 1 && velc > 0.2) {
			s = true;
			if (s and prevSignal[LEFT_SECTION]) {
				tone(BUZZER_PIN, 900, 50);
			}
			//Serial.println("back side trigger");
		}
		prevSignal[LEFT_SECTION] = s;
	}

	//rigth board
	s = false;
	distance = ReadSensor(RpinUStri, RpinUSecho);
	if (distance < 0) {
		digitalWrite(RpinGL, LOW);
		digitalWrite(RpinRL, HIGH);
		Serial.println("Right section has echo.");
	}
	else {
		curTime = millis();
		_time = (float)(curTime - prevTime[RIGHT_SECTION]) / 1000;
		velc = (prevDistance[RIGHT_SECTION] - distance) / _time;
		prevDistance[RIGHT_SECTION] = distance;
		prevTime[RIGHT_SECTION] = curTime;
		/*Serial.print("distance[Right]: ");
		Serial.print(distance);
		Serial.println(" meters");
		Serial.print("velocity[Right]: ");
		Serial.print(velc);
		Serial.println(" m/s");*/
		if (distance <= 0.5 && velc >= 0.2) {
			s = true;
			if (s and prevSignal[RIGHT_SECTION]) {
				tone(BUZZER_PIN, 1500, 200);
			}
			//Serial.println("back CONTINUEOUS side trigger");
		}
		else if (distance < 1 && velc > 0.2) {
			s = true;
			if (s and prevSignal[RIGHT_SECTION]) {
				tone(BUZZER_PIN, 1500, 50);
			}
			//Serial.println("back side trigger");
		}
		prevSignal[RIGHT_SECTION] = s;
	}

	//back board
	s = false;
	distance = ReadSensor(BpinUStri, BpinUSecho);
	if (distance < 0) {
		digitalWrite(BpinGL, LOW);
		digitalWrite(BpinRL, HIGH);
		Serial.println("Back section has echo.");
	}
	else {
		curTime = millis();
		_time = (float)(curTime - prevTime[BACK_SECTION]) / 1000;
		velc = (prevDistance[BACK_SECTION] - distance) / _time;
		prevDistance[BACK_SECTION] = distance;
		prevTime[BACK_SECTION] = curTime;
		/*Serial.print("distance[Back]: ");
		Serial.print(distance);
		Serial.println(" meters");
		Serial.print("velocity[Back]: ");
		Serial.print(velc);
		Serial.println(" m/s");*/
		if (distance <= 0.5 && velc >= 0.2) {
			s = true;
			if (s and prevSignal[BACK_SECTION]) {
				tone(BUZZER_PIN, 3500, 200);
			}
			//Serial.println("back CONTINUEOUS side trigger");
		}
		else if (distance < 1 && velc > 0.2) {
			s = true;
			if (s and prevSignal[BACK_SECTION]) {
				tone(BUZZER_PIN, 3500, 50);
			}
			//Serial.println("back side trigger");
		}
		prevSignal[BACK_SECTION] = s;
	}

	delay(50);
}

// sets all output and input pins to the connected devices to low
void ResetAllPins(void)
{
	// sensor triggers
	digitalWrite(FpinUStri, LOW);
	digitalWrite(LpinUStri, LOW);
	digitalWrite(RpinUStri, LOW);
	digitalWrite(BpinUStri, LOW);

	// sensor echos
	digitalWrite(FpinUSecho, LOW);
	digitalWrite(LpinUSecho, LOW);
	digitalWrite(RpinUSecho, LOW);
	digitalWrite(BpinUSecho, LOW);

	// lights
	digitalWrite(FpinGL, LOW);
	digitalWrite(FpinRL, LOW);
	analogWrite(LpinGL, LOW);
	analogWrite(LpinRL, LOW);
	analogWrite(RpinGL, LOW);
	analogWrite(RpinRL, LOW);
	analogWrite(BpinGL, LOW);
	analogWrite(BpinRL, LOW);

	// buzzer
	//digitalWrite(BUZZER_PIN, LOW);
}

// returns the distance read from the sensor in meters.
double ReadSensor(int sensorTrig, int sensorEcho)
{
	double result = 0.0f;
	digitalWrite(sensorTrig, LOW);
	delayMicroseconds(2);
	digitalWrite(sensorTrig, HIGH);
	delayMicroseconds(10);
	digitalWrite(sensorTrig, LOW);
	result = pulseIn(sensorEcho, HIGH);
	result = (result / 58.2) / 100;
	if (result > SENSOR_LIMIT) {
		result = -1.0f;
	}

	return result;
}
