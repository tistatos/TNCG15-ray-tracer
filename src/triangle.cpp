/**
* @file triangle.cpp
* @author Erik Sandrén
* @date 31-08-2016
* @brief [Description Goes Here]
*/

#include "triangle.h"
#include <iostream>

Triangle::Triangle() { }

Triangle::Triangle(glm::vec3 v0, glm::vec3 v1, glm::vec3 v2) :
  mV0(v0), mV1(v1), mV2(v2) {
    mNormal = glm::normalize(glm::cross(v0-v2, v1-v2));
}

Triangle::~Triangle() {
  //delete surface;
}

bool Triangle::rayIntersection(Ray* r, float &tOut) {
  glm::vec3 T = r->start - mV0;
  glm::vec3 E1 = mV1 - mV0;
  glm::vec3 E2 = mV2 - mV0;
  glm::vec3 D = r->direction;

  glm::vec3 P = glm::cross(D, E2);
  glm::vec3 Q = glm::cross(T, E1);

  float det = glm::dot(P, E1);

  if(det > -EPSILON && det < EPSILON)
    return false;

  float inverseDet = 1.0f/det;

  float u = glm::dot(T, P) * inverseDet;
  float v = glm::dot(D, Q) * inverseDet;

  if(u < 0.0f || u > 1.0f) {
    return false;
  }

  if(v < 0.0f || u + v > 1.0f) {
    return false;
  }

  float t = glm::dot(Q, E2) * inverseDet;
  tOut = t;

  if(t > EPSILON) {
    return true;
  }

  return false;
}
