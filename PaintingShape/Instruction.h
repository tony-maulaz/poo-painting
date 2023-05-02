
#pragma once
//#include "pch.h"
#include <iostream>
#include <queue>
#include <memory>
#include "Robot.h"

struct Instruction {
	Instruction(int size) {
		duration = size * 4;
	}

	void start();
	void end();
	bool execute();

	int duration;
};

class InstructionManager {
public:
	InstructionManager(Robot& r);

	void start();

	void executeStateMachine();

	void createInstruction();

	bool isInProgress() { return inProgress; }
	
private:
	Robot& robot;
	std::queue<std::unique_ptr<Instruction>> instructions;

	int cptTime{ 0 };
	bool inProgress{ false };
};