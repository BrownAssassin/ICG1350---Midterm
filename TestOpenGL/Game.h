#pragma once

#include "libs.h"
#include "Camera.h"


//Enumerations
enum shader_enums {	SHADER_CORE_PROGRAM = 0 };
enum texture_enums { TEX_BLAZARK = 0, TEX_BLAZARK_SPECULAR, TEX_CONTAINER, TEX_CONTAINER_SPECULAR };
enum material_enums { MAT_1 = 0 };
enum mesh_enums { MESH_QUAD = 0 };

class Game
{
private:
	//Variables
	//Window
	GLFWwindow* window;
	const int WINDOW_WIDTH;
	const int WINDOW_HEIGHT;
	int framebufferWidth;
	int framebufferHeight;

	//OpenGL Context
	const int GL_VERSION_MAJOR;
	const int GL_VERSION_MINOR;

	//Delta Time
	float dt;
	float curTime;
	float lastTime;

	//Mouse Input
	double lastMouseX;
	double lastMouseY;
	double mouseX;
	double mouseY;
	double mouseOffsetX;
	double mouseOffsetY;
	bool firstMouse;

	//Camera
	Camera camera;
	bool isPerspective = true;

	//Matrices
	glm::mat4 ViewMatrix;
	glm::vec3 camPosition;
	glm::vec3 worldUp;
	glm::vec3 camFront;

	glm::mat4 ProjectionMatrix;
	float fov;
	float nearPlane;
	float farPlane;

	int changeDirX = 1;
	int changeDirY = 1;

	 
	//Shaders
	std::vector<Shader*> shaders;

	//Textures
	std::vector<Texture*> textures;

	//Materials
	std::vector<Material*> materials;

	//Models
	std::vector<Model*> models;

	//Bricks
	std::vector<Brick*> bricks;

	//Lights
	std::vector<glm::vec3*> lights;

	//Private functions
	void initGLFW();
	void initWindow(const char* title, bool resizable);
	void initGLEW(); //AFTER CONTEXT CREATION!!!
	void initOpenGLOptions();
	void initMatrices(bool isPerspective = true);
	void initShaders();
	void initInstancingShaders();
	void initTextures();
	void initMaterials();
	void initOBJModels();
	void initBricks(float rows, float cols, float width, float height, float horDist, float verDist);
	void initModels();
	void initLights();
	void initUniforms();

	void updateUniforms();

	//Static variables

public:
	//Constructors/destructors
	Game(const char* title, const int WINDOW_WIDTH, const int WINDOW_HEIGHT, const int GL_VERSION_MAJOR, const int GL_VERSION_MINOR, bool resizable);
	virtual ~Game();

	//Accessors
	int getWindowShouldClose();

	//Modifiers
	void setWindowShouldClose();

	//Functions	
	void updateDt();
	void updateMouseInput();
	void updateKeyboardInput();
	void updateGamepadInput();
	void updateInput();
	void updateModels();
	void update();
	void render();

	//Static functions
	static void framebuffer_resize_callback(GLFWwindow* window, int fbW, int fbH);
};

