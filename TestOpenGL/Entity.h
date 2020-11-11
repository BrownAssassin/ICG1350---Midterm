#pragma once
#include <glm.hpp>
#include "Texture.h"
#include "Mesh.h"
#include "Model.h"

class Entity
{
public:

	enum ID {
		PLAYER=0,
		ENEMY,
		BULLET=2000
	};


	Entity(Model model, unsigned int id, glm::vec3 vel = glm::vec3(0), bool isdes = false)
		:m_model(model),
		m_ID(id),
		m_isDestroyed(isdes),
		m_velocity(vel)
	{
	}

	void setPosition(glm::vec3 pos);
	void setSize(glm::vec3 size);
	void setRotation(glm::vec3 rotation);
	void setvelocity(glm::vec3 velocity);
	void setID(int id);
	void setDestroyed(bool isdestroyed);
	
	Model* GetModel();

	glm::vec3 getVelocity();

	glm::vec3 getPosition();
	glm::vec3 getRotation();
	glm::vec3 getSize();

	int getID();
	bool getIsDestroyed();
	
private:
	glm::vec3 m_velocity;

	Model m_model;
	//GLuint m_shader_prog

	unsigned int m_ID; 
	bool m_isDestroyed;
};