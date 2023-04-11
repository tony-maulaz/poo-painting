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

Application::Application() {
	inProgress = true; 
}

// call evry 100 ms
void Application::Execute() {
	
	static int cpt = 0;

	if (cpt == 1)
		robot.Print(true);

	if (cpt == 20)
		robot.Start();

	if (cpt == 40)
		robot.Rotate(45);

	if(cpt == 50)
		robot.Print(false);

	if (cpt == 60) {
		robot.Print(true);
		robot.Rotate(270);
	}

	if (cpt == 80) {
		robot.Print(true);
		robot.Rotate(180);
	}

	if (cpt == 130)
		robot.Print(false);

	if (cpt == 200) {
		robot.Stop();
	}

	if (cpt == 210)
		inProgress = false;

	cpt++;
}