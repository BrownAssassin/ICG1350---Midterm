#pragma once

#include "libs.h"

class Level
{
public:
	Level() {};

	void Load(const char* fileName, unsigned int levelWidth, unsigned int levelHeight);
	
	//Check if all bricks are destroyed
	bool levelDone();

	std::vector<GameObject> bricks;

private:
	void initLevel(std::vector<std::vector<unsigned int>> bricksData, unsigned int levelWidth, unsigned int levelHeight);
};
