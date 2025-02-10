#include "../engine.h"

void Engine::processInput() {
	glfwPollEvents();
	using glm::vec3;
	input->update_keys(window);
	input->update_mouse(window);
	if (input->key_pressed(GLFW_KEY_Q))
		glfwSetWindowShouldClose(window, true);

	vec3 direction = vec3(0.0);
	if (input->key_pressed(GLFW_KEY_UP))
		direction += vec3(0.0f, 0.0f, 0.2f);
	if (input->key_pressed(GLFW_KEY_DOWN))
		direction += vec3(0.0f, 0.0f, -0.2f);
	if (input->key_pressed(GLFW_KEY_LEFT))
		direction += vec3(-0.2f, 0.0f, 0.0f);
	if (input->key_pressed(GLFW_KEY_RIGHT))
		direction += vec3(0.2f, 0.0f, 0.0f);
	if (input->key_pressed(GLFW_KEY_SPACE))
		direction += vec3(0.0f, 0.2f, 0.0f);
	if (input->key_pressed(GLFW_KEY_LEFT_SHIFT))
		direction += vec3(0.0f, -0.2f, 0.0f);

	camera->ProcessMouseMovement(this->input->getMouseXOffset(),
								 this->input->getMouseYOffset());
}
