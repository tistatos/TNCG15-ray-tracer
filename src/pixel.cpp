/**
* @file pixel.cpp
* @author Erik Sandrén
* @date 05-09-2016
* @brief pixel class
*/

#include "pixel.h"

Pixel::Pixel() : mIntensity(0.0) { }
Pixel::Pixel(Color color, double intensity): color(color), mIntensity(intensity) { }

void Pixel::setColor(Color color) {
  this->color = color;
}
