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

class Ray {
public:
  Ray(Vertex start, Vertex end);
  Ray(Vertex start, Vertex end, Color c);

  void setIntersection(Intersectable* intersect) { mIntersect = intersect; }
private:
  Vertex mStart, mEnd;
  Color mColor;
  Intersectable* mIntersect;
};


#endif
