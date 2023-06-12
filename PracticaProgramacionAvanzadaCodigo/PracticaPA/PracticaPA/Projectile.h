#pragma once
#include "Solid.h"
#include "Model.h"
#include "ModelLoader.h"

class Projectile : public Solid
{
public:

	Projectile();
	Projectile(Vector3D const &spawnPos);

	void Render() override;
	void Update(double dt) override;

private:

	Model projectileModel;
	Vector3D startLocation;
	float maxDistance;
};