#include "cube.hpp"
// #include <GLFW/glfw3.h>
#include <glad/glad.h>
#include <iostream>
#include <ostream>
// #include <glm/glm.hpp>

Cube::Cube() {
	vertices = {-1.0f, 1.0f,  0.0f,	 -1.0f, -1.0f, 0.0f, 1.0f,	1.0f,
				0.0f,  1.0f,  -1.0f, 0.0f,	-1.0f, 1.0f, -1.0f, -1.0f,
				-1.0f, -1.0f, 1.0f,	 1.0f,	-1.0f, 1.0f, -1.0f, -1.0f};

	indices = {
		0, 2, 3, 0, 3, 1, 2, 6, 7, 2, 7, 3, 6, 4, 5, 6, 5, 7,
		4, 0, 1, 4, 1, 5, 0, 4, 6, 0, 6, 2, 1, 5, 7, 1, 7, 3,
	};

	initVAO();
};

Cube::~Cube() {
	glDeleteVertexArrays(1, &VAO);
	glDeleteBuffers(1, &VBO);
	glDeleteBuffers(1, &EBO); // Missing cleanup
}


void Cube::draw() const {
	glBindVertexArray(VAO);
	glDrawElements(GL_TRIANGLES, 36, GL_UNSIGNED_INT, 0);
	glBindVertexArray(0);
}

void Cube::initVAO() {
	glGenVertexArrays(1, &VAO);
	glBindVertexArray(VAO);
	initVBO();
	initEBO();
	glBindVertexArray(0);
}
void Cube::initEBO() {
	glGenBuffers(1, &EBO);
	glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, EBO);
	glBufferData(GL_ELEMENT_ARRAY_BUFFER, sizeof(indices), &indices,
				 GL_STATIC_DRAW);
}

void Cube::initVBO() {
	glGenBuffers(1, &VBO);
	glBindBuffer(GL_ARRAY_BUFFER, VBO);
	glBufferData(GL_ARRAY_BUFFER, sizeof(vertices), &vertices, GL_STATIC_DRAW);
	glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 3 * sizeof(float),
						  (void *)0);
	glEnableVertexAttribArray(0);
}
