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
  return this->color * (reflectCoefficient / M_PI);
}

Color Surface::evaluateBRDFOrenNayar(Ray in, Ray out, glm::vec3 normal) {
  //theta inclination
  //phi azimuth
  glm::vec3 inSphere = cartesianToSpherical(-in.direction);
  glm::vec3 outSphere = cartesianToSpherical(out.direction);
  float sigma = 2.0f;

  float phiIn = inSphere.x;
  float thetaIn = inSphere.z;
  float thetaOut = outSphere.z;
  float phiOut = outSphere.x;

  float A = 1.0f - (sigma*sigma) / (2.0f*(sigma*sigma + 0.33f));
  float B = 0.45f * (sigma*sigma) / (2.0f*(sigma*sigma + 0.09f));

  float alpha = std::max(thetaIn, thetaOut);
  float beta = std::min(thetaIn, thetaOut);

  return this->color * reflectCoefficient/M_PI * (A+B * std::max(0.0, cos(phiIn-phiOut)) * sin(alpha) * tan(beta));
}
