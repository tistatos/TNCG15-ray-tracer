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
  Quad(Vertex topLeft, Vertex topRight, Vertex bottomLeft, Vertex bottomRight, Surface* surface);
  ~Quad();

  bool rayIntersection(Ray* r, float &tOut);
};



#endif
