/**
* @file camera.cpp
* @author Erik Sandrén
* @date 05-09-2016
* @brief Camera to cast rays from
*/

#include "camera.h"
#include "sceneObject.h"

#include <stdio.h>
#include <cstdlib>
#include <iostream>
#include <cmath>

Camera::Camera(glm::vec3 position, int width, int height, glm::mat4 perspective)
  : mPosition(position),
   mWidth(width),
   mHeight(height) {
    glm::mat4 view = glm::lookAt(position, glm::vec3(1.0f,0.0f,0.0f), glm::vec3(0.0f,0.0f,1.0f));
    mInverseViewPerspective = glm::inverse(perspective*view);
}


Ray Camera::castRay(float x, float y)  const {
  float xNDC = (2.0f * x) / mWidth - 1.0f;
  float yNDC = 1.0f - (2.0f * y) / mHeight;
  float zNDC = 1.0f;

  glm::vec4 end = mInverseViewPerspective * glm::vec4(xNDC, yNDC, zNDC, 1.0f);
  end = glm::normalize(end);

  glm::vec3 rayEnd(end.x, end.y, end.z);

  Ray r(mPosition, rayEnd);
  return r;
}
