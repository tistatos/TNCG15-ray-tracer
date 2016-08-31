/**
* @file intersectable.h
* @author Erik Sandrén
* @date 31-08-2016
* @brief [Description Goes Here]
*/

#ifndef __INTERSECTABLE_H__
#define __INTERSECTABLE_H__

#include "ray.h"
#include "direction.h"

class Ray;

class Intersectable {
public:
  virtual bool rayIntersection(Ray* r) = 0;

protected:
  Direction mNormal;
};



#endif
