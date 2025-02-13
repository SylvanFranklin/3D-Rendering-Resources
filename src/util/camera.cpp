#include "camera.hpp"

Camera::Camera(glm::vec3 Pos, glm::vec3 Up, float Yaw, float Pitch)
	: pos(Pos), worldUp(Up), yaw(Yaw), pitch(Pitch),
	  mouse_sensitivity(SENSITIVITY), fov(FOV), velocity(0), acceleration(0),
	  render_distance(RENDER_DISTANCE) {
	updateCameraVectors();
}
Camera::Camera()
	: pos(POSITION), worldUp(WORLD_UP), yaw(YAW), pitch(PITCH),
	  mouse_sensitivity(SENSITIVITY), fov(FOV), velocity(0), acceleration(0),
	  render_distance(RENDER_DISTANCE) {
	updateCameraVectors();
}

// Get matrices
glm::mat4 Camera::GetViewMatrix() { return glm::lookAt(pos, pos + front, up); }

glm::mat4 Camera::GetProjectionMatrix(float width, float height) {
	return glm::perspective(glm::radians(fov),
							static_cast<float>(width) / height, 0.1f,
							render_distance);
}

// Keyboard processing
void Camera::move(glm::vec3 direction, bool lockY) {
	if (lockY) {
		direction.y = 0;
	}
	// move in terms of the camera's right and forward vectors
	pos += direction.x * right;
	pos += direction.y * glm::vec3(0.0f, 1.0f, 0.0f);
	pos += direction.z * front;
}

// Mouse processing
void Camera::ProcessMouseMovement(float xoffset, float yoffset,
								  GLboolean constrainPitch) {
	xoffset *= mouse_sensitivity;
	yoffset *= mouse_sensitivity;
	yaw += xoffset;
	pitch += yoffset;

	// Clamp pitch
	if (constrainPitch) {
		if (pitch > PITCH_LIMIT)
			pitch = PITCH_LIMIT;
		if (pitch < -PITCH_LIMIT)
			pitch = -PITCH_LIMIT;
	}

	updateCameraVectors();
}

void Camera::updateCameraVectors() {
	glm::vec3 newFront;
	newFront.x = cos(glm::radians(yaw)) * cos(glm::radians(pitch));
	newFront.y = sin(glm::radians(pitch));
	newFront.z = sin(glm::radians(yaw)) * cos(glm::radians(pitch));
	front = glm::normalize(newFront);
	right = glm::normalize(glm::cross(front, worldUp));
	up = glm::normalize(glm::cross(right, front));
}
