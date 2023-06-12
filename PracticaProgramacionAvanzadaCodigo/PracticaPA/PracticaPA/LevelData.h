#pragma once
#include "Solid.h"
#include "Model.h"
#include "ModelLoader.h"
#include "Background.h"
#include <string>
#include "Color.h"
#include "ColorLoader.h"

class LevelData
{
public:
	LevelData();
	LevelData(std::string const &newLevelName, std::string const &newBackgroundName, std::string const &newBackgroundColor, int newLevelScore, Color const &newSkyColor);

	inline void setLevelName(std::string const& newName) { this->levelName = newName; }
	inline void setBackgroundName(std::string const& newBackground) { this->backgroundName = newBackground; }
	inline void setLevelScore(int newScore) { this->levelScore = newScore; }
	inline void setSkyColor(Color const& newColor) { this->skyColor = newColor; }

	inline std::string getLevelName() const { return this->levelName; }
	inline std::string getBackgroundName() const { return this->backgroundName; }
	inline int getLevelScore() const { return this->levelScore; }
	inline Color getSkyColor() const { return this->skyColor; }

	void preloadData();
	inline Model getPreloadedModel() const { return this->preloadedModel; }

private:
	std::string levelName, backgroundName,backgroundColor;
	int levelScore;
	Model preloadedModel;
	Color skyColor;
};