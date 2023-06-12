#pragma once
#include "Background.h"
#include "LevelData.h"
#include "Text.h"
#include <vector>
#include "Sky.h"

class LevelManager
{
public:
	LevelManager();

	inline void setStage(int newStage) { this->currentStage = newStage; }
	void ResetStage();

	void Update(double dt, int score);

	void advanceStage();

	inline void setLevelData(std::vector<LevelData> const& newData) { this->levelDataList = newData; }
	inline void setBackground(Background* newBackground) { this->currentBackground = newBackground; this->startPos = newBackground->getLocation(); this->endPos = startPos + Vector3D{ 0,0,500 }; }
	inline void setStageText(Text *newText) { this->stageText = newText; }

	void lerpBackgroundPos(float t);

	void loadStage(int stage);

private:

	int currentStage;
	Background *currentBackground;
	std::vector<LevelData> levelDataList;

	Text *stageText;

	Vector3D startPos, endPos;
	float tparam;

};