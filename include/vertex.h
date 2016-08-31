/**
* @file vertex.h
* @author Erik Sandrén
* @date 30-08-2016
* @brief Vertex class
*/

#ifndef __VERTEX_H__
#define __VERTEX_H__

class Vertex {
public:
  Vertex();
  Vertex(float x, float y, float z);
  Vertex(float x, float y, float z, float w);
  float mX, mY, mZ, mW;
};


#endif
