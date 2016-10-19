/**
* @file intersectable.h
* @author Erik Sandrén
* @date 31-08-2016
* @brief [Description Goes Here]
*/

#ifndef __INTERSECTABLE_H__
#define __INTERSECTABLE_H__
#include "surface.h"
#include "ray.h"

#define EPSILON 1e-5f


class Ray;
class Surface;

class Intersectable {
public:
  virtual ~Intersectable() { }
  virtual bool rayIntersection(Ray* r, float &tOut) = 0;
  virtual glm::vec3 getNormal(glm::vec3 position) { return mNormal; }
  virtual glm::vec3 getPoint(float u, float v, glm::vec3 from) = 0;
public:
  Surface* surface;
protected:
  glm::vec3 mNormal;
};



#endif
