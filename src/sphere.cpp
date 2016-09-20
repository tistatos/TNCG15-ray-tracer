/**
* @file sphere.cpp
* @author Erik Sandrén
* @date 12-09-2016
* @brief [Description Goes Here]
*/

#include "sphere.h"
#include <cmath>

Sphere::Sphere(float radius, Vertex position, Surface* surface) :
  mPosition(position), mRadius(radius) {
    this->surface = surface;
}

Sphere::~Sphere() {
  delete surface;
}

bool Sphere::rayIntersection(Ray* ray, float &tOut) {
  glm::vec3 o = ray->start;
  glm::vec3 i = ray->end;
  glm::vec3 c = mPosition;
  float r = mRadius;

  float b = glm::dot(2*i, o-c);
  float cCoeff = glm::dot(o-c,o-c) - r;

  float d1 = -b/2.0f;
  float d2 = d1;

  float delta = d1*d1 - cCoeff;
  if(delta < 0) {
    return false; // complex solutions
  }

  float dSqrt = std::sqrt(delta);

  d1 += dSqrt;
  d2 -= dSqrt;

  if(d1 < d2) {
    tOut = d1;
    return true;
  }
  else if(d2 < d1) {
    tOut = d2;
    return true;
  }
  else {
    tOut = d1;
    return true;
  }
}
