/**
* @file Quad.cpp
* @author Erik Sandrén
* @date 05-09-2016
* @brief [Description Goes Here]
*/

#include "quad.h"
#include "color.h"

Quad::Quad(glm::vec3 topRight, glm::vec3 topLeft, glm::vec3 bottomLeft, glm::vec3 bottomRight, Surface* surface) {
  mTriangles = new Triangle[2];
  this->surface = surface;

  mTriangles[0] = Triangle( topRight, topLeft, bottomRight);
  mTriangles[1] = Triangle( bottomLeft, bottomRight, topLeft);
}

Quad::~Quad() {
  delete surface;
  delete[] mTriangles;
}
bool Quad::rayIntersection(Ray* r, float &tOut) {
  bool intersects = mTriangles[0].rayIntersection(r, tOut) || mTriangles[1].rayIntersection(r, tOut);

  return intersects;
}

glm::vec3 Quad::getNormal(glm::vec3 position) {
  return mTriangles[0].getNormal(position);
}
