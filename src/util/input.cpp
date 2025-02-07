#include "../engine.h"

void Engine::processInput() {
	glfwPollEvents();
	input->update_keys(window);
	input->update_mouse(window);
	if (input->key_pressed(GLFW_KEY_Q))
		glfwSetWindowShouldClose(window, true);

	if (input->key_pressed(GLFW_KEY_W))
		camera->move(glm::vec3(0, 1.0, 1.0));
	camera->ProcessMouseMovement(this->input->getMouseXOffset(),
								 this->input->getMouseYOffset());

}
