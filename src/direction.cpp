/**
* @file direction.cpp
* @author Erik Sandrén
* @date 30-08-2016
* @brief Direction for ray and normal
*/

#include "direction.h"

Direction::Direction() : Direction(1.0, 0.0, 0.0) { }

Direction::Direction(float x, float y, float z) : mX(x), mY(y), mZ(z) { }
