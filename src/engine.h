#ifndef GRAPHICS_ENGINE_H
#define GRAPHICS_ENGINE_H

#include "util/camera.h"
#include "util/inputHandler.h"
#include <GLFW/glfw3.h>
#include <glad/glad.h>
#include <glm/glm.hpp>
#include <memory>
#include <vector>

using std::vector, std::unique_ptr, std::make_unique, glm::mat4;

class Engine {
  private:
	GLFWwindow *window{};
	bool allowMove = true;
	float time_since_last_move = 999.0;
	float width = 1920;
	float height = 1080;
	unique_ptr<Camera> camera;
	unique_ptr<InputHandler> input;
	mat4 modelLeft;	 // Model matrix for a 3D object
	mat4 projection; // Orthographic projection matrix maps a 3D scene to a
	mat4 view;		 // The camera's position and orientation in the world

	// @note Call glCheckError() after every OpenGL call to check for errors.
	//   GLenum glCheckError_(const char *file, int line);
	//
	// @brief Macro for glCheckError_ function. Used for debugging.
	// #define glCheckError() glCheckError_(__FILE__, __LINE__)

  public:
	Engine();
	~Engine();
	unsigned int initWindow(bool debug = false);
	void initShaders();
	void initShapes();
	void processInput();
	void initMatrices();
	void update();
	void render();
	float deltaTime = 0.0f; // Time between current frame and last frame
	float lastFrame = 0.0f; // Time of last frame (used to calculate deltaTime)
	bool shouldClose();
};

#endif // GRAPHICS_ENGINE_H
