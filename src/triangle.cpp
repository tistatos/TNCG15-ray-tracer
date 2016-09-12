/**
* @file triangle.cpp
* @author Erik Sandrén
* @date 31-08-2016
* @brief [Description Goes Here]
*/

#include "triangle.h"
#include <iostream>

Triangle::Triangle() :
  mColor(0.0, 0.0, 0.0) { }

Triangle::Triangle(Vertex v0, Vertex v1, Vertex v2, Color c) :
  mV0(v0), mV1(v1), mV2(v2), mColor(c) { }

bool Triangle::rayIntersection(Ray* r, float &tOut) {
  Vertex T = r->start - mV0;
  Vertex E1 = mV1 - mV0;
  Vertex E2 = mV2 - mV0;
  Vertex D = r->end - r->start;

  Vertex P = glm::cross(D, E2);
  Vertex Q = glm::cross(T, E1);

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
