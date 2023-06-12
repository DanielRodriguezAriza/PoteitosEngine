#include "Game.h"
#include "Random.h"
#include "Math.h"
#include "Utility.h"

//Constructor
Game::Game()
	:saveData {}, player1{}, player2{}, cameraScene{}, menuScene{}, mainScene{}, deadScene{}, saveScene{}, rankingScene{},
	maxEnemies{}, play1Text{}, play2Text{}, scoresText{}, quitText{}, scoreText{}, deadText{}, saveScoreText{}, saveNameText{},
	rankingTextList{}, playername{}, totalPlayerScore{}, menuOption{}, currentRound{ 0 }, levelManager{}, messageText{}
{}

//Funciones básicas de la clase Game
void Game::Init()
{
	//game init
	Random::setSeed(time(0));
	this->maxEnemies = 20;
	this->totalPlayerScore = 0;

	//camera scene init
	cameraScene.Init();
	cameraScene.setIsActive(true);

	Camera* playerCamera = new Camera;
	playerCamera->setLocation(Vector3Df{ 0,0,40 }); //oldpos is 0 10 40
	cameraScene.addObject(playerCamera);

	//menu scene init
	menuScene.Init();
	menuScene.setIsActive(true);

	menuOption = 0;
	
	play1Text = new Text{ "[Play](1p)" };
	play1Text->setLocation(playerCamera->getLocation() + Vector3Df{ -.4,0.4,-2 });
	play1Text->setColor({ 1,1,1 });
	play1Text->setIsScreenSpace(true);
	play1Text->setIsStroke(true);
	play1Text->setScale(.2);
	menuScene.addObject(play1Text);

	play2Text = new Text{ "[Play](2p)" };
	play2Text->setLocation(playerCamera->getLocation() + Vector3Df{ -.4,0.2,-2 });
	play2Text->setColor({ 1,1,1 });
	play2Text->setIsScreenSpace(true);
	play2Text->setIsStroke(true);
	play2Text->setScale(.2);
	menuScene.addObject(play2Text);

	scoresText = new Text{ "[Rank]" };
	scoresText->setLocation(playerCamera->getLocation() + Vector3Df{ -.4,0,-2 });
	scoresText->setColor({ 1,1,1 });
	scoresText->setIsScreenSpace(true);
	scoresText->setIsStroke(true);
	scoresText->setScale(.2);
	menuScene.addObject(scoresText);

	quitText = new Text{ "[Quit]" };
	quitText->setLocation(playerCamera->getLocation() + Vector3Df{ -.4,-0.2,-2 });
	quitText->setColor({ 1,1,1 });
	quitText->setIsScreenSpace(true);
	quitText->setIsStroke(true);
	quitText->setScale(.2);
	menuScene.addObject(quitText);

	//main scene init
	mainScene.Init();
	mainScene.setIsActive(false);

	player1 = new Player;
	player1->setLocation({-10,0,0});
	player1->setPlayerColor({1,0,0});
	player1->getPlayerController().setUseSpecialKeys(false);

	player2 = new Player;
	player2->setLocation({10,0,0});
	player2->setPlayerColor({0,1,0});
	player2->getPlayerController().setUseSpecialKeys(true);

	mainScene.addObject(player1);
	mainScene.addObject(player2);

	Background* background = new Background;
	background->setScale(5);
	background->setLocation({ 0,-400,0 });
	mainScene.addObject(background);

	levelManager = new LevelManager;
	levelManager->setLevelData(
		{
			{"Space Runway","../../Assets/Models/stage_id_0.obj","../../Assets/Models/stage_id_0.mtl",0,{0,0,0.2}},
			{"Asteroid Field","../../Assets/Models/asteroides_fondo_1.obj","../../Assets/Models/stage_id_1.mtl",5000,{.5,.2,0.5}},
			{"Turbine Pathway","../../Assets/Models/stage_id_2.obj","../../Assets/Models/stage_id_2.mtl",10000,{0,0.2,0.2}},
			{"Bridge City","../../Assets/Models/stage_id_3.obj","../../Assets/Models/stage_id_3.mtl",20000,{1,0.66,.2}},
			{"Red Canyon","../../Assets/Models/stage_id_4.obj","../../Assets/Models/stage_id_4.mtl",25000,{0,.8,.8}}
		}
	);
	levelManager->setBackground(background);
	
	scoreText = new Text{"SCORE: "};
	scoreText->setLocation(playerCamera->getLocation() + Vector3Df{-2,1,-2});
	scoreText->setColor({1,1,1});
	scoreText->setIsScreenSpace(true);
	scoreText->setIsStroke(true);
	scoreText->setScale(.2);
	mainScene.addObject(scoreText);

	messageText = new Text{ "" };
	messageText->setLocation(playerCamera->getLocation() + Vector3Df{ -.6,0.5,-2 }); //stage text
	messageText->setColor({ 0,1,0 });
	messageText->setIsScreenSpace(true);
	messageText->setIsStroke(true);
	messageText->setScale(.1);
	mainScene.addObject(messageText);
	levelManager->setStageText(messageText);


	//dead scene init
	deadScene.Init();
	deadScene.setIsActive(false);

	deadText = new Text{ "[YOU ARE DEAD]" };
	deadText->setLocation(playerCamera->getLocation() + Vector3Df{ -1,0,-2 });
	deadText->setColor({ 1,0,0 });
	deadText->setIsScreenSpace(true);
	deadText->setIsStroke(true);
	deadText->setScale(.2);
	deadScene.addObject(deadText);

	//save scene init
	saveScene.Init();
	saveScene.setIsActive(false);

	saveScoreText = new Text{ "SCORE: " };
	saveScoreText->setLocation(playerCamera->getLocation() + Vector3Df{ -1,0,-2 });
	saveScoreText->setColor({ 1,1,1 });
	saveScoreText->setIsScreenSpace(true);
	saveScoreText->setIsStroke(true);
	saveScoreText->setScale(.2);
	saveScene.addObject(saveScoreText);

	saveNameText = new Text{ "NAME: ___" };
	saveNameText->setLocation(playerCamera->getLocation() + Vector3Df{ -1,-0.4,-2 });
	saveNameText->setColor({ 1,1,1 });
	saveNameText->setIsScreenSpace(true);
	saveNameText->setIsStroke(true);
	saveNameText->setScale(.2);
	saveScene.addObject(saveNameText);

	//ranking scene init
	rankingScene.Init();
	rankingScene.setIsActive(false);

	//solo se muestra el top 10
	for (int i = 0; i < 10; ++i)
	{
		std::string txt = std::to_string(1+i) + ") --- : P1: ---, P2: ---";
		rankingTextList[i] = new Text{txt};
		rankingTextList[i]->setLocation(playerCamera->getLocation() + Vector3Df{ -.5,1.f+i*-0.2f,-2 });
		rankingTextList[i]->setColor({ 1,1,1 });
		rankingTextList[i]->setIsScreenSpace(true);
		rankingTextList[i]->setIsStroke(true);
		rankingTextList[i]->setScale(.1);
		rankingScene.addObject(rankingTextList[i]);
	}

}

