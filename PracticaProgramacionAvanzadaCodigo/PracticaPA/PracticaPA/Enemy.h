#pragma once
#include "Solid.h"
#include "Model.h"
#include "ModelLoader.h"

class Enemy : public Solid
{
public:
	Enemy();
	Enemy(Vector3D const &spawnPos);
	Enemy(Vector3D const& spawnPos, Model const& enemyModel); //para realizar una precarga del modelo del enemigo y evitar realizar una lectura de archivo en cada spawn.

	void Render() override;
	void Update(double dt) override;
	void collideWithSolid(Solid& other) override;

	~Enemy();

public:

	static int numEnemies;
	static Model preloadedEnemyModel;

private:
	Model enemyModel;

};