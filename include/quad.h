/**
* @file Quad.h
* @author Erik Sandrén
* @date 05-09-2016
* @brief Quad Quad of triangles
*/

#ifndef __QUAD_H__
#define __QUAD_H__

#include "sceneObject.h"

class Quad : public SceneObject {
public:
  Quad(glm::vec3 topLeft, glm::vec3 topRight, glm::vec3 bottomLeft, glm::vec3 bottomRight, Surface* surface);
  ~Quad();

  glm::vec3 getNormal(glm::vec3 position);
  bool rayIntersection(Ray* r, float &tOut);
};



#endif
