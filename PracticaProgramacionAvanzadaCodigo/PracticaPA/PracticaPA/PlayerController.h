#pragma once
#include "Controller.h"
#include "InputKey.h"

class PlayerController : public Controller
{
public:
	PlayerController();

	void ProcessKeyPressed(unsigned char key, int x, int y);
	void ProcessKeyReleased(unsigned char key, int x, int y);
	void ProcessSpecialKeyPressed(int key, int x, int y);
	void ProcessSpecialKeyReleased(int key, int x, int y);

	void Update();

	inline float const getAxisX() const { return this->axisX; }
	inline float const getAxisY() const { return this->axisY; }

	void setUseSpecialKeys(bool b);
	inline bool const getUseSpecialKeys() const { return this->usesSpecialKeys; }

private:

	bool usesSpecialKeys;
	InputKey upKey, downKey, rightKey, leftKey, shootKey;
	float axisX, axisY;

};