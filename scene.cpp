#include "scene.h"

#include <glm/gtc/matrix_transform.hpp>

Object::Object(std::string modelPath, std::string texturePath)
    : modelPath(modelPath), texturePath(texturePath) {}

glm::mat4 Object::getModelMatrix() {
  glm::mat4 model = glm::mat4(1.0f);
  model = glm::translate(model, position);
  model = model * glm::mat4_cast(rotation);
  model = glm::scale(model, scale);
  return model;
}