#include "engine.h"
#include "shader/Shader.h"
#include <iostream>
#include <memory>

using std::endl, std::cout;

Engine::Engine() {
	this->camera = std::make_unique<Camera>();
	this->input = std::make_unique<InputHandler>();
	this->initWindow();
	this->initShaders();
	this->initShapes();
	this->initMatrices();
}

unsigned int Engine::initWindow(bool debug) {
	// glfw: initialize and configure
	glfwInit();
	glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
	glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
	glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);
#ifdef __APPLE__
	glfwWindowHint(GLFW_OPENGL_FORWARD_COMPAT, true);
	glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);
	glfwWindowHint(GLFW_COCOA_RETINA_FRAMEBUFFER, GLFW_FALSE);
	glfwWindowHint(GLFW_DECORATED, GLFW_FALSE);
#endif
	glfwWindowHint(GLFW_RESIZABLE, false);

	GLFWmonitor *primaryMonitor = glfwGetPrimaryMonitor();
	const GLFWvidmode *mode = glfwGetVideoMode(primaryMonitor);

	this->width = mode->width;
	this->height = mode->height;

	window = glfwCreateWindow(width, height, "transmogVX", nullptr, nullptr);
	glfwMakeContextCurrent(window);
	//	glfwSetInputMode(window, GLFW_CURSOR, GLFW_CURSOR_DISABLED); //disables
	// the cursor

	if (!gladLoadGLLoader((GLADloadproc)glfwGetProcAddress)) {
		cout << "Failed to initialize GLAD" << endl;
		return -1;
	}

	glViewport(0, 0, mode->width, mode->height);
	glEnable(GL_BLEND);
	glDisable(GL_CULL_FACE); // Disable face culling
	glEnable(GL_DEPTH_TEST);
	glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);
	glfwSwapInterval(1);

	return 0;
}

void Engine::initShaders() {
	shaderManager = make_unique<ShaderManager>();
	defaultShader = this->shaderManager->loadShader(
		"../src/res/shaders/default.vert", "../src/res/shaders/default.frag",
		nullptr, "default");
	defaultShader.use();
}
void Engine::initShapes() { cube = make_unique<Cube>(); }
void Engine::initMatrices() {
	model = mat4(0.3f);
	view = mat4(1.0f);
	projection = PROJECTION;
}

void Engine::update() {
	glClearColor(1.0f, 1.0f, 1.0f, 1.0f);
	float currentFrame = glfwGetTime();
	view = camera->GetViewMatrix();
	projection = camera->GetProjectionMatrix(width, height);
	deltaTime = currentFrame - lastFrame;
	lastFrame = currentFrame;
}

void Engine::render() {
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	defaultShader.use();
	defaultShader.setMatrix4("model", model);
	defaultShader.setMatrix4("view", view);
	defaultShader.setMatrix4("projection", projection);
	cube->draw();
	glfwSwapBuffers(window);
}

bool Engine::shouldClose() { return glfwWindowShouldClose(window); }
Engine::~Engine() {}
