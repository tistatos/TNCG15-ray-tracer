/**
* @file direction.h
* @author Erik Sandrén
* @date 30-08-2016
* @brief Direction for ray and normal
*/

#ifndef __DIRECTION_H__
#define __DIRECTION_H__

class Direction {
public:
  Direction();
  Direction(float x, float y, float z);
  float mX, mY, mZ;
};

#endif
