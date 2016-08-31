/**
* @file vertex.cpp
* @author Erik Sandrén
* @date 30-08-2016
* @brief Vertex class
*/

#include "vertex.h"
Vertex::Vertex() : Vertex(0.0, 0.0, 0.0, 1.0) { }

Vertex::Vertex(float x, float y, float z) : Vertex(x, y, z, 1.0) { }

Vertex::Vertex(float x, float y, float z, float w) : mX(x), mY(y), mZ(z), mW(w) { }
