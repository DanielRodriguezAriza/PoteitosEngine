#include "PlayerController.h"
#include <iostream>
#include "Player.h"

PlayerController::PlayerController()
:usesSpecialKeys{ false }, axisX{0}, axisY{0}, upKey{}, downKey{}, leftKey{}, rightKey{}, shootKey{}
{
	this->setUseSpecialKeys(false);
}

void PlayerController::ProcessKeyPressed(unsigned char key, int x, int y)
{
	Controller::ProcessKeyPressed(key,x,y);
	std::cout << "KEY PRESSED\n";

	if (upKey.keyEquals(key))    { upKey.setIsPressed(true); }
	if (downKey.keyEquals(key))  { downKey.setIsPressed(true);}
	if (rightKey.keyEquals(key)) { rightKey.setIsPressed(true);}
	if (leftKey.keyEquals(key))  { leftKey.setIsPressed(true);}

	if (shootKey.keyEquals(key))
	{
		if (this->owner != NULL && !shootKey.getIsPressed())
		{
			((Player*)(owner))->Shoot();
		}
		shootKey.setIsPressed(true);
	}

}

void PlayerController::ProcessKeyReleased(unsigned char key, int x, int y)
{
	Controller::ProcessKeyReleased(key, x, y);
	std::cout << "KEY RELEASED\n";

	if (upKey.keyEquals(key)) { upKey.setIsPressed(false);}
	if (downKey.keyEquals(key)) { downKey.setIsPressed(false);}
	if (rightKey.keyEquals(key)) { rightKey.setIsPressed(false); }
	if (leftKey.keyEquals(key)) { leftKey.setIsPressed(false); }

	if (shootKey.keyEquals(key)) { shootKey.setIsPressed(false); }
	
}

void PlayerController::ProcessSpecialKeyPressed(int key, int x, int y)
{
	Controller::ProcessSpecialKeyPressed(key,x,y);
	std::cout << "KEY PRESSED\n";

	if (upKey.keyEquals(key)) { upKey.setIsPressed(true); }
	if (downKey.keyEquals(key)) { downKey.setIsPressed(true); }
	if (rightKey.keyEquals(key)) { rightKey.setIsPressed(true); }
	if (leftKey.keyEquals(key)) { leftKey.setIsPressed(true); }

	if (shootKey.keyEquals(key))
	{
		if (this->owner != NULL && !shootKey.getIsPressed())
		{
			((Player*)(owner))->Shoot();
		}
		shootKey.setIsPressed(true);
	}
}

void PlayerController::ProcessSpecialKeyReleased(int key, int x, int y)
{
	Controller::ProcessSpecialKeyReleased(key, x, y);
	std::cout << "KEY RELEASED\n";

	if (upKey.keyEquals(key)) { upKey.setIsPressed(false); }
	if (downKey.keyEquals(key)) { downKey.setIsPressed(false); }
	if (rightKey.keyEquals(key)) { rightKey.setIsPressed(false); }
	if (leftKey.keyEquals(key)) { leftKey.setIsPressed(false); }

	if (shootKey.keyEquals(key)) { shootKey.setIsPressed(false); }

}

void PlayerController::Update()
{
	Controller::Update();
	//resetear los valores de los ejes
	axisX = 0;
	axisY = 0;

	//actualizarlos en función de las teclas presionadas.
	//Si las teclas del mismo eje en direcciones estan presionadas a la vez, el eje vuelve a ser puesto a 0.
	if (upKey.getIsPressed()) { axisY += 1; }
	if (downKey.getIsPressed()) { axisY -= 1; }
	if (rightKey.getIsPressed()) { axisX += 1; }
	if (leftKey.getIsPressed()) { axisX -= 1; }

}

void PlayerController::setUseSpecialKeys(bool b)
{
	this->usesSpecialKeys = b;

	if (usesSpecialKeys)
	{
		upKey.setKey(101);
		downKey.setKey(103);
		rightKey.setKey(102);
		leftKey.setKey(100);
		shootKey.setKey('\n','\r');
	}
	else
	{
		upKey.setKey('w','W');
		downKey.setKey('s','S');
		rightKey.setKey('d','D');
		leftKey.setKey('a','A');
		shootKey.setKey('h','H');
	}
}