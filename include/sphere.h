/**
* @file sphere.h
* @author Erik Sandrén
* @date 12-09-2016
* @brief [Description Goes Here]
*/

#ifndef __SPHERE_H__
#define __SPHERE_H__

#include "sceneObject.h"

class Sphere : public SceneObject {
public:
  Sphere(float radius, Vertex position, Surface* s);
  bool rayIntersection(Ray* r, float &tOut);

private:
  Vertex mPosition;
  float mRadius;
};


#endif
