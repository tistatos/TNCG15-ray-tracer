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

Ray Ray::sampleHemisphere(Ray radianceOut, glm::vec3 normal, float u1, float u2) {
  // test with perfect reflection
  //glm::vec3 reflected = glm::normalize(radianceOut.direction - 2.0f * glm::dot(normal, radianceOut.direction) * normal);
  //return Ray(radianceOut.start, reflected);

  glm::vec3 v1 = -glm::normalize(-radianceOut.direction - glm::dot(-radianceOut.direction, normal)*normal);
  glm::vec3 left = glm::cross(v1, normal);

  float r =  sqrt(u1);
  float theta = 2 * M_PI * u2;

  float x = r * cos(theta);
  float y = r * sin(theta);
  float z = sqrt( 1-u1 > 0.0f ? 1 - u1 : 0.0f);

  glm::vec3 direction = v1*x+left*y+normal*z;


  return Ray(radianceOut.start, glm::normalize(direction));

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
