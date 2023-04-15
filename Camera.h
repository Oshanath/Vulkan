#ifndef CAMERA_H
#define CAMERA_H

#include <glm/glm.hpp>

class Camera{
public:
    glm::vec3 position;
    glm::vec3 direction;
    glm::vec3 up;
    glm::vec3 right;

    glm::mat4 getViewMatrix();
};

#endif // CAMERA_H