/**
* @file ray.cpp
* @author Erik Sandrén
* @date 30-08-2016
* @brief ray class
*/

#include "ray.h"

Ray::Ray(glm::vec3 start, glm::vec3 direction) : start(start), direction(direction) {
  this->importance = Color(1.0, 1.0, 1.0);
  this->normalize();
}

Ray::Ray(glm::vec3 start, glm::vec3 direction, Color color) : Ray(start, direction) {
  this->importance = color;
}

Ray Ray::sampleHemisphere(glm::vec3 position, float u1, float u2) {

  float r =  sqrt(u1);
  float theta = 2 * M_PI * u2;

  float x = r * cos(theta);
  float y = r * sin(theta);
  float z = sqrt( 1-u1 > 0.0f ? 1 - u1 : 0.0f);

  glm::vec3 direction(x, y, z);

  return Ray(position, glm::normalize(direction-position));

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
