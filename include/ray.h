/**
* @file ray.h
* @author Erik Sandrén
* @date 30-08-2016
* @brief Ray class
*/

#ifndef __RAY_H__
#define __RAY_H__

#include "vertex.h"
#include "color.h"
#include "triangle.h"
#include "intersectable.h"

class Intersectable;

class Ray {
public:
  Ray(Vertex start, Vertex end, Color c);

  void setIntersection(Intersectable* intersect);
  float length();
  void normalize();

  Vertex start, end;
  Color color;
  float importance = 1.0f;

private:
  Intersectable* mIntersect;
};


#endif
