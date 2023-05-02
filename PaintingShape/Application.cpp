#include "pch.h"
#include "Helper.h"
#include "Application.h"

using namespace std;

Application::Application() {
	inProgress = true; 
}

void Application::Config() {
	// Set list of shapes
	printGreen("Configuration de l'application", true);	
	
	// Create shapes
	// Vous devez faire mieux que cela
	formes[0] = new Forme();
	formes[1] = new Forme();
	state = State::new_forme;
}

// call every 100 ms
void Application::Execute() {
	
	// State machine example
	switch (state) {
	case State::wait:
		break;

	case State::new_forme:
	{
		const string s = "Start forme : " + to_string(forme_id);
		printBlue(s, true);
		im.createInstruction();
		im.start();
		forme_id++;
		state = State::drawing;
		break;
	}

	case State::drawing:
		im.executeStateMachine();
		if (!im.isInProgress()) {
			state = State::end_forme;
		}
		break;

	case State::end_forme:
		if (forme_id >= 2)
			state = State::end_application;
		else
			state = State::new_forme;

		break;

	case State::end_application:
		inProgress = false;
		break;
	}

	return;

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