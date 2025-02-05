#ifndef SCENE_HPP
#define SCENE_HPP

#include <GLFW/glfw3.h>
#include <glad/glad.h>
#include <glm/glm.hpp>

class Scene {
  private:
	unsigned int VBO;
	unsigned int VAO;
	static const unsigned int indices[6];
	static const float vertices[18];

  public:
	Scene() = default; // Corrected constructor
	void initVBO();
	void initVAO();
	void draw();
};

#endif // SCENE_HPP

