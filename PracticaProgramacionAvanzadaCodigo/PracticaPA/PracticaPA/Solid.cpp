#include "Solid.h"
#include <GL/glut.h>
#include <iostream>
#include "Scene.h"
#include "Time.h"

//Constructores:
Solid::Solid()
	:location{}, rotation{}, scale{ 1,1,1 }, color{}, hasCollision{true}, collisionRadius{1},owner{NULL},parentSceneIndex{-1}, SpeedMult{1}
{}

Solid::~Solid()
{}

Solid::Solid(Vector3D const& newLocation = Vector3D{}, Vector3D const& newRotation = Vector3D{}, Vector3D const& newScale = Vector3D{1,1,1}, Color const& newColor = Color{})
	:location{ newLocation }, rotation{ newRotation }, scale{ newScale }, color{ newColor }, hasCollision{ true }, collisionRadius{ 1 }, owner{ NULL }, parentSceneIndex{ -1 }, SpeedMult{1}
{}

Solid::Solid(Solid const& other)
:location{other.location},rotation{other.rotation},color{other.color}, hasCollision{ true }, collisionRadius{ 1 }, owner{ NULL }, parentSceneIndex{ -1 }, SpeedMult{1}
{}

//Métodos:
void Solid::beginRender()
{
	glPushMatrix();
	glTranslatef(this->getLocation().getX(), getLocation().getY(), getLocation().getZ());
	glRotatef(this->getRotation().getX(), 1, 0, 0);
	glRotatef(this->getRotation().getY(), 0, 1, 0);
	glRotatef(this->getRotation().getZ(), 0, 0, 1);
	glColor3f(this->getColor().getR(), this->getColor().getG(), this->getColor().getB());
	glScalef(this->getScale().getX(), this->getScale().getY(), this->getScale().getZ());
}

void Solid::endRender()
{
	glPopMatrix();
}

void Solid::Update(double dt)
{
	this->setLocation(this->getLocation() + this->linearSpeed * dt * SpeedMult);
	this->setRotation(this->getRotation() + this->rotationSpeed * dt);

	Scene* scene = Scene::gameScenes[this->getParentSceneIndex()];
	for (int i = 0; i < scene->getSceneObjects().size(); ++i)
	{
		Solid& current = *(scene->getSceneObjects()[i]);
		if (this->checkCollision(current))
		{
			collideWithSolid(current);
		}
	}

}

bool Solid::checkCollision(Solid &other)
{
	Vector3D direction = this->getLocation() - other.getLocation();
	float distance = direction.length();

	return (this!=&other) && (this->getHasCollision() && other.getHasCollision()) && (distance <= this->collisionRadius + other.collisionRadius);
}

void Solid::collideWithSolid(Solid& other)
{
	Vector3D direction = this->getLocation() - other.getLocation();
	float distance = direction.length();
	float length = this->getCollisionRadius() + other.getCollisionRadius() - distance;
	Vector3D normal = direction.normalize();
	this->setLocation(this->getLocation() + normal * length);
}