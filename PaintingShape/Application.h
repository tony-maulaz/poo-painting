#pragma once
#include "Robot.h"
#include "Instruction.h"

class Application {
public:
	Application();

	void Config();

	void Execute();
	bool IsInProgress() { return inProgress; }

	Robot robot;
	//InstructionManager im{ robot };

private:
	bool inProgress;
};