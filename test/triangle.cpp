/**
* @file triangle.cpp
* @author Erik Sandrén
* @date 12-09-2016
* @brief [Description Goes Here]
*/

#include <gtest/gtest.h>
#include <glm/glm.hpp>
#include "triangle.h"
#include "ray.h"

TEST(triangle, Intersection) {

  Triangle t(
      glm::vec3(-1.0f, 0.5f, 0.0f),
      glm::vec3(-1.0f, 0.0f, 1.0f),
      glm::vec3(-1.0f, -0.5f, 0.0f));

  Ray r(
      glm::vec3(0.0f, 0.0f, 0.0f),
      glm::vec3(-2.0f, 0.0f, 0.0f),
      Color(0.0, 0.0, 0.0) );

  float tOut = 0;
  bool intersected = false;
  intersected = t.rayIntersection(&r, tOut);

  EXPECT_TRUE(intersected) << "intersection is expected";
  EXPECT_FLOAT_EQ(tOut, 1.0f) << "Distance from ray origin to triangle should be 1";

  Ray r2(
      glm::vec3(0.0f, 0.0f, 0.0f),
      glm::vec3(-1.0f, 0.49f, 0.0f),
      Color(0.0, 0.0, 0.0) );

  tOut = 0;
  intersected = t.rayIntersection(&r2, tOut);

  EXPECT_TRUE(intersected) << "intersection is expected";
  EXPECT_GT(tOut, 1.0f) << "Distance from ray origin to triangle should be greater than 1";

  Ray r3(
      glm::vec3(0.0f, 0.0f, 0.0f),
      glm::vec3(1.0f, 0.49f, 0.0f),
      Color(0.0, 0.0, 0.0) );

  tOut = 0;
  intersected = t.rayIntersection(&r3, tOut);

  ASSERT_FALSE(intersected) << "intersection not expected";
}

TEST(triangle, normal) {
  Triangle t(
      glm::vec3(10.0f, 6.0f, 5.0f),
      glm::vec3(0.0f, 6.0f, 5.0f),
      glm::vec3(10.0f, 6.0f, -5.0f));

  glm::vec3 normal = t.getNormal(glm::vec3());


  EXPECT_FLOAT_EQ(normal.x, 0.0f) << "Normal of triangle should only have y part";
  EXPECT_FLOAT_EQ(normal.y, -1.0f) << "Normal of triangle should only have y part";
  EXPECT_FLOAT_EQ(normal.z, 0.0f) << "Normal of triangle should only have y part";
}
