#include "cube.hpp"
// #include <GLFW/glfw3.h>
#include <glad/glad.h>
// #include <glm/glm.hpp>

Cube::Cube() : vertices() {
	float vertices[24] = {-1.0f, 1.0f,	0.0f,  -1.0f, -1.0f, 0.0f,	1.0f,
						  1.0f,	 0.0f,	1.0f,  -1.0f, 0.0f,	 -1.0f, 1.0f,
						  -1.0f, -1.0f, -1.0f, -1.0f, 1.0f,	 1.0f,	-1.0f,
						  1.0f,	 -1.0f, -1.0f

	};
	unsigned int indicies[36] = {
		0, 2, 3, 0, 3, 1, 2, 6, 7, 2, 7, 3, 6, 4, 5, 6, 5, 7,
		4, 0, 1, 4, 1, 5, 0, 4, 6, 0, 6, 2, 1, 5, 7, 1, 7, 3,
	};

	initVAO();
	initVBO();
};

Cube::~Cube() {
	glDeleteVertexArrays(1, &VAO);
	glDeleteBuffers(1, &VBO);
}

void Cube::draw() const {
	glBindVertexArray(VAO);
	glDrawArrays(GL_TRIANGLES, 0, 3*24);
}

void Cube::initVAO() {
	unsigned int VAO;
	glGenVertexArrays(1, &VAO);
}

void Cube::initVBO() {
	glBindVertexArray(VAO);
	glGenBuffers(1, &VBO);
	glBindBuffer(GL_ARRAY_BUFFER, VBO);
	glBufferData(GL_ARRAY_BUFFER, sizeof(vertices), vertices, GL_STATIC_DRAW);
	glEnableVertexAttribArray(0);
}
