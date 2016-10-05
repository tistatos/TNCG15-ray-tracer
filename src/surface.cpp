/**
* @file surface.cpp
* @author Erik Sandrén
* @date 14-09-2016
* @brief [Description Goes Here]
*/

#include "surface.h"

Surface::Surface() : Surface(Color(0.0, 0.0, 0.0), kDiffuse) { }

Surface::Surface(Color color) : Surface(color, kDiffuse) { }

Surface::Surface(Color color, eReflectionType rType) : Surface(color, glm::vec3()) {
  this->mReflectionType = rType;
}

Surface::Surface(Color color, glm::vec3 emission) {
  this->color = color;
  this->mEmission = emission;
}
bool Surface::reflect(Ray& in, Ray& reflect, Ray& refract) {
  if(mReflectionType == kRefraction) {
  }
  else if(mReflectionType == kSpecular) {
  }
  else if(mReflectionType == kDiffuse) {
  }

  return true;
}
