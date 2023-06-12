#include "Background.h"
#include "ColorLoader.h"

Background::Background()
	:Solid{}, backgroundModel{},backgroundSpeed{80,0,0}
{
	this->setHasCollision(false);
	this->backgroundModel.setHasCollision(false);
	this->backgroundModel.setLocation(this->getLocation());
	this->setRotationSpeed(backgroundSpeed);
}

void Background::loadBackground(std::string s)
{
	ModelLoader loader;
	loader.loadModel(s);
	this->backgroundModel.setModel(loader.getModel());
}

void Background::Render()
{
	this->backgroundModel.Render();
}

void Background::Update(double dt)
{
	Solid::Update(dt);
	this->setRotationSpeed(backgroundSpeed);
	this->backgroundModel.setLocation(this->getLocation());
	this->backgroundModel.setRotation(this->getRotation());
	this->backgroundModel.setScale(this->getScale());
}
