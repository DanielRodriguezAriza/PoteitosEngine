#pragma once
#include "Vector3D.h"
#include "Color.h"

class Solid
{
public:

	Solid();
	Solid(Vector3D const &newLocation, Vector3D const& newRotation, Vector3D const &newScale, Color const &newColor);
	Solid(Solid const &other);

	inline Vector3D const& getLocation() const { return this->location; }
	inline Vector3D const& getRotation() const { return this->rotation; }
	inline Vector3D const& getScale() const { return this->scale; }
	inline Color const& getColor() const { return this->color; }

	inline void setLocation(Vector3D const& newLocation) { this->location = newLocation; }
	inline void setRotation(Vector3D const& newRotation) { this->rotation = newRotation; }
	inline void setScale(Vector3D const& newScale) { this->scale = newScale; }
	inline void setColor(Color const& newColor) { this->color = newColor; }

	virtual void Render() = 0;
	virtual void Update(double dt);

	inline void setLinearSpeed(Vector3D const& newLinearSpeed) { this->linearSpeed = newLinearSpeed; }
	inline void setRotationSpeed(Vector3D const& newRotationSpeed) { this->rotationSpeed = newRotationSpeed; }

	inline Vector3D const& getLinearSpeed() const { return this->linearSpeed; }
	inline Vector3D const& getRotationSpeed() const { return this->rotationSpeed; }

	bool checkCollision(Solid &other);
	virtual void collideWithSolid(Solid &other);

	inline float const& getCollisionRadius() const { return this->collisionRadius; }
	inline void setCollisionRadius(float newRadius) { this->collisionRadius = newRadius; }

	inline bool const& getHasCollision() const { return this->hasCollision; }
	inline void setHasCollision(bool newCollision) { this->hasCollision = newCollision; }

	inline void *getOwner() const { return this->owner; }
	inline void setOwner(void *newOwner) { this->owner = newOwner; }

	inline int getParentSceneIndex() const { return this->parentSceneIndex; }
	inline void setParentSceneIndex(int idx) { this->parentSceneIndex = idx; }

	inline float getSpeedMult() const { return this->SpeedMult; }
	inline void setSpeedMult(float newSpeedMult) { this->SpeedMult = newSpeedMult; }

	virtual ~Solid();

protected:

	Vector3D location;
	Vector3D rotation;
	Vector3D scale;
	Color color;

	Vector3D linearSpeed;
	Vector3D rotationSpeed;

	float SpeedMult;

	bool hasCollision;
	float collisionRadius;

	void* owner;
	int parentSceneIndex;

	void beginRender();
	void endRender();

};