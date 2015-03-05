#include "tcrt5000.h"
#include "Arduino.h"

tcrt5000Distance::tcrt5000Distance(char pinTx, bool connection, char pinRx, bool logic) {
	//Set how LED is turned on and when Rx is ON
	txOn = connection;
	rxUp = logic;
	status = OFF;
	pTx = pinTx;
	pRx = pinRx;
	distance = 0;
	//Set hardware pin directions
	pinMode(pTx, OUTPUT);
	digitalWrite(pTx,!txOn); //turn off emitter
	pinMode(pRx, INPUT);
	
	#ifdef DEBUG
		Serial.print("TCRT5000: Inited at TX ");
	#endif
};

//This function iscompiled only in DEBUG mode
#ifdef DEBUG
void tcrt5000Distance::debug() {
	Serial.println("***TCRT5000 DEBUG MSGS***");
	Serial.print("Tx pin: ");
	Serial.println((int)pTx);
	Serial.print("Tx on: ");
	Serial.println((int)txOn);
	Serial.print("Rx pin: ");
	Serial.println((int)pRx);
	Serial.print("Rx up: ");
	Serial.println((int)rxUp);
	Serial.print("Status: ");
	Serial.println((int)status);
}
#endif

void tcrt5000Distance::begin(void) {
	status = ON;
	digitalWrite(this->pTx, this->txOn);	//Activate IR LED
	#ifdef DEBUG
		Serial.print("TCRT5000: Started......");
	#endif
};

void tcrt5000Distance::end(void) {
	status = OFF;
	digitalWrite(pTx, !txOn);
	#ifdef DEBUG
		Serial.println("TCRT5000: Stopped!");
	#endif
};

bool tcrt5000Distance::isNear(void) {
	if(status == OFF) return 0;
	
	if(digitalRead(pRx) == rxUp) {
		#ifdef DEBUG
			Serial.println("TCRT5000: Object is NEAR the sensor");
		#endif
		return NEAR;
	} else {
		#ifdef DEBUG
			Serial.println("TCRT5000: Object is FAR the sensor");
		#endif
		return FAR;
	}
};

unsigned int tcrt5000Distance::getDistance(void) {
	if(status == OFF) return 0;
	
	return analogRead(pRx);
};

//#####################################################################
