#pragma once

class Robot {
public:
	void Print(bool enable);
	void Start();
	void Stop();
	void Rotate(double angle);
	bool IsInMove() { return inMove; }
	double GetAngle() { return angle; }
	
	// Do not use or modify below functions
	bool UpdateRotate() { return updateRotation; }
	bool UpdateMove() { return updateMove; }
	void ClearRotate() { updateRotation = false; }
	void ClearMove() { updateMove = false; }
	bool updatePrint = false;
	bool printEnable = false;

private:
	bool updateRotation = false;
	bool updateMove = false;
	bool inMove = false;
	double angle = 0;
};

class Application {
public:
	Application();

	void Execute();
	bool IsInProgress() { return inProgress; }

	Robot robot;

private:
	bool inProgress;
};