#pragma once
#include "Solid.h"
#include "Camera.h"
#include "Scene.h"
#include "Model.h"
#include "ModelLoader.h"
#include "PlayerController.h"
#include <vector>

class Player : public Solid
{
public:

	Player();
	~Player();

	void Render() override;
	void Update(double dt) override;
	void collideWithSolid(Solid &other) override;

	inline PlayerController& getPlayerController() { return this->playerController; }
	inline PlayerController const & getPlayerController() const { return this->playerController; }

	void Shoot();

	void setPlayerColor(Color const& newColor);

	inline int getPlayerScore() const { return this->playerScore; }
	inline void setPlayerScore(int newScore) { this->playerScore = newScore; }

	inline bool getIsAlive() const { return this->isAlive; }
	inline void setIsAlive(bool newAlive) { this->isAlive = newAlive; }

public:

	static std::vector<Player*> playerList;

private:

	Model playerMesh;
	PlayerController playerController;
	int playerScore;
	bool isAlive;
};