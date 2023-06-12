#include "HealthPickUp.h"
#include "Player.h"

HealthPickUp::HealthPickUp(Vector3D const& newPos)
	:PickUp{ newPos }
{
	this->setPickUpModel("../../Assets/Models/Heart.obj");
	this->pickUpModel.paintColor({ 1,0,0 });
}

void HealthPickUp::Pick()
{
	for (Player* currentPlayer : Player::playerList)
	{
		currentPlayer->setIsAlive(true);
	}
}