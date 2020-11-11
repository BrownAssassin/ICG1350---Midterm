#include "Model.h"

Model::Model(glm::vec3 position, Material* material, Texture* overrideTextureDiffuse, Texture* overrideTextureSpecular, Mesh* mesh)
{
	this->position = position;
	this->material = material;
	this->overrideTextureDiffuse = overrideTextureDiffuse;
	this->overrideTextureSpecular = overrideTextureSpecular;


	this->meshes = mesh;

	mesh->move(this->position);
	mesh->setOrigin(this->position);
}

Model::Model(glm::vec3 position, Material* material, Texture* overrideTextureDiffuse, Texture* overrideTextureSpecular, const char* objFile)
{
	this->position = position;
	this->material = material;
	this->overrideTextureDiffuse = overrideTextureDiffuse;
	this->overrideTextureSpecular = overrideTextureSpecular;

	std::vector<Vertex> mesh = loadOBJ(objFile);
	meshes = new Mesh(mesh.data(), mesh.size(), NULL, 0, glm::vec3(2.0f, 0.0f, 0.0f),
		glm::vec3(0.0f),
		glm::vec3(0.0f),
		glm::vec3(1.0f));

	
	this->meshes->move(this->position);
	this->meshes->setOrigin(this->position);
	
}

Model::~Model()
{
		delete this->meshes;
}

void Model::SetPosition(const glm::vec3 position)
{
		this->meshes->setPosition(position);
}

void Model::SetSize(const glm::vec3 size)
{
	
	this->meshes->setScale(size);
}

glm::vec3 Model::GetPosition()
{
	return this->meshes->GetPosition();
}

glm::vec3 Model::GetSize()
{
	return this->meshes->GetScale();
}

glm::vec3 Model::GetRotation()
{
	return this->meshes->GetRotation();
}

void Model::Setrotate(const glm::vec3 rotation)
{
	
	this->meshes->setRotation(rotation);
}

void Model::render(Shader* shader)
{
	this->material->sendToShader(*shader);

	//Use a program
	shader->use();

	//DRAW
	
		//Activate Texture
		this->overrideTextureDiffuse->bind(0);
		this->overrideTextureSpecular->bind(1);

		this->meshes->render(shader);

}
