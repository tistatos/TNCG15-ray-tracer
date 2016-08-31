/**
* @file triangle.h
* @author Erik Sandrén
* @date 31-08-2016
* @brief [Description Goes Here]
*/

#ifndef __TRIANGLE_H__
#define __TRIANGLE_H__

#include "intersectable.h"
#include "color.h"

class Triangle : Intersectable {
public:
  Triangle(Vertex v0, Vertex v1, Vertex v2);
  Triangle(Vertex v0, Vertex v1, Vertex v2, Color c);
  bool rayIntersection(Ray* r) { return false; }

private:
  Color mColor;
  Vertex mV0, mV1, mV2;
};



#endif