void Game::Render()
{
	for (auto scene : Scene::gameScenes)
	{
		if (scene->getIsActive())
		{
			scene->Render();
		}
	}
}

void Game::Update()
{

	Time::deltaTimeSeconds = timer.getElapsedTime();
	//Utility::print("deltaTime: ",Time::deltaTimeSeconds," seconds\n");

	

	for (auto scene : Scene::gameScenes)
	{
		if (scene->getIsActive())
		{
			scene->Update(Time::deltaTimeSeconds);
		}
	}


	if (menuScene.getIsActive())
	{
		play1Text->setColor((menuOption == 0 ? Color{ 1,1,0 } : Color{ 1 }));
		play2Text->setColor((menuOption == 1 ? Color{ 1,1,0 } : Color{ 1 }));
		scoresText->setColor((menuOption == 2 ? Color{ 1,1,0 } : Color{ 1 }));
		quitText->setColor((menuOption == 3 ? Color{ 1,1,0 } : Color{ 1 }));

		Sky::setSkyColor({0,0,0.1});
	}


	if (mainScene.getIsActive())
	{
		levelManager->Update(Time::deltaTimeSeconds,totalPlayerScore);

		this->SpawnWave(10);
		this->totalPlayerScore = player1->getPlayerScore() + player2->getPlayerScore();
		this->scoreText->setText("SCORE: " + std::to_string(totalPlayerScore));

		if (!player1->getIsAlive() && !player2->getIsAlive())
		{
			deadScene.setIsActive(true);
		}
	}

	if (saveScene.getIsActive())
	{
		this->saveNameText->setText(std::string("NAME: ") + playername);
	}

	if (rankingScene.getIsActive())
	{

	}

	timer.Restart();
}


