#pragma once
#include <glm.hpp>
#include "Texture.h"
#include "Mesh.h"
#include "Model.h"

class Entity
{
public:
	void setPosition(glm::vec3 pos);
	void setSize(glm::vec3 size);
	void setRotation(glm::vec3 rotation);
	void setvelocity(glm::vec3 velocity);
	void setID(int id);
	void setDestroyed(bool isdestroyed);
	
	glm::vec3 getPosition();
	glm::vec3 getSize();
	glm::vec3 getRotation();
	glm::vec3 getVelocity();

	int getID();
	bool getIsDestroyed();
	
private:
	glm::vec3 m_position;
	glm::vec3 m_size;
	glm::vec3 m_rotation;
	glm::vec3 m_velocity;

	Texture* m_texture;
	Mesh* m_mesh;
	Model* m_model;
	//GLuint m_shader_prog

	int m_ID;
	bool m_isDestroyed;
	GLuint VAO;
};