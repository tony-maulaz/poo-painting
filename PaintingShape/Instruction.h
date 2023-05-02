
#pragma once
#include "Robot.h"
#include "pch.h"

using namespace std;

struct Instruction {
	Instruction(int size) {
		duration = size * 4;
	}

	void start() { }
	void end() {}
	bool execute() {}

	int duration;
};

class InstructionManager {
public:
	InstructionManager(Robot& r) {}

	void start() {
		if (instructions.size() > 0 && !inProgress)
			inProgress = true;
	}

	void executeStateMachine() {
		if (!inProgress) {
			return;
		}

		unique_ptr<Instruction>& i = instructions.front();

		if (cptTime == 0) {
			cout << "Start new instruction" << endl;
			inProgress = true;
			i->start();
		}
		else if (cptTime >= i->duration) {
			cout << "End of instruction" << endl;
			i->end();
			instructions.pop();
			cptTime = 0;

			if (instructions.size() == 0) {
				inProgress = false;
			}
		}
		else {
			i->execute();
			cptTime++;
		}
	}

	void createInstruction() {
		instructions.push( std::make_unique<Instruction>(10) );
		instructions.push( std::make_unique<Instruction>(20) );
		instructions.push( std::make_unique<Instruction>(30) );
	}

	Robot* r;
	std::queue<std::unique_ptr<Instruction>> instructions;

	int cptTime{ 0 };

	bool inProgress{ false };
};