#include "positionController.h"

PositionController::PositionController()
{
	initialize();
}

PositionController::~PositionController()
{
}

void PositionController::initialize()
{

}

void PositionController::update_coordinate()
{
	this->cur_latitude = gps_instance->get_latitude();
	this->cur_longitude = gps_instance->get_longitude();
	if (cur_latitude == 0) { is_gps_measure_success = false; }
	else { is_gps_measure_success = true; }
}

void PositionController::clac_target_bearing()
{
	double deltaLon = longitudes[target_waypoint] - cur_longitude;
	double y = sin(deltaLon)*cos(latitudes[target_waypoint]);
	double x = cos(cur_latitude)*sin(latitudes[target_waypoint]) - sin(cur_latitude)*cos(latitudes[target_waypoint])*cos(deltaLon);
	
	float raw_bearing = atan2(y, x) * 180 / M_PI;
	target_bearing = (int)(raw_bearing +360) % 360;
}

void PositionController::update_altitude()
{
	altitude = gy86.getAltitude();
}

void PositionController::update_heading()
{
	cur_bearing = gy86.getHeading();
}
