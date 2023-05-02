#include <string>
#include "pch.h"
#include "Robot.h"
#include "Helper.h"

using namespace std;

void Robot::Start() {
	printBlue("Robot start", true);
	updateMove = true;
	inMove = true;
}

void Robot::Stop() {
	printBlue("Robot stop", true);
	updateMove = true;
	inMove = false;
}

void Robot::Rotate(double angle) {
	string txt = "Robot rotate : " + to_string((int)angle);
	printBlue(txt, true);
	updateRotation = true;
	this->angle = angle;
}

void Robot::Print(bool enable) {

	printBlue("Robot print ", false);

	if (enable)
		printBlue("enable", true);
	else
		printBlue("disable", true);

	updatePrint = true;
	printEnable = enable;
}