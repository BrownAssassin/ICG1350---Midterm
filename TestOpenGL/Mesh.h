#pragma once

#include <iostream>
#include <vector>


#include "Vertex.h"
#include "Primitives.h"
#include "Shader.h"
#include "Texture.h"
#include "Material.h"

class Mesh
{

public:
	Mesh(Vertex* vertexArray,
		const unsigned& nrOfVertices,
		GLuint* indexArray,
		const unsigned& nrOfIndices,
		glm::vec3 position = glm::vec3(0.0f),
		glm::vec3 origin = glm::vec3(0.0f),
		glm::vec3 rotation = glm::vec3(0.0f),
		glm::vec3 scale = glm::vec3(1.0f));

	Mesh(
		Primitive* primitive,
		glm::vec3 position = glm::vec3(0.0f),
		glm::vec3 origin = glm::vec3(0.0f),
		glm::vec3 rotation = glm::vec3(0.0f),
		glm::vec3 scale = glm::vec3(1.0f));

	Mesh(const Mesh& obj);

	~Mesh();

	//Modifiers
	void setPosition(const glm::vec3 position);

	void setOrigin(const glm::vec3 origin);

	void setRotation(const glm::vec3 rotation);

	void setScale(const glm::vec3 scale);

	glm::vec3 GetPosition();

	glm::vec3 GetRotation();

	glm::vec3 GetScale();

	void move(const glm::vec3 position);

	void rotate(const glm::vec3 rotation);

	void scaleMesh(const glm::vec3 scale);

	void render(Shader* shader);

private:
	Vertex* vertexArray;
	unsigned nrOfVertices;
	GLuint* indexArray;
	unsigned nrOfIndices;

	GLuint VAO;
	GLuint VBO;
	GLuint EBO;

	GLuint skyboxVAO;
	GLuint skyboxVBO;

	glm::vec3 position;
	glm::vec3 origin;
	glm::vec3 rotation;
	glm::vec3 scale;

	glm::mat4 ModelMatrix;

	void initVAO();

	void updateUniforms(Shader* shader);

	void updateModelMatrix();
};