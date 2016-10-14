/**
* @file utils.h
* @author Erik Sandrén
* @date 10-10-2016
* @brief [Description Goes Here]
*/

#ifndef __UTILS_H__
#define __UTILS_H__

#include <glm/glm.hpp>

inline glm::vec3 cartesianToSpherical(glm::vec3 c) {
  float cx2 = c.x * c.x;
  float cy2 = c.y * c.y;

  float r = sqrt(cx2 + cy2 + c.z * c.z);
  float phi = atan2(c.y, c.x);
  float theta = atan2(sqrt(cx2 + cy2), c.z);

  return glm::vec3(r, phi, theta);
}

inline glm::vec3 sphericalToCartesian(glm::vec3 s) {
  float sinPhi = sin(s.y);
  float cosPhi = cos(s.y);
  float sinTheta = sin(s.z);

  float x = s.x * cosPhi * sinTheta;
  float y = s.x * sinPhi * sinTheta;
  float z = s.x * cos(s.z);
  return glm::vec3(x, y, z);
}


#endif
