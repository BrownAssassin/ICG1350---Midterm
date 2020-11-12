#include "Model.h"

//Model::Model(glm::vec3 position, Material* material, Texture* overrideTextureDiffuse, Texture* overrideTextureSpecular, Mesh* meshes)
//{
//	this->position = position;
//	this->material = material;
//	this->overrideTextureDiffuse = overrideTextureDiffuse;
//	this->overrideTextureSpecular = overrideTextureSpecular;
//
//	
//		this->meshes = meshes;
//
//		this->meshes->move(this->position);
//		this->meshes->setOrigin(this->position);
//	
//}

Model::Model(glm::vec3 position, Material* material, Texture* overrideTextureDiffuse, Texture* overrideTextureSpecular, Mesh* mesh)
{
	this->position = position;
	this->material = material;
	this->overrideTextureDiffuse = overrideTextureDiffuse;
	this->overrideTextureSpecular = overrideTextureSpecular;


	this->mesh = mesh;

	mesh->move(this->position);
	//mesh->setOrigin(this->position);
}

Model::Model(glm::vec3 position, Material* material, Texture* overrideTextureDiffuse, Texture* overrideTextureSpecular, const char* objFile)
{
	this->position = position;
	this->material = material;
	this->overrideTextureDiffuse = overrideTextureDiffuse;
	this->overrideTextureSpecular = overrideTextureSpecular;

	std::vector<Vertex> mesh = loadOBJ(objFile);
	this->mesh = new Mesh(mesh.data(), mesh.size(), NULL, 0, glm::vec3(2.0f, 0.0f, 0.0f),
		glm::vec3(0.0f),
		glm::vec3(1.0f));

	
	this->mesh->move(this->position);
	//this->meshes->setOrigin(this->position);
	
}

Model::~Model()
{	
	delete this->mesh;
}

void Model::SetPosition(const glm::vec3 position)
{
		this->mesh->setPosition(position);
}

void Model::SetSize(const glm::vec3 size)
{
	
	this->mesh->setScale(size);
}

glm::vec3 Model::GetPosition()
{
	return this->mesh->GetPosition();
}

glm::vec3 Model::GetSize()
{
	return this->mesh->GetScale();
}

glm::vec3 Model::GetRotation()
{
	return this->mesh->GetRotation();
}

Mesh* Model::getMesh()
{
	return this->mesh;
}

void Model::Setrotate(const glm::vec3 rotation)
{
	
	this->mesh->setRotation(rotation);
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

		this->mesh->render(shader);

}
