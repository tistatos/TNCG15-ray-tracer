/**
* @file ray.cpp
* @author Erik Sandrén
* @date 12-09-2016
* @brief [Description Goes Here]
*/

#include <gtest/gtest.h>
#include "ray.h"

TEST(Ray, length) {
  Ray r(
      glm::vec3(0.0f, 0.0f, 0.0f),
      glm::vec3(4.0f, 1.0f, 0.0f),
      Color(0.0, 0.0, 0.0)
      );

  EXPECT_FLOAT_EQ(r.length(), 1.0f) << "Ray length should always be 1";
}
