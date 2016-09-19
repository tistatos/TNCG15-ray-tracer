/**
* @file surface.h
* @author Erik Sandrén
* @date 14-09-2016
* @brief [Description Goes Here]
*/

#ifndef __SURFACE_H__
#define __SURFACE_H__

#include "color.h"
#include "vertex.h"
#include "glm/glm.hpp"

class Surface {
public:
  enum eReflectionType {
    kDiffuse,
    kSpecular,
    kRefraction,
  };

  Surface();
  Surface(Color c);
  Surface(Color c, eReflectionType rType);
  Surface(Color c, eReflectionType rType, Vertex emission);
  Color color;

private:
  eReflectionType mReflectionType;
  glm::vec3 mEmission;
};


#endif
