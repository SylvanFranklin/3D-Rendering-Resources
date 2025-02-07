#ifndef INPUTHANDLER_H
#define INPUTHANDLER_H

#include <GLFW/glfw3.h>
#include <algorithm>
#include <iterator>

class InputHandler {

  public:
	InputHandler() {};
	// InputHandler(GLFWwindow *window) : window(window) {};

	void update_mouse(GLFWwindow *window) {
		double mouseX, mouseY;
		glfwGetCursorPos(window, &mouseX, &mouseY);

		// we do this to not stap the camera around
		if (this->firstMouse) {
			lastMouseX = mouseX;
			lastMouseY = mouseY;
			this->firstMouse = false;
		}
		MouseXOffset = mouseX - lastMouseX;
		MouseYOffset = lastMouseY - mouseY;
		lastMouseX = mouseX;
		lastMouseY = mouseY;
	}

	void update_keys(GLFWwindow *window) {
		std::copy(std::begin(keys), std::end(keys), std::begin(last_keys));
		for (int key = 0; key < 1024; ++key) {
			if (glfwGetKey(window, key) == GLFW_PRESS)
				keys[key] = true;
			else if (glfwGetKey(window, key) == GLFW_RELEASE)
				keys[key] = false;
		}
	};

	bool key_pressed(int key) { return keys[key]; }
	bool key_pressed_released(int key) { return !keys[key] && last_keys[key]; }
	float getMouseXOffset() { return MouseXOffset; }
	float getMouseYOffset() { return MouseYOffset; }
	float lastMouseX, lastMouseY, MouseXOffset, MouseYOffset;

  private:
	bool keys[1024];
	bool last_keys[1024];
	bool firstMouse = true;
};

#endif // INPUTHANDLER_H
