#include "SaveData.h"
#include "Utility.h"

SaveData::SaveData()
:names{}, scores{}, numPlayers{0}
{}


void SaveData::load(std::string const& filename)
{
	this->names.clear();
	this->scores.clear();
	this->numPlayers = 0;

	try
	{
		std::ifstream file;
		file.open(filename);

		while (file.good() && !file.eof())
		{
			std::string identifier, currname;
			int currscore;

			file >> identifier;
			file >> currname;
			file >> currscore;

			if (identifier[0] == 'p')
			{
				this->names.push_back(currname);
				this->scores.push_back(currscore);
				++numPlayers;
			}
			
		}

		file.close();
		this->orderScores();
	}
	catch (std::exception& e)
	{
		Utility::printError("Could not read save data: ", e.what(), "\n");
	}
}

void SaveData::save(std::string const& filename, std::string const &name, int score)
{
	try
	{
		std::ofstream file;
		file.open(filename, std::ios_base::app);

		file << "p: " << name << " " << score << "\n";

		file.close();
	}
	catch (std::exception& e)
	{
		Utility::printError("Could not write save data: ", e.what(), "\n");
	}
}

void SaveData::orderScores()
{
	if (this->numPlayers <= 0) { return; }

	for (int i = 0; i < this->numPlayers; ++i)
	{
		for (int j = i; j < this->numPlayers; ++j)
		{
			if (scores[i] < scores[j])
			{
				int temp = scores[i];
				scores[i] = scores[j];
				scores[j] = temp;

				std::string tempName = names[i];
				names[i] = names[j];
				names[j] = tempName;
			}
		}
	}
	for (int i = 0; i < numPlayers; ++i)
	{
		std::cout << "p: " << names[i] << " : " << scores[i]<<"\n";
	}
}