/**
* @file surface.cpp
* @author Erik Sandrén
* @date 14-09-2016
* @brief [Description Goes Here]
*/

#include "surface.h"
#include <iostream>

Surface::Surface() : Surface(Color(0.0, 0.0, 0.0), kDiffuse) { }

Surface::Surface(Color color) : Surface(color, kDiffuse) { }

Surface::Surface(Color color, eReflectionType rType) : Surface(color, Vertex()) {
  this->mReflectionType = rType;
}

Surface::Surface(Color color, Vertex emission) {
  this->color = color;
  this->mEmission = emission;
}
