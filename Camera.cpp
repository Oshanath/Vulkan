#include "Camera.h"

#include <glm/gtc/matrix_transform.hpp>

glm::mat4 Camera::getViewMatrix() {
  right = glm::cross(direction, glm::vec3(0.0f, 0.0f, 1.0f));
  up = glm::cross(right, direction);
  return glm::lookAt(position, position + direction, up);
}