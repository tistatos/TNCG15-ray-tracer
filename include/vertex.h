/**
* @file vertex.h
* @author Erik Sandrén
* @date 30-08-2016
* @brief Vertex class
*/

#ifndef __VERTEX_H__
#define __VERTEX_H__

#include <glm/glm.hpp>
#include <glm/ext.hpp>
#include <iostream>

typedef glm::vec3 Vertex;

//class Vertex {
//public:
  //Vertex(float x, float y, float z);
  //Vertex operator+(const Vertex &b) { return Vertex(x + b.x, y + b.y, z + b.z); }
  //Vertex operator-(const Vertex &b) { return Vertex(x - b.x, y - b.y, z - b.z); }
  //Vertex operator*(const double scalar) { return Vertex(x * scalar, y * scalar, z * scalar);}
  //Vertex operator*(const Vertex &b) { return Vertex(x * b.x, y * b.y, z * b.z); }
  //double dot(const Vertex &b) { return x * b.x + y * b.y + z * b.z; }
  //Vertex cross(const Vertex &b) { return Vertex(b.z-z*b.y,z*b.x-x*b.z,x*b.y-y*b.x); }
  //void normalize();
  //float length();

  //float x, y, z;

//};


#endif
