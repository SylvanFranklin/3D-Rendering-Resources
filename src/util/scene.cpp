#include "scene.hpp"

const unsigned int Scene::indices[6] = {
	0, 1, 3, // first triangle
	1, 2, 3	 // second triangle
};
const float Scene::vertices[18] = {
	0.5f,  0.5f,  0.0f, // top right
	0.5f,  -0.5f, 0.0f, // bottom right
	-0.5f, 0.5f,  0.0f, // top left
	0.5f,  -0.5f, 0.0f, // bottom right
	-0.5f, -0.5f, 0.0f, // bottom left
	-0.5f, 0.5f,  0.0f	// top left
};

void Scene::draw() {
	glBindVertexArray(VAO);
	glDrawArrays(GL_TRIANGLES, 0, 3);
}

void Scene::initVBO() {
	glGenBuffers(1, &VBO);
	glBindBuffer(GL_ARRAY_BUFFER, VBO);
	glBufferData(GL_ARRAY_BUFFER, sizeof(vertices), vertices, GL_STATIC_DRAW);
}

unsigned int Scene::initVAO() {
	glGenVertexArrays(1, &VAO);
	glBindVertexArray(VAO);
    initVBO();
	glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 3 * sizeof(float),
						  (void *)0);

	glEnableVertexAttribArray(0);
	return VAO;

}
