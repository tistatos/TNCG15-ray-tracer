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
  Sphere(float radius, glm::vec3 position, Surface* s);
  ~Sphere();
  bool rayIntersection(Ray* r, float &tOut);
  glm::vec3 getNormal(glm::vec3 position);
  glm::vec3 getPoint(float u, float v, glm::vec3 from);
  float getArea();

private:
  glm::vec3 mPosition;
  float mRadius;
};


#endif
