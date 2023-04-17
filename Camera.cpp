#include "Camera.h"
#include <iostream>

#include <glm/gtc/matrix_transform.hpp>

glm::mat4 Camera::getViewMatrix() {
  // right = glm::normalize(glm::cross(direction, glm::vec3(0.0f, 0.0f, 1.0f)));
  // std::cout << "direction " << direction.x << " " << direction.y << " " << direction.z << std::endl;
  right = glm::normalize(glm::cross(direction, glm::vec3(0.0f, 1.0f, 0.0f)));
  // std::cout << "right " << right.x << " " << right.y << " " << right.z << std::endl;
  up = glm::normalize(glm::cross(right, direction));
  // std::cout << "up " << up.x << " " << up.y << " " << up.z << std::endl;
  return glm::lookAt(position, position + direction, up);
  // return glm::lookAt(position, position + direction, glm::vec3(0.0f, 1.0f, 0.0f));
  // std::cout << "\n";
}