#include "../engine.h"

void Engine::processInput() {
	glfwPollEvents();
	input->update_keys(window);
	input->update_mouse(window);
	if (input->key_pressed(GLFW_KEY_Q))
		glfwSetWindowShouldClose(window, true);
}
