#include <string>
#include "pch.h"
#include "Application.h"

using namespace std;

void Robot::Start() {
	std::cout << "Robot Start" << std::endl;
	updateMove = true;
	inMove = true;
}

void Robot::Stop() {
	std::cout << "Robot Stop" << std::endl;
	updateMove = true;
	inMove = false;
}

void Robot::Rotate(double angle) {
	std::cout << "Robot rotate : " << (int)angle << std::endl;
	updateRotation = true;
	this->angle = angle;
}

void Robot::Print(bool enable) {

	std::cout << "Robot print : ";

	if (enable)
		std::cout << "enable" << std::endl;
	else
		std::cout << "disable" << std::endl;

	updatePrint = true;
	printEnable = enable;
}