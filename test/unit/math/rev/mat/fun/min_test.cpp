#include <stan/math/rev/mat.hpp>
#include <gtest/gtest.h>
#include <test/unit/math/rev/mat/fun/util.hpp>
#include <test/unit/math/rev/mat/util.hpp>
#include <limits>
#include <algorithm>

TEST(AgradRevMatrix, min_vector) {
  using stan::math::min;
  using stan::math::vector_d;
  using stan::math::vector_v;

  vector_d d1(3);
  vector_v v1(3);

  d1 << 100, 0, -3;
  v1 << 100, 0, -3;

  AVAR output;
  output = min(d1);
  EXPECT_FLOAT_EQ(-3, output.val());

  output = min(v1);
  EXPECT_FLOAT_EQ(-3, output.val());
}
TEST(AgradRevMatrix, min_vector_exception) {
  using stan::math::min;
  using stan::math::vector_d;
  using stan::math::vector_v;

  vector_d d;
  vector_v v;
  d.resize(0);
  v.resize(0);
  EXPECT_EQ(std::numeric_limits<double>::infinity(), min(v).val());
}
TEST(AgradRevMatrix, min_rowvector) {
  using stan::math::min;
  using stan::math::row_vector_d;
  using stan::math::row_vector_v;

  row_vector_d d1(3);
  row_vector_v v1(3);

  d1 << 100, 0, -3;
  v1 << 100, 0, -3;

  AVAR output;
  output = min(d1);
  EXPECT_FLOAT_EQ(-3, output.val());

  output = min(v1);
  EXPECT_FLOAT_EQ(-3, output.val());
}
TEST(AgradRevMatrix, min_rowvector_exception) {
  using stan::math::min;
  using stan::math::row_vector_v;

  row_vector_v v;
  EXPECT_FLOAT_EQ(std::numeric_limits<double>::infinity(), min(v).val());
}
TEST(AgradRevMatrix, min_matrix) {
  using stan::math::min;
  using stan::math::matrix_d;
  using stan::math::matrix_v;

  matrix_d d1(3, 1);
  matrix_v v1(1, 3);

  d1 << 100, 0, -3;
  v1 << 100, 0, -3;

  AVAR output;
  output = min(d1);
  EXPECT_FLOAT_EQ(-3, output.val());

  output = min(v1);
  EXPECT_FLOAT_EQ(-3, output.val());
}
TEST(AgradRevMatrix, min_matrix_exception) {
  using stan::math::min;
  using stan::math::matrix_v;

  matrix_v v;
  EXPECT_FLOAT_EQ(std::numeric_limits<double>::infinity(), min(v).val());
}
TEST(AgradRevMatrix, check_varis_on_stack) {
  stan::math::vector_v v(3);
  v << -100, 0, 1;
  stan::math::row_vector_v rv(3);
  rv << -100, 0, 1;
  stan::math::matrix_v m(2, 3);
  m << -100, 0, 1, 20, -40, 2;

  test::check_varis_on_stack(stan::math::min(v));
  test::check_varis_on_stack(stan::math::min(rv));
  test::check_varis_on_stack(stan::math::min(m));
}
