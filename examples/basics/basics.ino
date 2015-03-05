#include <tcrt5000.h>

tcrt5000Distance s1(4,ANODE,2,POSITIVE);

void setup() {
  // put your setup code here, to run once:
  Serial.begin(115200);
  s1.begin();
}

void loop() {
  // put your main code here, to run repeatedly:
bool isNear = false;

	isNear = s1.isNear();
  if(isNear) {
  	Serial.println("|---*");
  }
  else {
    Serial.println("|-----------*");
  }

  
  delay(500);
}
