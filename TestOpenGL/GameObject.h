#pragma once
#include "libs.h"

class GameObject
{
public:
	GameObject();
	GameObject(glm::vec3 position, glm::vec3 size, Texture* texture, glm::vec3 color = glm::vec3(1.0f), glm::vec3 velocity = glm::vec3(0.0f, 0.0f, 0.0f));

	glm::vec3 position;
	glm::vec3 size;
	glm::vec3 velocity;
	glm::vec3 color; //

	float rotation;
	bool isSolid;
	bool isDestroyed;

	Texture* texture;
	
};
