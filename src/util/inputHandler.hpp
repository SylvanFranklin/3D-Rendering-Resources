#ifndef INPUTHANDLER_H
#define INPUTHANDLER_H

#include <GLFW/glfw3.h>
#include <algorithm>
#include <glm/glm.hpp>
#include <iterator>

class InputHandler {

  public:
	InputHandler(GLFWwindow *window);
	void update_mouse();
	void update_keys();
	bool key_pressed(int key) { return keys[key]; }
	bool key_pressed_released(int key) { return !keys[key] && last_keys[key]; }
	glm::vec2 get_mouse_pos();

  private:
	bool keys[1024];
	bool last_keys[1024];
	double lastMouseX, lastMouseY, MouseXOffset, MouseYOffset;
	GLFWwindow *window;
	bool firstMouse = true;
};

#endif // INPUTHANDLER_H
