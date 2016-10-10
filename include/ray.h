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
  Ray(glm::vec3 start, glm::vec3 direction, Color c);

  void setIntersection(Intersectable* intersect);
  float length();
  void normalize();
  Ray reflect();

public:
  glm::vec3 start, direction;
  Color importance;

private:
  Intersectable* mIntersect;
};

#endif
