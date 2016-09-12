/**
* @file pixel.h
* @author Erik Sandrén
* @date 05-09-2016
* @brief Pixel class
*/

#ifndef __PIXEL_H__
#define __PIXEL_H__

#include "color.h"
#include "ray.h"

class Pixel {
public:
  Pixel();
  Pixel(Color color, double intensity);
  void setRay(Ray* ray);
  void setColor(Color c);
  Ray* ray;
  Color color;
private:
  double mIntensity;
};


#endif
