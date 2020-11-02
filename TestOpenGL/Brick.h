#pragma once
#include "libs.h"

enum BrickType
{
	SOLID_BRICK,
	ONE_HIT_BRICK,
	TWO_HIT_BRICK
};

class Brick
{
public:
	Brick(glm::vec3 pos, float width, float height, Material* material, Texture* texture, BrickType type);
	~Brick();

	void setType(BrickType type, Texture* texture);
	
	glm::vec3 position;

	float width;
	float height;

	Texture* texture;
	Material* material;

	BrickType type;

	int brick_id;
	bool isDestroyed = false;

};
