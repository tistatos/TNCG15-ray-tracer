/**
* @file triangle.cpp
* @author Erik Sandrén
* @date 12-09-2016
* @brief [Description Goes Here]
*/

#include <gtest/gtest.h>
#include "triangle.h"
#include "vertex.h"
#include "ray.h"

TEST(triangle, Intersection) {

  Triangle t(
      Vertex(-1.0f, 0.5f, 0.0f),
      Vertex(-1.0f, 0.0f, 1.0f),
      Vertex(-1.0f, -0.5f, 0.0f),
      Color(1.0, 0.0, 0.0));

  Ray r(
      Vertex(0.0f, 0.0f, 0.0f),
      Vertex(-2.0f, 0.0f, 0.0f),
      Color(0.0, 0.0, 0.0) );

  float tOut = 0;
  bool intersected = false;
  intersected = t.rayIntersection(&r, tOut);

  EXPECT_TRUE(intersected) << "intersection is expected";
  EXPECT_FLOAT_EQ(tOut, 1.0f) << "Distance from ray origin to triangle should be 1";

  Ray r2(
      Vertex(0.0f, 0.0f, 0.0f),
      Vertex(-1.0f, 0.49f, 0.0f),
      Color(0.0, 0.0, 0.0) );

  tOut = 0;
  intersected = t.rayIntersection(&r2, tOut);

  EXPECT_TRUE(intersected) << "intersection is expected";
  EXPECT_GT(tOut, 1.0f) << "Distance from ray origin to triangle should be greater than 1";

  Ray r3(
      Vertex(0.0f, 0.0f, 0.0f),
      Vertex(1.0f, 0.49f, 0.0f),
      Color(0.0, 0.0, 0.0) );

  tOut = 0;
  intersected = t.rayIntersection(&r3, tOut);

  ASSERT_FALSE(intersected) << "intersection is expected";
}
