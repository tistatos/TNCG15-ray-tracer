/**
* @file color.cpp
* @author Erik Sandrén
* @date 30-08-2016
* @brief Double precision color
*/

#include "color.h"

Color::Color() : Color(0.0, 0.0, 0.0) { }
Color::Color(double r, double g, double b) : r(r), g(g), b(b) { }
