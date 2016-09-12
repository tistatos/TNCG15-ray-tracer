/**
* @file intersectable.h
* @author Erik Sandrén
* @date 31-08-2016
* @brief [Description Goes Here]
*/

#ifndef __INTERSECTABLE_H__
#define __INTERSECTABLE_H__

#include "ray.h"

#define EPSILON 0.000001

class Ray;

class Intersectable {
public:
  virtual bool rayIntersection(Ray* r, float &tOut) = 0;
};



#endif
