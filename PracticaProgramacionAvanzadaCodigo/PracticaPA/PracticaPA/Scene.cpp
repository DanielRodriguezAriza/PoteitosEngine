#include "Scene.h"
#include <iostream>

std::vector<Scene*> Scene::gameScenes = {};

Scene::Scene()
:isActive{ true }, gameObjects{}
{}

Scene::~Scene()
{
	for (int i = 0; i < Scene::gameScenes.size(); ++i)
	{
		if (Scene::gameScenes[i] == this)
		{
			Scene::gameScenes[i] = Scene::gameScenes[Scene::gameScenes.size() - 1];
			Scene::gameScenes.pop_back();
			break;
		}
	}
}

void Scene::Init()
{
	Scene::gameScenes.push_back(this);
}

void Scene::Render()
{
	for (auto obj : this->gameObjects)
	{
		obj->Render();
	}
}

void Scene::Update(double dt)
{
	for (auto obj : this->gameObjects)
	{
		obj->Update(dt);
	}
}


int Scene::getSceneIndex()
{
	for (int i = 0; i < Scene::gameScenes.size(); ++i)
	{
		if (Scene::gameScenes[i] == this)
		{
			return i;
		}
	}
	return -1;
}

void Scene::addObject(Solid* elem)
{
	elem->setParentSceneIndex(this->getSceneIndex());
	gameObjects.push_back(elem);
}

void Scene::removeObject(Solid* elem)
{
	for (int i = 0; i < this->gameObjects.size(); ++i)
	{
		if (this->gameObjects[i] == elem)
		{
			delete this->gameObjects[i];
			this->gameObjects[i] = this->gameObjects[this->gameObjects.size() - 1];
			this->gameObjects.pop_back();
			break;
		}
	}
}