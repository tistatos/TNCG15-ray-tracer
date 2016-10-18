/**
* @file ray.h
* @author Erik Sandrén
* @date 30-08-2016
* @brief Ray class
*/

#ifndef __RAY_H__
#define __RAY_H__

#include <glm/glm.hpp>

#include "color.h"
#include "triangle.h"
#include "intersectable.h"

class Intersectable;

class Ray {
public:
  Ray(glm::vec3 start, glm::vec3 direction);

  static Ray sampleHemisphere(Ray radianceOut, glm::vec3 normal, float u1, float u2);
  void setIntersection(Intersectable* intersect);
  float length();
  void normalize();
  Ray reflect();

public:
  glm::vec3 start, direction;

private:
  Intersectable* mIntersect;
};

#endif
