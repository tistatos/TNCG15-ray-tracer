/**
* @file surface.cpp
* @author Erik Sandrén
* @date 14-09-2016
* @brief [Description Goes Here]
*/

#include "surface.h"
#include <algorithm>

Surface::Surface() : Surface(Color(0.0, 0.0, 0.0), kLambert) { }

Surface::Surface(Color color) : Surface(color, kLambert) { }

Surface::Surface(Color color, eReflectionType rType) : Surface(color, Color()) {
  this->reflectionType = rType;
}

Surface::Surface(Color color, Color emission) {
  this->color = color;
  this->emission = emission;
  this->sigma2 = 0.0f;
  this->reflectCoefficient = 0.8f;
}

Color Surface::evaluateBRDF(Ray in, Ray out, glm::vec3 normal) {
  if(reflectionType == kLambert)
    return evaluateBRDFLambertian();
  else
    return evaluateBRDFOrenNayar(in, out, normal);
}

Color Surface::evaluateBRDFLambertian() {
  return this->color * reflectCoefficient / M_PI;
}

Color Surface::evaluateBRDFOrenNayar(Ray in, Ray out, glm::vec3 normal) {

  float thetaIn = acos(glm::dot(-in.direction, normal));
  float thetaOut = acos(glm::dot(out.direction, normal));

  float A = 1.0f - 0.5f * (sigma2 / (sigma2 + 0.57f));
  float B = 0.45f * sigma2 / (sigma2 + 0.09f);

  float alpha = std::max(thetaIn, thetaOut);
  float beta = std::min(thetaIn, thetaOut);

  float orenNayar =  reflectCoefficient / M_PI * (A + B * std::max(0.0f, glm::dot(-in.direction, out.direction)) * sin(alpha) * sin(beta));

  return this->color * orenNayar;
}
