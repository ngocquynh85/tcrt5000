#ifndef tcrt5000_h
#define tcrt5000_h
#endif

#define OFF			0
#define ON			1
//Object possition with respectto the sensor
#define FAR			0	// Far from the sensor
#define NEAR		1	// Near the sensor
//Object direction with respect to the sensor
#define INCOMING	1	// Incoming to the sensor
#define OUCOMING	0	// Going away from the sensor
//Input logic - positive or negative
#define POSITIVE	1	// Pulldown resistor HIGH on the Rx pin if object is NEAR Vcc -> Collector / Emitter -> pin
#define NEGATIVE	0	// Pullup resistor    LOW on the Rx pin if object is NEAR GND -> Collector / Emitter -> pin 
//Tx connection and control
#define ANODE		1	//If ANODE is connected to arduino	PIN -> ANODE -> Cathode -> GND
#define CATHODE		0	//If CHATODE is connected to arduino    Vcc -> CHATODE -> Anode -> PIN

// Use this class to start the sensor in distance measurement mode - report Far/Near objects, and direction - incoming (to the sensor) or outcoming (from thesensor)

class tcrt5000Distance {
private:
  unsigned int distance;
  
  char pRx;
  char pTx;
  bool rxUp;
  bool txOn;
  bool status; 	//Snesor may be switched on/off - by default it is off and should call .begin() to start
public:
  //Constructor for class tcrt5000Distance 
  // Input:	pinTx 		- number of the pin where the Emitting diode is connected
  //		connection 	- connection of of the LED - ANODE or CATHODE to arduino
  //		pinRx 		- number of the pin where receiving fototransistor is connected -
  //		logic 		- POSITIVE or NEGATIVE logic (Pulldown or pullup schematic)
  tcrt5000Distance(char pinTx, bool connection, char pinRx, bool logic);
  //Start the sensor - else Tx is off
#ifdef DEBUG
  void debug();
#endif
//void begin(void): Turn TCRT5000 on. Should be called in setup() to start measurement.
  void begin(void);
//void end(void): Turn TCRT5000 off. 
  void end(void);
//bool isNear(): Detects if there is an object near the the sensor.
//returns: (NEAR) TRUE  - if object is near the sensor
//         (FAR)  FALSE - if object is far from the sensor
  bool isNear(void);
//int getDistance(void): returns integer - how near the object is to the sensor. 
//requerments:  Tx should be connected to a analog pin  
 unsigned int getDistance(void);
};

