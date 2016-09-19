/**
* @file surface.cpp
* @author Erik Sandrén
* @date 14-09-2016
* @brief [Description Goes Here]
*/

#include "surface.h"

Surface::Surface() : Surface(Color(0.0, 0.0, 0.0), kDiffuse) { }

Surface::Surface(Color color) : Surface(color, kDiffuse, Vertex()) { }

Surface::Surface(Color color, eReflectionType rType) : Surface(color, rType, Vertex()) { }

Surface::Surface(Color color, eReflectionType rType, Vertex emission) {
  this->color = color;
  this->mReflectionType = rType;
  this->mEmission = emission;
}