//Eventos de Entrada / Salida
void Game::ProcessKeyPressed(unsigned char key, int x, int y)
{
	std::cout << "Tecla presionada: {'" << key << "' = '" << (int)(key)<< "'}\n";
	for (auto controller : Controller::gameControllers)
	{
		controller->ProcessKeyPressed(key, x, y);
	}

	if (menuScene.getIsActive() && (key == '\n' || key == '\r'))
	{
		switch (menuOption)
		{
		case 0:
			menuScene.setIsActive(false);
			mainScene.setIsActive(true);
			player1->setIsAlive(true);
			player2->setIsAlive(false);

			player1->setLocation({0,0,0});

			levelManager->ResetStage();
			//levelManager->loadStage(4);

			break;
		case 1:
			menuScene.setIsActive(false);
			mainScene.setIsActive(true);
			player1->setIsAlive(true);
			player2->setIsAlive(true);

			player1->setLocation({ -10,0,0 });
			player2->setLocation({  10,0,0 });

			levelManager->ResetStage();

			break;
		case 2:
			menuScene.setIsActive(false);
			rankingScene.setIsActive(true);
			saveData.load("../../Data/save.sav");
			
			//resetear el top 10 del ranking
			for(int i = 0; i < 10; ++i)
			{
				std::string txt = std::to_string(1 + i) + ") --- : ---";
				rankingTextList[i]->setText(txt);
			}
			//mostrar el top 10 del ranking
			for (int i = 0; i < std::min(10,saveData.getNumPlayers()); ++i)
			{
				std::string txt = std::to_string(1 + i) + ") " + saveData.getPlayerName(i) + " : " + std::to_string(saveData.getPlayerScore(i));
				rankingTextList[i]->setText(txt);
			}

			break;
		case 3:
			exit(0);
		default:
			std::cout << "Este caso no debería ser posible, si has llegado aquí, algo se ha roto muy fuertemente.\n";
			break;
		}
	}
	else
	if (deadScene.getIsActive() && (key == '\n' || key == '\r'))
	{
		menuScene.setIsActive(false);
		mainScene.setIsActive(false);
		deadScene.setIsActive(false);
		saveScene.setIsActive(true);

		saveScoreText->setText("SCORE: " + std::to_string(this->totalPlayerScore));
		playername = "";
	}
	else
	if (saveScene.getIsActive())
	{
		if (playername.size()>0 && (key == '\n' || key == '\r'))
		{
			saveData.save("../../Data/save.sav",playername,totalPlayerScore);
			totalPlayerScore = 0;
			player1->setPlayerScore(0);
			player2->setPlayerScore(0);
			saveScene.setIsActive(false);
			menuScene.setIsActive(true);
		}
		else
		if (key == 8 && playername.size() > 0)
		{
			playername.pop_back();
		}
		else
		if (playername.size() < 6 && (isalpha(key) || isdigit(key)))
		{
			playername.push_back(key);
		}
	}
	else
	if (rankingScene.getIsActive() && (key == '\n' || key == '\r'))
	{
		rankingScene.setIsActive(false);
		menuScene.setIsActive(true);
	}
}

void Game::ProcessKeyReleased(unsigned char key, int x, int y)
{
	std::cout << "Tecla soltada: {'" << key << "'}\n";
	for (auto controller : Controller::gameControllers)
	{
		controller->ProcessKeyReleased(key, x, y);
	}
}

void Game::ProcessMouseMovement(int x, int y)
{
	std::cout << "Ratón desplazado: {" << x << ", " << y << "}\n";
	for (auto controller : Controller::gameControllers)
	{
		controller->ProcessMouseMovement(x, y);
	}
}

void Game::ProcessMouseClick(int button, int state, int x, int y)
{
	std::cout << "Evento Click: {button = " << button << ", state = " << state << ", pos = {" << x << ", " << y << "} }\n";
	for (auto controller : Controller::gameControllers)
	{
		controller->ProcessMouseClick(button, state, x, y);
	}
}

void Game::ProcessSpecialKeyPressed(int key, int x, int y)
{
	std::cout << "Tecla especial presionada: {'" << key << "', " << x << ", " << y << "}\n";
	for (auto controller : Controller::gameControllers)
	{
		controller->ProcessSpecialKeyPressed(key,x,y);
	}

	if (menuScene.getIsActive())
	{
		if (key == 101)
		{
			menuOption--;
		}

		if (key == 103)
		{
			menuOption++;
		}

		menuOption = Math::clamp<int>(menuOption, 0, 3);
	}
	

}

void Game::ProcessSpecialKeyReleased(int key, int x, int y)
{
	std::cout << "Tecla especial soltada: {'" << key << "', " << x << ", " << y << "}\n";
	for (auto controller : Controller::gameControllers)
	{
		controller->ProcessSpecialKeyReleased(key, x, y);
	}
}




//Funciones de gameplay:

void Game::SpawnWave(int num)
{	
	if (Enemy::numEnemies > 0) { return; }
	for (int i = 0; i < num; ++i)
	{
		this->SpawnEnemy();
	}

	bool deadPlayers = false;
	for (auto* currentPlayer : Player::playerList)
	{
		if (!currentPlayer->getIsAlive()) { deadPlayers = true; }
	}

	float rand = Random::getRand<float>(0, 100);
	if (rand <= 50 && deadPlayers && menuOption != 0)
	{
		HealthPickUp* p = new HealthPickUp{ {0,0,-500} };
		mainScene.addObject(p);
	}
	++currentRound;
}

void Game::SpawnEnemy()
{
	Enemy* currentEnemy = new Enemy{ { Random::getRand<float>(-30,30),Random::getRand<float>(-20,20),-1000 + Random::getRand<float>(-200,0) } , Enemy::preloadedEnemyModel };
	currentEnemy->setSpeedMult(currentEnemy->getSpeedMult()+Random::getRand<float>(0.f,10.f*(currentRound%6)+10.f));
	this->mainScene.addObject(currentEnemy);
}
