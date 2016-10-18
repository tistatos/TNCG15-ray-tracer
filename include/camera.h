/**
* @file camera.h
* @author Erik Sandrén
* @date 05-09-2016
* @brief [Description Goes Here]
*/

#ifndef __CAMERA_H__
#define __CAMERA_H__
#include <glm/gtc/matrix_transform.hpp>
#include <random>

#include "pixel.h"
#include "scene.h"

const int CAMERA_RESOLUTION = 1000;

class Camera {
public:
  Camera(glm::vec3 position, int width, int height, glm::mat4 perspective);
  Ray castRay(float x, float y, float sx, float sy, float subSamples);

private:
  std::mt19937 mEngine;
  std::uniform_real_distribution<float> mRng;
  glm::vec3 mPosition;
  glm::mat4 mInverseViewPerspective;
  int mWidth;
  int mHeight;
};



#endif
