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

  Vertex start, end;
  Color color;
private:
  Intersectable* mIntersect;
};


#endif
