#include "Level.h"

void Level::Load(const char* fileName, unsigned int levelWidth, unsigned int levelHeight)
{
	//clear data
	this->bricks.clear();

	//Load from file
	unsigned int brickCode;

	Level level;
	std::string line = "";
	std::ifstream fstream(fileName);
	std::vector<std::vector<unsigned int>> brickData;

	if (fstream)
	{
		while (std::getline(fstream, line))
		{
			std::istringstream ss(line);
			std::vector<unsigned int> row;
			while (ss >> brickCode)
			{
				row.push_back(brickCode);
			}
			brickData.push_back(row);
		}

		if (brickData.size() > 0)
			this->initLevel(brickData, levelWidth, levelHeight);
	}
}

bool Level::levelDone()
{
	return false;
}

void Level::initLevel(std::vector<std::vector<unsigned int>> bricksData, unsigned int levelWidth, unsigned int levelHeight)
{
	//Dimensions
	unsigned int height = bricksData.size();
	unsigned int width = bricksData[0].size();
	//float unit_width = levelWidth
}
