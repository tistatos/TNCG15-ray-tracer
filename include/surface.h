/**
* @file surface.h
* @author Erik Sandrén
* @date 14-09-2016
* @brief [Description Goes Here]
*/

#ifndef __SURFACE_H__
#define __SURFACE_H__

#include "ray.h"
#include "color.h"
#include "glm/glm.hpp"

class Ray;
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
  Surface(Color c, Color emission);

  Color color;
  Color emission;

  const float glassRefract = 1.5f;
  eReflectionType reflectionType;
};


#endif
