#include <string>
#include "pch.h"
#include "Helper.h"

using namespace std;

Application::Application() {
	inProgress = true; 
}

void Application::Config() {
	// Set list of shapes
	printGreen("Configuration de l'application", true);
}

// call every 100 ms
void Application::Execute() {
	
	static int cpt = 0;

	if (cpt == 1)
		robot.Print(true);

	if (cpt == 20) {
		robot.Rotate(0);
		robot.Start();
	}

	if (cpt == 40)
		robot.Rotate(45);

	if(cpt == 50)
		robot.Print(false);

	if (cpt == 60) {
		robot.Print(false);
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