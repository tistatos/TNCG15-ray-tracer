/**
* @file color.cpp
* @author Erik Sandrén
* @date 30-08-2016
* @brief Double precision color
*/

#include "color.h"

Color::Color() : Color(1.0, 1.0, 1.0) { }

Color::Color(double r, double g, double b) : mR(r), mG(g), mB(b) { }
