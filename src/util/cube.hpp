#ifndef CUBE_HPP
#define CUBE_HPP
#include <glm/glm.hpp>
#include <vector>
using std::vector, glm::mat4;

class Cube {

  public:
	Cube();
	~Cube();
	void initVAO();
	void initVBO();
	void draw() const;

  protected:
	unsigned int VAO, VBO;
	float vertices[24];
	unsigned int indicies[36];
};

#endif // CUBE_HPP
