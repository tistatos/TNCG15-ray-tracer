/**
* @file surface.cpp
* @author Erik Sandrén
* @date 14-09-2016
* @brief [Description Goes Here]
*/

#include "surface.h"
#include <algorithm>
#include "utils.h"

Surface::Surface() : Surface(Color(0.0, 0.0, 0.0), kLambert) { }

Surface::Surface(Color color) : Surface(color, kLambert) { }

Surface::Surface(Color color, eReflectionType rType) : Surface(color, Color()) {
  this->reflectionType = rType;
}

Surface::Surface(Color color, Color emission) {
  this->color = color;
  this->emission = emission;
}

Color Surface::evaluateBRDF(Ray in, Ray out, glm::vec3 normal) {
  if(reflectionType == kLambert)
    return evaluateBRDFLambertian();
  else
    return evaluateBRDFOrenNayar(in, out, normal);
}

Color Surface::evaluateBRDFLambertian() {
  return this->color * reflectCoefficient;
}

#include<iostream>
Color Surface::evaluateBRDFOrenNayar(Ray in, Ray out, glm::vec3 normal) {
  //theta inclination
  //phi azimuth
  glm::vec3 inSphere = cartesianToSpherical(-in.direction);
  glm::vec3 outSphere = cartesianToSpherical(out.direction);
  float sigma2 = 0.3f;

  float phiIn = inSphere.y;
  float thetaIn = acos(glm::dot(-in.direction, normal));
  float phiOut = outSphere.y;
  float thetaOut = acos(glm::dot(out.direction, normal));

  float A = 1.0f - (sigma2) / (2.0f*(sigma2 + 0.33f));
  float B = 0.45f * (sigma2) / (sigma2 + 0.09f);

  float alpha = std::max(thetaIn, thetaOut);
  float beta = std::min(thetaIn, thetaOut);

  float on =  reflectCoefficient * (A + B * std::max(0.0f, glm::dot(-in.direction,out.direction)) * sin(alpha) * tan(beta));
  return this->color * on;
}
