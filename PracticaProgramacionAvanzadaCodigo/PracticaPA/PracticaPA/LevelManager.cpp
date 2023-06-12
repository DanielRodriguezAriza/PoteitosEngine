#include "LevelManager.h"
#include "Math.h"

LevelManager::LevelManager()
	:currentStage{ 0 }, currentBackground{}, levelDataList{}, tparam{ 0 }, startPos{}, endPos{}, stageText{}
{}

void LevelManager::Update(double dt, int score)
{
	bool canAdvance = currentStage < levelDataList.size() && score >= levelDataList[currentStage].getLevelScore();
	if (canAdvance)
	{
		this->lerpBackgroundPos(tparam = Math::clamp<float>(tparam + dt*0.5,0,1));
		if ((1.0 - tparam) < 0.1)
		{
			this->advanceStage();
		}
	}
	else
	if (tparam != 0)
	{
		this->lerpBackgroundPos(tparam = Math::clamp<float>(tparam - dt*0.3,0,1));
	}
	else
	{
		tparam = 0;
		if (stageText != NULL)
		{
			stageText->setText("");
		}
	}
	if (currentStage > 0 && currentStage <= levelDataList.size())
	{
		Sky::lerpSkyColor(this->levelDataList[currentStage-1].getSkyColor());
	}
}

void LevelManager::lerpBackgroundPos(float t)
{
	this->currentBackground->setLocation(Math::lerp<Vector3D>(startPos,endPos,t));
}

void LevelManager::advanceStage()
{
	//currentBackground->loadBackground(levelDataList[currentStage].getBackgroundName());
	this->loadStage(this->currentStage);
	++this->currentStage;
}

void LevelManager::ResetStage()
{
	this->currentStage = 0;
	if (this->currentBackground != NULL)
	{
		this->currentBackground->loadBackground("../../Assets/Models/stage_spawn.obj");
	}
	if (this->stageText != NULL)
	{
		this->stageText->setText("");
	}
}

void LevelManager::loadStage(int stage)
{
	this->currentStage = stage;
	if (currentBackground != NULL)
	{
		currentBackground->setModel(levelDataList[currentStage].getPreloadedModel());
	}
	if (stageText != NULL)
	{
		stageText->setText(std::string("Stage ") + std::to_string(currentStage + 1) + ": " + levelDataList[currentStage].getLevelName());
	}
}
