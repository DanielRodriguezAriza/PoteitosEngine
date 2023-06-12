#pragma once
#include "Solid.h"
#include "Controller.h"
#include <vector>

class Scene
{
public:

	Scene();
	~Scene();

	virtual void Init();
	virtual void Render();
	virtual void Update(double dt);

	//virtual void ProcessKeyPressed(unsigned char key, int x, int y);
	//virtual void ProcessMouseMovement(int x, int y);
	//virtual void ProcessMouseClick(int button, int state, int x, int y);



	void addObject(Solid* elem);
	void removeObject(Solid* elem);

	inline bool const getIsActive() const { return this->isActive; }
	inline void setIsActive(bool const& newActive) { this->isActive = newActive; }

	std::vector<Solid*> const &getSceneObjects() const { return gameObjects; }
	std::vector<Solid*> &getSceneObjects() { return gameObjects; }

	int getSceneIndex();

public:

	static std::vector<Scene*> gameScenes;

private:

	bool isActive;
	std::vector<Solid*> gameObjects;

};