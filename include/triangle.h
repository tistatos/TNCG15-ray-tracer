/**
* @file triangle.h
* @author Erik Sandrén
* @date 31-08-2016
* @brief [Description Goes Here]
*/

#ifndef __TRIANGLE_H__
#define __TRIANGLE_H__

#include <glm/glm.hpp>

#include "ray.h"
#include "color.h"
#include "intersectable.h"

class Triangle : public Intersectable {
public:
  Triangle();
  ~Triangle();
  Triangle(glm::vec3 v0, glm::vec3 v1, glm::vec3 v2);
  bool rayIntersection(Ray* r, float &tOut);
  glm::vec3 getPoint(float u, float v, glm::vec3 from);
  glm::vec3 mV0, mV1, mV2;
};

#endif
