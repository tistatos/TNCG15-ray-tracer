/**
* @file surface.h
* @author Erik Sandrén
* @date 14-09-2016
* @brief [Description Goes Here]
*/

#ifndef __SURFACE_H__
#define __SURFACE_H__

#include "ray.h"
#include "color.h"
#include "glm/glm.hpp"

class Ray;
class Surface {
public:
  enum eReflectionType {
    kLambert,
    kOrenNayar,
    kSpecular,
    kRefraction,
  };

  Surface();
  Surface(Color c);
  Surface(Color c, eReflectionType rType);
  Surface(Color c, Color emission);

  Color evaluateBRDF(Ray in, Ray out, glm::vec3 normal);
  Color color;
  Color emission;

  float reflectCoefficient = 2.0f;
  float sigma2 = 1.0f;

  eReflectionType reflectionType;
private:
  Color evaluateBRDFOrenNayar(Ray in, Ray out, glm::vec3 normal);
  Color evaluateBRDFLambertian();
};


#endif
