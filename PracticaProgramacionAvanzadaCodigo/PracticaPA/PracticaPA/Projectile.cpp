#include "Projectile.h"
#include "Scene.h"

Projectile::Projectile()
	:Solid{}, projectileModel{}, startLocation{},maxDistance{500}
{
	ModelLoader loader;
	loader.loadModel("../../Assets/Models/bullet01.obj");

	projectileModel.setModel(loader.getModel());

	this->setLinearSpeed({0,0,-2});
	this->setRotationSpeed({0,100,0});
	this->setCollisionRadius(3);

	projectileModel.paintColorIndex({.5,.5,.5},0);
	projectileModel.paintColorIndex({1,0,0},1);
	projectileModel.paintColorIndex({.8,.2,0},2);

	this->setSpeedMult(100);
	
}

Projectile::Projectile(Vector3D const &spawnPos)
:Projectile{}
{
	this->setLocation(spawnPos);
	this->projectileModel.setLocation(this->getLocation());
}


void Projectile::Render()
{
	projectileModel.Render();
}

void Projectile::Update(double dt)
{
	Solid::Update(dt);
	projectileModel.setLocation(getLocation());
	projectileModel.setRotation(getRotation());

	if ((startLocation - getLocation()).length() >= maxDistance)
	{
		Scene::gameScenes[this->getParentSceneIndex()]->removeObject(this);
	}

}
