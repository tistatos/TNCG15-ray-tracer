/**
* @file triangle.cpp
* @author Erik Sandrén
* @date 31-08-2016
* @brief [Description Goes Here]
*/

#include "triangle.h"

Triangle::Triangle(Vertex v0, Vertex v1, Vertex v2) : Triangle(v0, v1, v2, Color()) { }

Triangle::Triangle(Vertex v0, Vertex v1, Vertex v2, Color c) : mV0(v0), mV1(v1), mV2(v2), mColor(c){ }
