#include "Brick.h"

Brick::Brick(glm::vec3 pos, float width, float height, Material* material, Texture* texture, BrickType type)
{
	this->position = pos;
	this->width = width;
	this->height = height;
	this->texture = texture;
	this->material = material;
	this->type = type;
}

Brick::~Brick()
{
}

void Brick::setType(BrickType type, Texture* texture)
{
	this->type = type;
	this->texture = texture;
}
