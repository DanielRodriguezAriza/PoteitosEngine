#include "Player.h"
#include "Scene.h"
#include "Projectile.h"
#include "Math.h"
#include "Scene.h"

std::vector<Player*> Player::playerList = {};

Player::Player()
:Solid{}, playerMesh{}, playerController{},playerScore{0},isAlive{true}
{
	Player::playerList.push_back(this);

	ModelLoader loader;
	loader.loadModel("../../Assets/Models/nave01.obj");

	playerMesh.setModel(loader.getModel());
	playerMesh.setScale(.3);
	playerMesh.paintColorIndex({ 1,0,0 }, 0);
	playerMesh.paintColorIndex({ 0,0,0 }, 1);
	playerMesh.paintColorIndex({ 0,0,1 }, 2);

	playerController.setOwner(this);

	this->setCollisionRadius(3);

	this->setSpeedMult(40);
}

Player::~Player()
{
	Solid::~Solid();
	for (int i = 0; i < Player::playerList.size(); ++i)
	{
		if (this == Player::playerList[i])
		{
			Player::playerList[i] = Player::playerList[Player::playerList.size() - 1];
			Player::playerList.pop_back();
		}
	}
}

void Player::Render()
{
	if (!this->isAlive) { return; }
	this->playerMesh.Render();
}

void Player::Update(double dt)
{
	if (!this->isAlive) { this->setHasCollision(false); return; }

	this->setHasCollision(true);

	Solid::Update(dt);
	playerController.Update();

	playerMesh.setLocation(getLocation());
	playerMesh.setRotation(getRotation() + Vector3D{ 
		Math::clamp<float>(Math::lerp<float>(playerMesh.getRotation().getX(),25*playerController.getAxisY(),0.1f),-50,50),
		0,
		Math::clamp<float>(Math::lerp<float>(playerMesh.getRotation().getZ(),-25*playerController.getAxisX(),0.1f),-25,25)});

	setLinearSpeed({playerController.getAxisX(),playerController.getAxisY(),0});


	setLocation({ Math::clamp<float>(getLocation().getX(),-30,30),Math::clamp<float>(getLocation().getY(),-20,20),getLocation().getZ() });
}

void Player::Shoot()
{
	if (!this->isAlive) { return; }
	Projectile* p = new Projectile{ getLocation() + Vector3D{0,0,-10} };
	p->setOwner(this);
	Scene::gameScenes[this->getParentSceneIndex()]->addObject(p);
}

void Player::setPlayerColor(Color const& newColor)
{
	playerMesh.paintColorIndex(newColor,0);
}

void Player::collideWithSolid(Solid& other)
{
	if (!this->isAlive) { return; }

	Solid::collideWithSolid(other);
	this->setLocation({ this->getLocation().getX(),this->getLocation().getY(),0 });
}