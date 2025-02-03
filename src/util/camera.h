#ifndef CAMERA_H
#define CAMERA_H

#include <glad/glad.h>
#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>

// Enum explicitly defined for size consistency
enum Camera_Movement : uint8_t { FORWARD, BACKWARD, LEFT, RIGHT, UP, DOWN };

// Constants
const float PITCH = -30.0f;
const float YAW = -300.0f;
const float FOV = 45.0f;
const float SENSITIVITY = 0.1f;
const float PITCH_LIMIT = 89.0f;
const float RENDER_DISTANCE = 300.0f;
const glm::vec3 WORLD_UP = glm::vec3(0.0f, 1.0f, 0.0f);
const glm::vec3 POSITION = glm::vec3(0.0f, 20.0f, 0.0f);

class Camera {
public:
  glm::vec3 pos;
  glm::vec3 front;
  glm::vec3 up;
  glm::vec3 right;
  glm::vec3 worldUp;

  float yaw;
  float pitch;
  float mouse_sensitivity;
  float velocity;
  float acceleration;
  float fov;
  float render_distance;

  // Constructor
  Camera(glm::vec3 Pos, glm::vec3 Up, float Yaw, float Pitch);
  Camera();

  // Get matrices
  glm::mat4 GetViewMatrix();
  glm::mat4 GetProjectionMatrix(float width, float height);

  void move(glm::vec3 direction, bool lockY = false);

  void ProcessMouseMovement(float xoffset, float yoffset,
                            GLboolean constrainPitch = true);

private:
  void updateCameraVectors();
};

#endif
