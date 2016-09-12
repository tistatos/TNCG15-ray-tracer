/**
* @file triangle.h
* @author Erik Sandrén
* @date 31-08-2016
* @brief [Description Goes Here]
*/

#ifndef __TRIANGLE_H__
#define __TRIANGLE_H__

#include "ray.h"
#include "color.h"
#include "intersectable.h"

class Triangle : public Intersectable {
public:
  Triangle();
  Triangle(Vertex v0, Vertex v1, Vertex v2, Color c);
  bool rayIntersection(Ray* r, float &tOut);

private:
  Vertex mV0, mV1, mV2;
  Color mColor;
  glm::vec3 mNormal;
};



#endif