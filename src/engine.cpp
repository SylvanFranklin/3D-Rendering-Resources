#include "engine.h"
#include "util/inputHandler.h"
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
//	glfwSetInputMode(window, GLFW_CURSOR, GLFW_CURSOR_DISABLED); //disables the cursor

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
    // load shader manager
    shaderManager = make_unique<ShaderManager>();

    // Load shader into shader manager and retrieve it
    shapeShader = this->shaderManager->loadShader("../res/shader/shape.vert",
                                                  "../res/shader/shape.frag",
                                                  nullptr, "shape");

    // Set uniforms that never change
    shapeShader.use();
    shapeShader.setMatrix4("projection", this->PROJECTION);
}
void Engine::initShapes() {

}
void Engine::initMatrices() {
	view = camera->GetViewMatrix();
	projection = camera->GetProjectionMatrix(width, height);
	modelLeft = mat4(1.0f);
}

void Engine::update() {
	glClearColor(255.0, 255.0, 255.0, 1.0f);
	float currentFrame = glfwGetTime();
	deltaTime = currentFrame - lastFrame;
	lastFrame = currentFrame;
}

void Engine::render() {
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	view = camera->GetViewMatrix();

    glfwSwapBuffers(window);
}

bool Engine::shouldClose() { return glfwWindowShouldClose(window); }
Engine::~Engine() {}
