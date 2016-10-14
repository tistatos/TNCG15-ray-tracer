
#include <gtest/gtest.h>
#include "utils.h"

TEST(util, sphericalToCartesian) {
  glm::vec3 spherical(1.0f, 0.0f, M_PI/2);

  glm::vec3 cart = sphericalToCartesian(spherical);

  EXPECT_FLOAT_EQ(cart.x, 1.0f) << "only x in result";

  spherical.x = 2.0f;
  cart = sphericalToCartesian(spherical);

  EXPECT_FLOAT_EQ(cart.x, 2.0f) << "length should be 2";
}

TEST(util, cartesianToSpherical) {
  glm::vec3 cart(1.0f, 0.0f, 0.0);
  glm::vec3 spherical = cartesianToSpherical(cart);
  EXPECT_FLOAT_EQ(spherical.x, 1.0f) << "length should be 1";

  cart.y = 1.0f;
  spherical = cartesianToSpherical(cart);
  EXPECT_FLOAT_EQ(spherical.x, sqrt(2.0f)) << "length should be sqrt2";


}
