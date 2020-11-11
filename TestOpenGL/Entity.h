#pragma once
#include <glm.hpp>
#include "Texture.h"
#include "Mesh.h"
#include "Model.h"

class Entity
{
public:

	Entity(glm::vec3 pos, glm::vec3 size, glm::vec3 rot, glm::vec3 vel, Texture* tex, Mesh* mesh, Model* model): m_model(model) {


		setPosition(pos);
		setSize(size);
		setRotation(rot);
		setvelocity(vel);

	}

	void setPosition(glm::vec3 pos);
	void setSize(glm::vec3 size);
	void setRotation(glm::vec3 rotation);
	void setvelocity(glm::vec3 velocity);
	void setID(int id);
	void setDestroyed(bool isdestroyed);
	
	glm::vec3 getVelocity();

	glm::vec3 getPosition();
	glm::vec3 getRotation();
	glm::vec3 getSize();

	int getID();
	bool getIsDestroyed();
	
private:
	glm::vec3 m_velocity;

	Model* m_model;
	//GLuint m_shader_prog

	unsigned int m_ID; 
	bool m_isDestroyed;
	GLuint VAO;
};