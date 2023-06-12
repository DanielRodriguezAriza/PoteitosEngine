#include "LevelData.h"

LevelData::LevelData()
	:LevelData{ "default","default","",0,{1,0,0}}
{}

LevelData::LevelData(std::string const& newLevelName, std::string const& newBackgroundName, std::string const &newBackgroundColor, int newLevelScore, Color const &newSkyColor)
	:levelName{ newLevelName }, backgroundName{ newBackgroundName }, backgroundColor{ newBackgroundColor }, levelScore {newLevelScore}, skyColor{ newSkyColor }
{
	this->preloadData();
}

void LevelData::preloadData()
{
	ModelLoader loader;
	loader.loadModel(this->backgroundName);
	this->preloadedModel.setModel(loader.getModel());

	ColorLoader cloader;
	cloader.loadColor(this->backgroundColor);
	cloader.paintModel(this->preloadedModel);
}