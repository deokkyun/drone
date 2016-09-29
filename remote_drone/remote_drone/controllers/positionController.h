#ifndef _POSITIONCONTROLLER_H_
#define _POSITIONCONTROLLER_H_

#include "../singleton.hpp"
#include "pid.h"
#include "DroneController.h"
#include "../sensors/gy-86/RPIGY86.h"
#include "../sensors/gps/gps.h"
#include <cmath>
#define _USE_MATH_DEFINES


class PositionController : public singleton <PositionController>{
private:
	PID alti_1st_pid, alti_2nd_pid;

	bool is_gps_measure_success;
	double cur_latitude, cur_longitude;
	double *latitudes, *longitudes;
	unsigned short cnt_waypoint, target_waypoint;
	unsigned short target_bearing;
	unsigned short cur_bearing;

	//airpress part
	float altitude;

	gps *gps_instance;
	RPIGY86 gy86;

private:
	PositionController();
	~PositionController();
	void initialize();

	void update_coordinate();
	void clac_target_bearing();
	
	void update_altitude();
	void update_heading();

};

#endif