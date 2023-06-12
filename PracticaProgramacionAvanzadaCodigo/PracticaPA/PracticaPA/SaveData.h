#pragma once
#include <iostream>
#include <fstream>
#include <vector>
#include <string>

class SaveData
{
public:
	SaveData();

	void load(std::string const &filename);
	void save(std::string const& filename, std::string const& name, int score);

	inline std::string getPlayerName(int index) const { return this->names[index]; }
	inline int getPlayerScore(int index) const { return this->scores[index]; }
	inline int getNumPlayers() const { return this->numPlayers; }

private:

	std::vector<std::string> names;
	std::vector<int> scores;
	int numPlayers;

	void orderScores();

};