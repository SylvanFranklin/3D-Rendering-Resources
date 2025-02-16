#include "engine.h"
#include "util/scene.hpp"
#include <iostream>
#include <memory>

using glm::vec2;
using std::endl, std::cout;
using namespace glm;

Engine::Engine() {
	this->camera = std::make_unique<Camera>();
	this->initWindow();
	this->initMatrices();
	this->initShaders();
	this->initScene();
	this->input = std::make_unique<InputHandler>(this->window);
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
	glEnable(GL_DEPTH_TEST);
	glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);
	glfwSwapInterval(1);

	return 0;
}

void Engine::initShaders() {
	shaderManager = make_unique<ShaderManager>();
	defaultShader = this->shaderManager->loadShader(
		"../res/shaders/default.vert", "../res/shaders/default.frag", nullptr,
		"default");
	//	defaultShader.use();
	defaultShader.setMatrix4("projection", this->PROJECTION);
}

void Engine::initScene() {
	this->scene = Scene();
	scene.setShader(defaultShader);
	scene.initVAO();
	scene.initVBO();
	//    scene.initEBO();
}

// void Engine::draw() {
//	defaultShader.use();
//	scene.draw();
//     glfwSwapBuffers(window);
// }

void Engine::initMatrices() {
	view = camera->GetViewMatrix();
	projection = camera->GetProjectionMatrix(width, height);
	modelLeft = mat4(1.0f);
}

void Engine::update() {
	float currentFrame = glfwGetTime();
	deltaTime = currentFrame - lastFrame;
	lastFrame = currentFrame;
}

void Engine::render() {
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	glClearColor(0.2f, 0.3f, 0.3f, 1.0f);
	view = camera->GetViewMatrix();
	// working with a box where we have vec2(1, -1, 1, 1)
	vec2 mouse = vec2(-1 + (input->get_mouse_pos().x / width * 2),
					  1 + (input->get_mouse_pos().y / height * -2));

	scene.setUniforms(modelLeft, view, projection, mouse);

	// cout << local_mouse.x << "," << local_mouse.y << endl;
	defaultShader.use();
	scene.draw();
	glfwSwapBuffers(window);
}

bool Engine::shouldClose() { return glfwWindowShouldClose(window); }
Engine::~Engine() {}
