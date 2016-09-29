/*
* Graduation Project [ Quad Copter ]
*/

#include "./controllers/droneController.h"
#include "./sensors/sonar/ultrasonic.h"

#include <iostream>
#include <wiringPi.h>
#include <string>
#include <thread>

#include "./sensors/filters.h"
#include "./sensors/gy-86/RPIGY86.h"

int main() {
	UltrasonicClass *sonar = UltrasonicClass::getInstance();
	//toNlanding *landing = toNlanding::getInstance();
	RPIGY86 a; 

	a.getPressure();
	
	while (1) {
		//b = a.getAltitude();
		//h = a.getHeading();
		//cout << "distance : " << b << " velocity : " << h<< endl;
		cout << "distance : " << sonar->getDistance() << endl;


		delay(5);
	}

	return 0;
}