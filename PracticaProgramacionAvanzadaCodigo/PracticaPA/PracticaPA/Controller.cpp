#include "Controller.h"
#include <iostream>

std::vector<Controller*> Controller::gameControllers = {};

Controller::Controller()
	:owner{ NULL },isEnabled{true}
{
	Controller::gameControllers.push_back(this);
}

Controller::~Controller()
{
	for (int i = 0; i < Controller::gameControllers.size(); ++i)
	{
		if (Controller::gameControllers[i] == this)
		{
			Controller::gameControllers[i] = Controller::gameControllers[Controller::gameControllers.size() - 1];
			Controller::gameControllers.pop_back();
			break;
		}
	}
}

void Controller::ProcessKeyPressed(unsigned char key, int x, int y)
{
	if (!isEnabled) { return; }
	std::cout << "Controller has received input\n";
}

void Controller::ProcessKeyReleased(unsigned char key, int x, int y)
{
	if (!isEnabled) { return; }
	std::cout << "Controller has received input\n";
}

void Controller::ProcessMouseMovement(int x, int y)
{
	if (!isEnabled) { return; }
	std::cout << "Controller has received input\n";
}

void Controller::ProcessMouseClick(int button, int state, int x, int y)
{
	if (!isEnabled) { return; }
	std::cout << "Controller has received input\n";
}

void Controller::ProcessSpecialKeyPressed(int key, int x, int y)
{
	if (!isEnabled) { return; }
	std::cout << "Controller has received input\n";
}
void Controller::ProcessSpecialKeyReleased(int key, int x, int y)
{
	if (!isEnabled) { return; }
	std::cout << "Controller has received input\n";
}

void Controller::Update()
{
	if (!isEnabled) { return; }
}