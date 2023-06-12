#pragma once
#include <GL/glut.h>
#include <vector>
#include <chrono>

#include "Solid.h"
#include "Scene.h"
#include "Controller.h"
#include "Text.h"
#include "LevelManager.h"
#include "Player.h"
#include "SaveData.h"
#include "Time.h"
#include "Sky.h"
#include "Enemy.h"
#include "HealthPickUp.h"

class Game
{
public:

	Game();

	void Init();
	void Render();
	void Update();
	void ProcessKeyPressed(unsigned char key, int x, int y);
	void ProcessKeyReleased(unsigned char key, int x, int y);
	void ProcessMouseMovement(int x, int y);
	void ProcessMouseClick(int button, int state, int x, int y);
	void ProcessSpecialKeyPressed(int key, int x, int y);
	void ProcessSpecialKeyReleased(int key, int x, int y);
	
private:
	//funciones de gameplay
	void SpawnWave(int num);
	void SpawnEnemy();

private:

	Timer timer;

	SaveData saveData;

	Player *player1, *player2;

	Scene cameraScene, menuScene, mainScene, deadScene, saveScene, rankingScene;

	int maxEnemies;

	Text *play1Text, *play2Text, *scoresText, *quitText, *scoreText, *deadText, *saveScoreText, *saveNameText, *messageText;

	Text *rankingTextList[10];
	
	std::string playername;

	int totalPlayerScore;

	int menuOption;

	int currentRound;

	LevelManager *levelManager;
};

