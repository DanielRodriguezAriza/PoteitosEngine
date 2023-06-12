#pragma once
#include <vector>
#include "InputKey.h"

class Controller
{
public:
	Controller();
	~Controller();

	virtual void ProcessKeyPressed(unsigned char key, int x, int y);
	virtual void ProcessKeyReleased(unsigned char key, int x, int y);
	virtual void ProcessMouseMovement(int x, int y);
	virtual void ProcessMouseClick(int button, int state, int x, int y);
	virtual void ProcessSpecialKeyPressed(int key, int x, int y);
	virtual void ProcessSpecialKeyReleased(int key, int x, int y);

	virtual void Update();

	inline void* getOwner() const { return this->owner; }
	inline void setOwner(void* newOwner) { this->owner = newOwner; }

	inline bool getIsEnabled() const { return this->isEnabled; }
	inline void setIsEnabled(bool newEnabled) { this->isEnabled = newEnabled; }

public:
	static std::vector<Controller*> gameControllers;

protected:
	void* owner;
	bool isEnabled;

};