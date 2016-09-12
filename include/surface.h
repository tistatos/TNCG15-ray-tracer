/**
* @file surface.h
* @author Erik Sandrén
* @date 05-09-2016
* @brief Quad surface of triangles
*/

#ifndef __SURFACE_H__
#define __SURFACE_H__

#include "sceneObject.h"

class Surface : public SceneObject {
public:
  Surface(Vertex topLeft, Vertex topRight, Vertex bottomLeft, Vertex bottomRight, Color color);

  bool rayIntersection(Ray* r, float &tOut);
};



#endif
