#pragma once
#include "Color.h"
#include "Model.h"
#include <vector>
#include <string>

class ColorLoader
{
public:
	ColorLoader();

	void paintModel(Model &model);

	void loadColor(std::string const &filename);

private:
	std::vector<Color> colorList;

	Color readLine(std::string const& line);
};