/**
* @file ray.cpp
* @author Erik Sandrén
* @date 12-09-2016
* @brief [Description Goes Here]
*/

#include <gtest/gtest.h>
#include <random>
#include "ray.h"

TEST(Ray, length) {
  Ray r(
      glm::vec3(0.0f, 0.0f, 0.0f),
      glm::vec3(0.0f, 1.0f, 0.0f));

  EXPECT_FLOAT_EQ(r.length(), 1.0f) << "Ray length should always be 1";
}

TEST(Ray, hemisphereSample) {
  Ray r(
      glm::vec3(0.0f, 0.0f, 0.0f),
      glm::vec3(1.0f, 1.0f, 0.0f));

  Triangle tri(
      glm::vec3(2.0f, 5.0f, -2.0f),
      glm::vec3(2.0f, -5.0f, -2.0f),
      glm::vec3(2.0f, 0.0f, 2.0f));

  float t = 0.0f;
  bool intersection = tri.rayIntersection(&r, t);

  ASSERT_TRUE(intersection) << "Ray must intersect";


  glm::vec3 intersectionPoint = r.start + r.direction * t;

  std::random_device rd;
  std::mt19937 engine(rd());
  std::uniform_real_distribution<float> rng(0.0f, 1.0f);
  for (unsigned int i = 0; i < 100; ++i) {
    float u1 = rng(engine);
    float u2 = rng(engine);
    Ray mcRay = Ray::sampleHemisphere(intersectionPoint, u1, u2);
    EXPECT_LT(mcRay.direction.x, 0.0f) << "should not bounce thru triangle";
  }
}
