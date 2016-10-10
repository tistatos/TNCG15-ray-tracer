/**
* @file sphere.cpp
* @author Erik Sandrén
* @date 12-09-2016
* @brief [Description Goes Here]
*/

#include "sphere.h"
#include <cmath>
#include <iostream>

Sphere::Sphere(float radius, glm::vec3 position, Surface* surface) :
  mPosition(position), mRadius(radius) {
    this->surface = surface;
}

Sphere::~Sphere() {
  delete surface;
}
glm::vec3 Sphere::getNormal(glm::vec3 position) {
  return glm::normalize(position - mPosition);
}

bool Sphere::rayIntersection(Ray* ray, float &tOut) {
  glm::vec3 o = ray->start;
  glm::vec3 i = ray->direction;
  glm::vec3 c = mPosition;
  glm::vec3 oc = o - c;
  float r = mRadius;

  float b = glm::dot(i * 2.0f, oc);

  float d1 = -b/2.0f;
  float d2 = d1;

  float delta = d1*d1 - (glm::dot(oc, oc) - r*r);
  if(delta < -EPSILON) {
    return false; // complex solutions
  }
  else if( delta > -EPSILON && delta < EPSILON) {
    tOut = d1;
    return true;
  }

  float dSqrt = std::sqrt(delta);

  d1 -= dSqrt;
  d2 += dSqrt;

  if(d1 >= 0 ) {
    tOut = d1;
    return true;
  }

  else if(d2 >= 0) {
    tOut = d2;
    return true;
  }
  return false;
}
