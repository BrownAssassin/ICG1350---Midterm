#pragma once

#include "Mesh.h"
#include "Texture.h"
#include "Shader.h"
#include "Material.h"
#include "OBJLoader.h"

class Model
{
public:
	Model(glm::vec3 position, Material* material, Texture* overrideTextureDiffuse, Texture* overrideTextureSpecular, std::vector<Mesh*> meshes);

	Model(glm::vec3 position, Material* material, Texture* overrideTextureDiffuse, Texture* overrideTextureSpecular, Mesh* mesh);

	//OBJ File loaded model
	Model(glm::vec3 position, Material* material, Texture* overrideTextureDiffuse, Texture* overrideTextureSpecular, const char* objFile);

	~Model();

	//Functions
	void rotate(const glm::vec3 rotation);

	void render(Shader* shader);

private:
	Material* material;
	Texture* overrideTextureDiffuse;
	Texture* overrideTextureSpecular;
	std::vector<Mesh*> meshes;

	glm::vec3 position;

};