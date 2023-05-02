#pragma once
#include <string>
#include <iostream>
#include <queue>
#include <memory>
#include "Forme.h"
#include "Instruction.h"
#include "Robot.h"

class Application {
public:
	Application();

	void Config();

	void Execute();
	bool IsInProgress() { return inProgress; }

	Robot robot;
	InstructionManager im{ robot };

	Forme* formes[2]; // A vous de faire mieux pour gérer les formes
	int forme_id = 0;
	
private:
	enum class State {
		wait,
		new_forme,
		drawing,
		end_forme,
		end_application
	};
	
	bool inProgress;
	State state{ State::wait };
};