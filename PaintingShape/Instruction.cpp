#include "pch.h"
#include "Instruction.h"

using namespace std;

// Instruction class
void Instruction::start() { cout << "  - Instruction start : " << duration << endl; }
void Instruction::end() {}
bool Instruction::execute() { return true; }


// Instruction manager class
InstructionManager::InstructionManager(Robot& r) : robot(r) {}

void InstructionManager::start() {
	if (instructions.size() > 0 && !inProgress)
		inProgress = true;
}

void InstructionManager::executeStateMachine() {
	if (!inProgress) {
		return;
	}

	unique_ptr<Instruction>& i = instructions.front();

	if (cptTime == 0) {
		cout << "Start new instruction" << endl;
		inProgress = true;
		i->start();
		cptTime++;
	}
	else if (cptTime >= i->duration) {
		cout << "End of instruction cpt : " << cptTime << endl;
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

void InstructionManager::createInstruction() {
	instructions.push(std::make_unique<Instruction>(5));
	instructions.push(std::make_unique<Instruction>(10));
	instructions.push(std::make_unique<Instruction>(15));
}