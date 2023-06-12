#include "ColorLoader.h"
#include <iostream>
#include <fstream>
#include <sstream>
#include "Utility.h"

ColorLoader::ColorLoader()
{}

void ColorLoader::paintModel(Model &model)
{
	for (int i = 0; i < this->colorList.size(); ++i)
	{
		model.paintColorIndex(this->colorList[i],i);
	}
}

void ColorLoader::loadColor(std::string const& filename)
{
	try
	{
		std::ifstream file;
		file.open(filename);
		std::string currentLine;

		while (std::getline(file, currentLine))
		{
			if (currentLine[0] == 'K' && currentLine[1] == 'd')
			{
				Color currentColor = this->readLine(currentLine);
				this->colorList.push_back(currentColor);
			}
		}

		file.close();
	}
	catch (std::exception& ex)
	{
		Utility::printError("Excepción al procesar el archivo \"", filename, "\": ", ex.what(), "\n");
	}
}

Color ColorLoader::readLine(std::string const& line)
{
	std::stringstream ss;

	std::string s;
	float r, g, b;

	ss << line;
	ss >> s >> r >> g >> b;

	Color ans = {r,g,b};

	return ans;
}