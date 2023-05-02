#pragma once
#include <string>
#include <iostream>
#include <queue>
#include <memory>
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

private:
	bool inProgress;
};