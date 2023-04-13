#ifndef SCENE_H
#define SCENE_H

#include <glm/glm.hpp>
#include <glm/gtx/quaternion.hpp>
#include <string>
#include <vector>

struct Object {
  glm::vec3 position;
  glm::quat rotation;
  glm::vec3 scale;
  std::string modelPath;
  std::string texturePath;

  Object(std::string modelPath, std::string texturePath);
  glm::mat4 getModelMatrix();
};

struct Scene {
 public:
  std::vector<Object> objects;
};

#endif  // SCENE_H