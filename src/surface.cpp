/**
* @file surface.cpp
* @author Erik Sandrén
* @date 05-09-2016
* @brief [Description Goes Here]
*/

#include "surface.h"
#include "vertex.h"
#include "color.h"

Surface::Surface(Vertex topRight, Vertex topLeft, Vertex bottomLeft, Vertex bottomRight, Color color) {
  mTriangles = new Triangle[2];
  mColor = color;

  mTriangles[0] = Triangle( topRight, topLeft, bottomRight, color);
  mTriangles[1] = Triangle( bottomLeft, bottomRight, topLeft, color);
}

bool Surface::rayIntersection(Ray* r, float &tOut) {
  bool intersects = mTriangles[0].rayIntersection(r, tOut) || mTriangles[1].rayIntersection(r, tOut);

  return intersects;
}
