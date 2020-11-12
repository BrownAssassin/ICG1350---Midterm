#pragma once
#include <glm.hpp>
#include "Texture.h"
#include "Mesh.h"
#include "Model.h"

enum playerDir { P_FORWARD = 0, P_BACKWARD, P_LEFT, P_RIGHT };

class Entity
{
public:
	Entity(Model* model, unsigned int id, glm::vec3 vel = glm::vec3(0), bool isdes = false)
		:m_model(model),
		m_ID(id),
		m_isDestroyed(isdes),
		m_velocity(vel)

	{
		
	}

	~Entity()
	{
		delete this->m_model;
	}

	/*Entity(glm::vec3 pos, glm::vec3 size, glm::vec3 rot, glm::vec3 vel, Texture* tex, Mesh* mesh, Model* model): m_model(model) {


		setPosition(pos);
		setSize(size);
		setRotation(rot);
		setvelocity(vel);

	}*/

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
	Model* getModel();

	int getID();
	bool getIsDestroyed();


	//void move(const float& dt, const int direction);
	
private:
	glm::vec3 m_velocity;

	Model* m_model;
	//GLuint m_shader_prog

	unsigned int m_ID; 
	bool m_isDestroyed;
	GLuint VAO;


	//Mouse Input
	GLfloat movementSpeed;

};

//class Player : Entity
//{
//public:
//	Player(Model* model, unsigned int id, glm::vec3 vel = glm::vec3(0), bool isdes = false)
//		: Entity(model, id, vel, isdes)
//	{
//		this->movementSpeed = 3.0f;
//		this->sensitivity = 5.0f;
//		this->worldUp = glm::vec3(0.0f, 1.0f, 0.0f);
//		this->up = glm::vec3(0.0f, 1.0f, 0.0f);
//		this->right = glm::vec3(0.0f);
//
//		this->pitch = 0.0f;
//		this->yaw = -90.0f;
//		this->roll = 0.0f;
//	}
//	
//	Model* getModel();
//	void move(const float& dt, const int direction);
//	void updateMouseInput(const float& dt, const double& offsetX, const double& offsetY);
//	void updateVectors();
//
//
//private:
//	//Mouse Input
//	GLfloat movementSpeed;
//	GLfloat sensitivity;
//	glm::vec3 worldUp;
//	
//	glm::vec3 front;
//	glm::vec3 right;
//	glm::vec3 up;
//	GLfloat pitch;
//	GLfloat yaw;
//	GLfloat roll;
//
//};