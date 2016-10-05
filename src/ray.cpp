/**
* @file ray.cpp
* @author Erik Sandrén
* @date 30-08-2016
* @brief ray class
*/

#include "ray.h"

Ray::Ray(glm::vec3 start, glm::vec3 direction) : start(start), direction(direction) {
  this->normalize();
}

Ray::Ray(glm::vec3 start, glm::vec3 direction, Color color) : Ray(start, direction) {
  this->color = color;
}

void Ray::normalize() {
  direction = glm::normalize(direction);
}

void Ray::setIntersection(Intersectable* intersect) {
  mIntersect = intersect;
}

float Ray::length() {
  return glm::length(direction);
}
