/**
* @file math.h
* @author Erik Sandrén
* @date 30-08-2016
* @brief [Description Goes Here]
*/

#ifndef __MATH_H__
#define __MATH_H__

template<class T> class Vector2 {
public:
  Vector2(T x, T y);
  T x, y;
};

template<class T> class Vector3 {
public:
  Vector3(T x, T y, T z);
  T x, y, z;
};
#endif
