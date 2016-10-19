/**
* @file sceneobject.h
* @author Erik Sandrén
* @date 05-09-2016
* @brief [Description Goes Here]
*/

#ifndef __SCENEOBJECT_H__
#define __SCENEOBJECT_H__

#include "triangle.h"
#include "ray.h"
#include "intersectable.h"
#include "surface.h"

class SceneObject : public Intersectable {
public:
  Color getColor() { return surface->color; }
  virtual bool rayIntersection(Ray* r, float &tOut) = 0;
  glm::vec3 getPoint(float u, float v, glm::vec3 from) = 0;
  virtual float getArea() = 0;
protected:
  Triangle* mTriangles;
};


#endif
