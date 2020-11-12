#include "Entity.h"

void Entity::setPosition(glm::vec3 pos)
{
	m_model->SetPosition(pos);
}

void Entity::setSize(glm::vec3 size)
{
m_model->SetSize(size);
}

void Entity::setRotation(glm::vec3 rotation)
{
	m_model->Setrotate(rotation);
}

void Entity::setvelocity(glm::vec3 velocity)
{
	m_velocity = velocity;
}

void Entity::setID(int id)
{
	m_ID = id;
}

void Entity::setDestroyed(bool isdestroyed)
{
	m_isDestroyed = isdestroyed;
}

glm::vec3 Entity::getPosition()
{
	return m_model->GetPosition();
}

glm::vec3 Entity::getSize()
{
	return m_model->GetSize();
}

Model* Entity::getModel()
{
	return m_model;
}

glm::vec3 Entity::getRotation()
{
	return m_model->GetRotation();
}

glm::vec3 Entity::getVelocity()
{
	return m_velocity;
}

int Entity::getID()
{
	return m_ID;
}

bool Entity::getIsDestroyed()
{
	return m_isDestroyed;
}

//void Entity::move(const float& dt, const int direction)
//{
//	//Update position vector
//	switch (direction)
//	{
//	case P_FORWARD:
//		this->setPosition(getPosition() += this->front * this->movementSpeed * dt);
//		std::cout << "forward\n";
//		break;
//	case P_BACKWARD:
//		this->setPosition(getPosition() -= this->front * this->movementSpeed * dt);
//
//		break;
//	case P_LEFT:
//		this->setPosition(getPosition() -= this->right * this->movementSpeed * dt);
//
//		break;
//	case P_RIGHT:
//		this->setPosition(getPosition() += this->right * this->movementSpeed * dt);
//
//		break;
//	default:
//		break;
//	}
//}


//Model* Player::getModel()
//{
//	return Entity::getModel();
//}
//
//void Player::move(const float& dt, const int direction)
//{
//	//Update position vector
//	switch (direction)
//	{
//	case P_FORWARD:
//		this->setPosition(getPosition() += this->front * this->movementSpeed * dt);
//
//		break;
//	case P_BACKWARD:
//		this->setPosition(getPosition() -= this->front * this->movementSpeed * dt);
//
//		break;
//	case P_LEFT:
//		this->setPosition(getPosition() -= this->right * this->movementSpeed * dt);
//
//		break;
//	case P_RIGHT:
//		this->setPosition(getPosition() += this->right * this->movementSpeed * dt);
//
//		break;
//	default:
//		break;
//	}
//}
//
//void Player::updateMouseInput(const float& dt, const double& offsetX, const double& offsetY)
//{
//	//Update pitch, yaw and roll
//	this->pitch += static_cast<GLfloat>(offsetY) * this->sensitivity * dt;
//	this->yaw += static_cast<GLfloat>(offsetX) * this->sensitivity * dt;
//
//
//	if (this->pitch > 80.0f)
//		this->pitch = 80.0f;
//	else if (this->pitch < -80.0f)
//		this->pitch = -80.0f;
//
//	if (this->yaw > 360.f || this->yaw < -360.f)
//		this->yaw = 0;
//}
//
//void Player::updateVectors()
//{
//	this->front.x = cos(glm::radians(this->yaw)) * cos(glm::radians(this->pitch));
//	this->front.y = sin(glm::radians(this->pitch));
//	this->front.z = sin(glm::radians(this->yaw)) * cos(glm::radians(this->pitch));
//
//	this->front = glm::normalize(this->front);
//	this->right = glm::normalize(glm::cross(this->front, this->worldUp));
//	this->up = glm::normalize(glm::cross(this->right, this->front));
//}
