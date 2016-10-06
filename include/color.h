/**
* @file color.h
* @author Erik Sandrén
* @date 30-08-2016
* @brief Double precision color
*/

#ifndef __COLOR_H__
#define __COLOR_H__

class Color {
public:
  Color();
  Color(double r, double g, double b);
  double r, g, b;
  Color operator+(const Color b);
  Color operator*(const Color b);
  Color operator*(const float b);
};


#endif
