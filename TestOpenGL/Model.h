#pragma once

#include "Mesh.h"
#include "Texture.h"
#include "Shader.h"
#include "Material.h"
#include "OBJLoader.h"

class Model
{
private:
	Material* material;
	Texture* overrideTextureDiffuse;
	Texture* overrideTextureSpecular;
	std::vector<Mesh*> meshes;

	glm::vec3 position;

	void updateUniforms()
	{

	}

public:
	Model(glm::vec3 position, Material* material, Texture* overrideTextureDiffuse, Texture* overrideTextureSpecular, std::vector<Mesh*> meshes)
	{
		this->position = position;
		this->material = material;
		this->overrideTextureDiffuse = overrideTextureDiffuse;
		this->overrideTextureSpecular = overrideTextureSpecular;

		for (auto* i : meshes)
		{
			this->meshes.push_back(new Mesh(*i));
		}

		for (auto& i : this->meshes)
		{
			i->move(this->position);
			i->setOrigin(this->position); 
		}
	}

	//OBJ File loaded model
	Model(glm::vec3 position, Material* material, Texture* overrideTextureDiffuse, Texture* overrideTextureSpecular, const char* objFile)
	{
		this->position = position;
		this->material = material;
		this->overrideTextureDiffuse = overrideTextureDiffuse;
		this->overrideTextureSpecular = overrideTextureSpecular;

		std::vector<Vertex> mesh = loadOBJ("OBJFiles/monkey.obj");
		meshes.push_back(new Mesh(mesh.data(), mesh.size(), NULL, 0, glm::vec3(2.0f, 0.0f, 0.0f),
			glm::vec3(0.0f),
			glm::vec3(0.0f),
			glm::vec3(1.0f)));

		for (auto& i : this->meshes)
		{
			i->move(this->position);
			i->setOrigin(this->position);
		}
	}

	~Model()
	{
		for (auto*& i : this->meshes)
			delete i;
	}

	//Functions
	void rotate(const glm::vec3 rotation)
	{
		for (auto& i : this->meshes)
			i->rotate(rotation);
	}

	void update()
	{

	}

	void render(Shader* shader)
	{
		//Update the uniforms
		this->updateUniforms();

		this->material->sendToShader(*shader);

		//Use a program
		shader->use();	

		//DRAW
		for (auto& i : this->meshes)
		{
			//Activate Texture
			this->overrideTextureDiffuse->bind(0);
			this->overrideTextureSpecular->bind(1);

			i->render(shader);
		}
	}

};