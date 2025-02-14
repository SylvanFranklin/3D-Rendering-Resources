#ifndef CUBE_HPP
#define CUBE_HPP
#include "../shader/Shader.h"
#include <glm/glm.hpp>
#include <vector>
using std::vector, glm::mat4;

class Cube {

  public:
	Cube();
	~Cube();
	void initVAO();
	void initVBO();
	void initEBO();
	void draw() const;

  protected:
	unsigned int VAO, VBO, EBO;
	std::array<float, 24> vertices;
	std::array<float, 36> indices;
	mat4 model;
};

#endif // CUBE_HPP
