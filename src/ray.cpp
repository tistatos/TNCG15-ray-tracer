/**
* @file ray.cpp
* @author Erik Sandrén
* @date 30-08-2016
* @brief ray class
*/

#include "ray.h"

Ray::Ray(Vertex start, Vertex end, Color color) : start(start), end(end), color(color) {
  this->normalize();
}

void Ray::normalize() {
  this->end = glm::normalize(end-start);
}

void Ray::setIntersection(Intersectable* intersect) {
  mIntersect = intersect;
}

float Ray::length() {
  return glm::length(end-start);
}
