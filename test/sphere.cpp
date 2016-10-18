/**
* @file sphere.cpp
* @author Erik Sandrén
* @date 16-09-2016
* @brief [Description Goes Here]
*/


#include <gtest/gtest.h>
#include "sphere.h"
#include "ray.h"

TEST(sphereTest, intersection) {
  Sphere s( 1.0f, glm::vec3(-5.0f, 0.0f, 0.0f), new Surface(Color(0.0,0.0,0.0)));
  Sphere s2( 2.0f, glm::vec3(-5.0f, 0.0f, 0.0f), new Surface(Color(0.0,0.0,0.0)));

  Ray r(glm::vec3(), glm::vec3(-1.0f, 0.f, 0.f));

  float tOut = 0;
  bool intersected = false;
  intersected = s.rayIntersection(&r, tOut);

  EXPECT_TRUE(intersected) << "Intersection with sphere expected";
  EXPECT_FLOAT_EQ(tOut, 4.0f) << "distance to sphere should be 4";

  tOut = 0;
  intersected = false;
  intersected = s2.rayIntersection(&r, tOut);
  //EXPECT_TRUE(intersected) << "Intersection with sphere expected";
  //EXPECT_FLOAT_EQ(tOut, 3.0f) << "distance to sphere should be 4";
}
