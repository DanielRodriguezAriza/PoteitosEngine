#include "Enemy.h"
#include "Player.h"
#include <iostream>
#include "Random.h"
#include "Projectile.h"

int Enemy::numEnemies = 0;
Model Enemy::preloadedEnemyModel = { "../../Assets/Models/nave02.obj" };

Enemy::Enemy()
	:Solid{},enemyModel {}
{
	this->setScale(0);

	ModelLoader loader;
	loader.loadModel("../../Assets/Models/nave02.obj");

	this->enemyModel.setModel(loader.getModel());
	this->enemyModel.paintColorIndex({Random::getRand<float>(0,1),Random::getRand<float>(0,1),Random::getRand<float>(0,1) }, 0);

	
	this->setCollisionRadius(5);
	this->setLinearSpeed({0,0,5});

	this->setSpeedMult(80);

	++Enemy::numEnemies;
}

Enemy::Enemy(Vector3D const& spawnPos)
:Enemy{}
{
	this->setLocation(spawnPos);
	this->enemyModel.setLocation(spawnPos);
}

Enemy::Enemy(Vector3D const& spawnPos, Model const& model)
	:Solid{}, enemyModel{model}
{
	//spawn position
	this->setLocation(spawnPos);
	this->enemyModel.setLocation(spawnPos);


	//spawn model
	this->enemyModel.setModel(model);
	this->enemyModel.paintColorIndex({ Random::getRand<float>(0,1),Random::getRand<float>(0,1),Random::getRand<float>(0,1) }, 0);


	//spawn settings
	this->setScale(0);
	this->setCollisionRadius(5);
	this->setLinearSpeed({ 0,0,5 });
	this->setSpeedMult(80);

	//increase num enemies
	++Enemy::numEnemies;
}

Enemy::~Enemy()
{
	Solid::~Solid();
	--Enemy::numEnemies;
}

void Enemy::Render()
{
	this->enemyModel.Render();
}

void Enemy::Update(double dt)
{
	Solid::Update(dt);
	this->enemyModel.setLocation(this->getLocation());
	this->enemyModel.setRotation({0,180,0});
	this->enemyModel.setScale(this->getScale()*.8f);

	this->setScale(Math::lerp<Vector3D>(this->getScale(), 1, Math::clamp<double>(dt,0,1)));

	if (this->getLocation().getZ() >= 100)
	{
		Scene::gameScenes[this->getParentSceneIndex()]->removeObject(this);
	}
}

void Enemy::collideWithSolid(Solid& other)
{
	Solid::collideWithSolid(other);

	if (auto *player = dynamic_cast<Player*>(&other))
	{
		std::cout << "Enemy collides with player\n";
		player->setIsAlive(false);
	}
	else
	if(auto *projectile = dynamic_cast<Projectile*>(&other))
	{
		std::cout << "Enemy collides with bullet\n";

		if (other.getOwner() != NULL)
		{
			Player* player = ((Player*)(other.getOwner()));
			player->setPlayerScore(player->getPlayerScore()+100);
		}

		Scene::gameScenes[this->getParentSceneIndex()]->removeObject(this);
	}
	else
	{
		std::cout << "Enemy collides with non identified object.\n";
	}
}