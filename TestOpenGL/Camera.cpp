#include "Camera.h"

Camera::Camera(glm::vec3 position, glm::vec3 direction, glm::vec3 worldUp)
{
	this->ViewMatrix = glm::mat4(1.0f);

	this->movementSpeed = 3.0f;
	this->sensitivity = 5.0f;

	this->worldUp = worldUp;
	this->position = position;
	this->right = glm::vec3(0.0f);
	this->up = worldUp;

	this->pitch = 0.0f;
	this->yaw = -90.0f;
	this->roll = 0.0f;

	this->updateCameraVectors();
}

const glm::mat4 Camera::getViewMatrix()
{
	this->updateCameraVectors();

	this->ViewMatrix = glm::lookAt(this->position, this->position + this->front, this->up);

	return this->ViewMatrix;
}

void Camera::setCamLookAt(glm::vec3 camTarget)
{
	this->front = glm::normalize(camTarget - this->position);

	//this->ViewMatrix = glm::lookAt(this->position, camTarget, glm::vec3(0.0f, 1.0f, 0.0f));
}

const glm::vec3 Camera::getPosition() const
{
	return this->position;
}

void Camera::setPosition(glm::vec3 pos)
{
	this->position = pos;
}

void Camera::move(const float& dt, const int direction)
{
	//Update position vector
	switch (direction)
	{
	case FORWARD:
		this->position += this->front * this->movementSpeed * dt;

		break;
	case BACKWARD:
		this->position -= this->front * this->movementSpeed * dt;

		break;
	case LEFT:
		this->position -= this->right * this->movementSpeed * dt;

		break;
	case RIGHT:
		this->position += this->right * this->movementSpeed * dt;

		break;
	default:
		break;
	}
}

void Camera::updateMouseInput(const float& dt, const double& offsetX, const double& offsetY)
{
	//Update pitch, yaw and roll
	this->pitch += static_cast<GLfloat>(offsetY) * this->sensitivity * dt;
	this->yaw += static_cast<GLfloat>(offsetX) * this->sensitivity * dt;


	if (this->pitch > 80.0f)
		this->pitch = 80.0f;
	else if (this->pitch < -80.0f)
		this->pitch = -80.0f;

	if (this->yaw > 360.f || this->yaw < -360.f)
		this->yaw = 0;
}

void Camera::updateInput(const float& dt, const int direction, const double& offsetX, const double& offsetY)
{
	this->updateMouseInput(dt, offsetX, offsetY);
}

void Camera::updateCameraVectors()
{
	/*this->front.x = cos(glm::radians(this->yaw)) * cos(glm::radians(this->pitch));
	this->front.y = sin(glm::radians(this->pitch));
	this->front.z = sin(glm::radians(this->yaw)) * cos(glm::radians(this->pitch));

	this->front = glm::normalize(this->front);*/
	this->right = glm::normalize(glm::cross(this->front, this->worldUp));
	this->up = glm::normalize(glm::cross(this->right, this->front));
}
