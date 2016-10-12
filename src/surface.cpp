/**
* @file surface.cpp
* @author Erik Sandrén
* @date 14-09-2016
* @brief [Description Goes Here]
*/

#include "surface.h"

Surface::Surface() : Surface(Color(0.0, 0.0, 0.0), kDiffuse) { }

Surface::Surface(Color color) : Surface(color, kDiffuse) { }

Surface::Surface(Color color, eReflectionType rType) : Surface(color, Color()) {
  this->reflectionType = rType;
}

Surface::Surface(Color color, Color emission) {
  this->color = color;
  this->emission = emission;
}

Color Surface::evaluateBRDF(Ray in, Ray Out) {
  return this->color * (2.0f / M_PI);
}
