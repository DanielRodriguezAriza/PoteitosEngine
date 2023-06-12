#include "PickUp.h"
#include "Player.h"
#include "Scene.h"

PickUp::PickUp()
	:Solid{}, pickUpModel{}
{
	this->setHasCollision(true);
	this->setCollisionRadius(2);

	this->pickUpModel.setOwner(this);
	this->setRotationSpeed({0,1,0});
	this->setLinearSpeed({0,0,1});

	setPickUpModel("../../Assets/Models/ObjetoPrueba.obj");

	this->setSpeedMult(100);
}

PickUp::PickUp(Vector3D const& newPos)
	:PickUp{}
{
	this->setLocation(newPos);
}

void PickUp::Render()
{
	this->pickUpModel.Render();
}

void PickUp::Update(double dt)
{
	Solid::Update(dt);
	this->pickUpModel.setLocation(this->getLocation());
	this->pickUpModel.setRotation(this->getRotation());
	this->pickUpModel.setScale(this->getScale());

	if (this->getLocation().getZ() > 100)
	{
		Scene::gameScenes[this->getParentSceneIndex()]->removeObject(this);
	}
}

void PickUp::collideWithSolid(Solid& other)
{
	if (auto* player = dynamic_cast<Player*>(&other))
	{
		this->Pick();
		Scene::gameScenes[this->getParentSceneIndex()]->removeObject(this);
	}
}

void PickUp::Pick()
{
	std::cout << "Item has been picked up! (default pickup behavior)\n";
}

void PickUp::setPickUpModel(std::string const& s)
{
	ModelLoader loader;
	loader.loadModel(s);
	this->pickUpModel.setModel(loader.getModel());
}