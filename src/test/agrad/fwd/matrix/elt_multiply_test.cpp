#include <stan/math/matrix/elt_multiply.hpp>
#include <gtest/gtest.h>
#include <stan/agrad/fvar.hpp>
#include <stan/agrad/fwd/matrix/typedefs.hpp>
#include <stan/agrad/var.hpp>

TEST(AgradFwdMatrix,elt_multiply_vec_vv) {
  using stan::math::elt_multiply;
  using stan::agrad::vector_fd;

  vector_fd x(2);
  x << 2, 5;
   x(0).d_ = 1.0;
   x(1).d_ = 1.0;
  vector_fd y(2);
  y << 10, 100;
   y(0).d_ = 1.0;
   y(1).d_ = 1.0;

  vector_fd z = elt_multiply(x,y);
  EXPECT_FLOAT_EQ(20.0,z(0).val_);
  EXPECT_FLOAT_EQ(500.0,z(1).val_);
  EXPECT_FLOAT_EQ(12,z(0).d_);
  EXPECT_FLOAT_EQ(105,z(1).d_);
}

TEST(AgradFwdMatrix,elt_multiply_vec_vd) {
  using stan::math::elt_multiply;
  using stan::math::vector_d;
  using stan::agrad::vector_fd;

  vector_fd x(2);
  x << 2, 5;
   x(0).d_ = 1.0;
   x(1).d_ = 1.0;
  vector_d y(2);
  y << 10, 100;

  vector_fd z = elt_multiply(x,y);
  EXPECT_FLOAT_EQ(20.0,z(0).val_);
  EXPECT_FLOAT_EQ(500.0,z(1).val_);
  EXPECT_FLOAT_EQ(10,z(0).d_);
  EXPECT_FLOAT_EQ(100,z(1).d_);
}
TEST(AgradFwdMatrix,elt_multiply_vec_dv) {
  using stan::math::elt_multiply;
  using stan::math::vector_d;
  using stan::agrad::vector_fd;

  vector_d x(2);
  x << 2, 5;
  vector_fd y(2);
  y << 10, 100;
   y(0).d_ = 1.0;
   y(1).d_ = 1.0;

  vector_fd z = elt_multiply(x,y);
  EXPECT_FLOAT_EQ(20.0,z(0).val_);
  EXPECT_FLOAT_EQ(500.0,z(1).val_);
  EXPECT_FLOAT_EQ(2,z(0).d_);
  EXPECT_FLOAT_EQ(5,z(1).d_);
}

TEST(AgradFwdMatrix,elt_multiply_row_vec_vv) {
  using stan::math::elt_multiply;
  using stan::agrad::row_vector_fd;

  row_vector_fd x(2);
  x << 2, 5;
   x(0).d_ = 1.0;
   x(1).d_ = 1.0;
  row_vector_fd y(2);
  y << 10, 100;
   y(0).d_ = 1.0;
   y(1).d_ = 1.0;

  row_vector_fd z = elt_multiply(x,y);
  EXPECT_FLOAT_EQ(20.0,z(0).val_);
  EXPECT_FLOAT_EQ(500.0,z(1).val_);
  EXPECT_FLOAT_EQ(12,z(0).d_);
  EXPECT_FLOAT_EQ(105,z(1).d_);
}
TEST(AgradFwdMatrix,elt_multiply_row_vec_vd) {
  using stan::math::elt_multiply;
  using stan::math::row_vector_d;
  using stan::agrad::row_vector_fd;

  row_vector_fd x(2);
  x << 2, 5;
   x(0).d_ = 1.0;
   x(1).d_ = 1.0;
  row_vector_d y(2);
  y << 10, 100;

  row_vector_fd z = elt_multiply(x,y);
  EXPECT_FLOAT_EQ(20.0,z(0).val_);
  EXPECT_FLOAT_EQ(500.0,z(1).val_);
  EXPECT_FLOAT_EQ(10,z(0).d_);
  EXPECT_FLOAT_EQ(100,z(1).d_);
}
TEST(AgradFwdMatrix,elt_multiply_row_vec_dv) {
  using stan::math::elt_multiply;
  using stan::math::row_vector_d;
  using stan::agrad::row_vector_fd;

  row_vector_d x(2);
  x << 2, 5;
  row_vector_fd y(2);
  y << 10, 100;
   y(0).d_ = 1.0;
   y(1).d_ = 1.0;

  row_vector_fd z = elt_multiply(x,y);
  EXPECT_FLOAT_EQ(20.0,z(0).val_);
  EXPECT_FLOAT_EQ(500.0,z(1).val_);
  EXPECT_FLOAT_EQ(2,z(0).d_);
  EXPECT_FLOAT_EQ(5,z(1).d_);
}

TEST(AgradFwdMatrix,elt_multiply_matrix_vv) {
  using stan::math::elt_multiply;
  using stan::agrad::matrix_fd;

  matrix_fd x(2,3);
  x << 2, 5, 6, 9, 13, 29;
   x(0,0).d_ = 1.0;
   x(0,1).d_ = 1.0;
   x(0,2).d_ = 1.0;
   x(1,0).d_ = 1.0;
   x(1,1).d_ = 1.0;
   x(1,2).d_ = 1.0;
  matrix_fd y(2,3);
  y << 10, 100, 1000, 10000, 100000, 1000000;
   y(0,0).d_ = 1.0;
   y(0,1).d_ = 1.0;
   y(0,2).d_ = 1.0;
   y(1,0).d_ = 1.0;
   y(1,1).d_ = 1.0;
   y(1,2).d_ = 1.0;

  matrix_fd z = elt_multiply(x,y);
  EXPECT_FLOAT_EQ(20.0,z(0,0).val_);
  EXPECT_FLOAT_EQ(500.0,z(0,1).val_);
  EXPECT_FLOAT_EQ(29000000.0,z(1,2).val_);
  EXPECT_FLOAT_EQ(12,z(0,0).d_);
  EXPECT_FLOAT_EQ(105,z(0,1).d_);
  EXPECT_FLOAT_EQ(1000029,z(1,2).d_);
}
TEST(AgradFwdMatrix,elt_multiply_matrix_vd) {
  using stan::math::elt_multiply;
  using stan::math::matrix_d;
  using stan::agrad::matrix_fd;

  matrix_fd x(2,3);
  x << 2, 5, 6, 9, 13, 29;
   x(0,0).d_ = 1.0;
   x(0,1).d_ = 1.0;
   x(0,2).d_ = 1.0;
   x(1,0).d_ = 1.0;
   x(1,1).d_ = 1.0;
   x(1,2).d_ = 1.0;
  matrix_d y(2,3);
  y << 10, 100, 1000, 10000, 100000, 1000000;

  matrix_fd z = elt_multiply(x,y);
  EXPECT_FLOAT_EQ(20.0,z(0,0).val_);
  EXPECT_FLOAT_EQ(500.0,z(0,1).val_);
  EXPECT_FLOAT_EQ(29000000.0,z(1,2).val_);
  EXPECT_FLOAT_EQ(10,z(0,0).d_);
  EXPECT_FLOAT_EQ(100,z(0,1).d_);
  EXPECT_FLOAT_EQ(1000000,z(1,2).d_);
}
TEST(AgradFwdMatrix,elt_multiply_matrix_dv) {
  using stan::math::elt_multiply;
  using stan::math::matrix_d;
  using stan::agrad::matrix_fd;

  matrix_d x(2,3);
  x << 2, 5, 6, 9, 13, 29;
  matrix_fd y(2,3);
  y << 10, 100, 1000, 10000, 100000, 1000000;
   y(0,0).d_ = 1.0;
   y(0,1).d_ = 1.0;
   y(0,2).d_ = 1.0;
   y(1,0).d_ = 1.0;
   y(1,1).d_ = 1.0;
   y(1,2).d_ = 1.0;

  matrix_fd z = elt_multiply(x,y);
  EXPECT_FLOAT_EQ(20.0,z(0,0).val_);
  EXPECT_FLOAT_EQ(500.0,z(0,1).val_);
  EXPECT_FLOAT_EQ(29000000.0,z(1,2).val_);
  EXPECT_FLOAT_EQ(2,z(0,0).d_);
  EXPECT_FLOAT_EQ(5,z(0,1).d_);
  EXPECT_FLOAT_EQ(29,z(1,2).d_);
}
TEST(AgradFvarVarMatrix,elt_multiply_vec_vv) {
  using stan::math::elt_multiply;
  using stan::agrad::vector_fv;
  using stan::agrad::vector_fv;
  using stan::agrad::fvar;
  using stan::agrad::var;

  fvar<var> a(2.0,1.0);
  fvar<var> b(5.0,1.0);
  fvar<var> c(10.0,1.0);
  fvar<var> d(100.0,1.0);

  vector_fv x(2);
  x << a,b;
  vector_fv y(2);
  y << c,d;

  vector_fv z = elt_multiply(x,y);
  EXPECT_FLOAT_EQ(20.0,z(0).val_.val());
  EXPECT_FLOAT_EQ(500.0,z(1).val_.val());
  EXPECT_FLOAT_EQ(12,z(0).d_.val());
  EXPECT_FLOAT_EQ(105,z(1).d_.val());
}

TEST(AgradFvarVarMatrix,elt_multiply_vec_vd) {
  using stan::math::elt_multiply;
  using stan::math::vector_d;
  using stan::agrad::vector_fv;
  using stan::agrad::fvar;
  using stan::agrad::var;

  fvar<var> a(2.0,1.0);
  fvar<var> b(5.0,1.0);

  vector_fv x(2);
  x << a,b;
  vector_d y(2);
  y << 10, 100;

  vector_fv z = elt_multiply(x,y);
  EXPECT_FLOAT_EQ(20.0,z(0).val_.val());
  EXPECT_FLOAT_EQ(500.0,z(1).val_.val());
  EXPECT_FLOAT_EQ(10,z(0).d_.val());
  EXPECT_FLOAT_EQ(100,z(1).d_.val());
}
TEST(AgradFvarVarMatrix,elt_multiply_vec_dv) {
  using stan::math::elt_multiply;
  using stan::math::vector_d;
  using stan::agrad::vector_fv;
  using stan::agrad::fvar;
  using stan::agrad::var;

  fvar<var> c(10.0,1.0);
  fvar<var> d(100.0,1.0);

  vector_d x(2);
  x << 2, 5;
  vector_fv y(2);
  y << c,d;

  vector_fv z = elt_multiply(x,y);
  EXPECT_FLOAT_EQ(20.0,z(0).val_.val());
  EXPECT_FLOAT_EQ(500.0,z(1).val_.val());
  EXPECT_FLOAT_EQ(2,z(0).d_.val());
  EXPECT_FLOAT_EQ(5,z(1).d_.val());
}

TEST(AgradFvarVarMatrix,elt_multiply_row_vec_vv) {
  using stan::math::elt_multiply;
  using stan::agrad::row_vector_fv;
  using stan::agrad::fvar;
  using stan::agrad::var;

  fvar<var> a(2.0,1.0);
  fvar<var> b(5.0,1.0);
  fvar<var> c(10.0,1.0);
  fvar<var> d(100.0,1.0);

  row_vector_fv x(2);
  x << a,b;
  row_vector_fv y(2);
  y << c,d;

  row_vector_fv z = elt_multiply(x,y);
  EXPECT_FLOAT_EQ(20.0,z(0).val_.val());
  EXPECT_FLOAT_EQ(500.0,z(1).val_.val());
  EXPECT_FLOAT_EQ(12,z(0).d_.val());
  EXPECT_FLOAT_EQ(105,z(1).d_.val());
}
TEST(AgradFvarVarMatrix,elt_multiply_row_vec_vd) {
  using stan::math::elt_multiply;
  using stan::math::row_vector_d;
  using stan::agrad::row_vector_fv;
  using stan::agrad::fvar;
  using stan::agrad::var;

  fvar<var> a(2.0,1.0);
  fvar<var> b(5.0,1.0);

  row_vector_fv x(2);
  x << a,b;
  row_vector_d y(2);
  y << 10, 100;

  row_vector_fv z = elt_multiply(x,y);
  EXPECT_FLOAT_EQ(20.0,z(0).val_.val());
  EXPECT_FLOAT_EQ(500.0,z(1).val_.val());
  EXPECT_FLOAT_EQ(10,z(0).d_.val());
  EXPECT_FLOAT_EQ(100,z(1).d_.val());
}
TEST(AgradFvarVarMatrix,elt_multiply_row_vec_dv) {
  using stan::math::elt_multiply;
  using stan::math::row_vector_d;
  using stan::agrad::row_vector_fv;
  using stan::agrad::fvar;
  using stan::agrad::var;

  fvar<var> c(10.0,1.0);
  fvar<var> d(100.0,1.0);

  row_vector_d x(2);
  x << 2, 5;
  row_vector_fv y(2);
  y << c,d;

  row_vector_fv z = elt_multiply(x,y);
  EXPECT_FLOAT_EQ(20.0,z(0).val_.val());
  EXPECT_FLOAT_EQ(500.0,z(1).val_.val());
  EXPECT_FLOAT_EQ(2,z(0).d_.val());
  EXPECT_FLOAT_EQ(5,z(1).d_.val());
}

TEST(AgradFvarVarMatrix,elt_multiply_matrix_vv) {
  using stan::math::elt_multiply;
  using stan::agrad::matrix_fv;
  using stan::agrad::fvar;
  using stan::agrad::var;

  fvar<var> a(2.0,1.0);
  fvar<var> b(5.0,1.0);
  fvar<var> c(6.0,1.0);
  fvar<var> d(9.0,1.0);
  fvar<var> e(13.0,1.0);
  fvar<var> f(29.0,1.0);
  fvar<var> g(10.0,1.0);
  fvar<var> h(100.0,1.0);
  fvar<var> i(1000.0,1.0);
  fvar<var> j(10000.0,1.0);
  fvar<var> k(100000.0,1.0);
  fvar<var> l(1000000.0,1.0);

  matrix_fv x(2,3);
  x << a,b,c,d,e,f;
  matrix_fv y(2,3);
  y << g,h,i,j,k,l;

  matrix_fv z = elt_multiply(x,y);
  EXPECT_FLOAT_EQ(20.0,z(0,0).val_.val());
  EXPECT_FLOAT_EQ(500.0,z(0,1).val_.val());
  EXPECT_FLOAT_EQ(29000000.0,z(1,2).val_.val());
  EXPECT_FLOAT_EQ(12,z(0,0).d_.val());
  EXPECT_FLOAT_EQ(105,z(0,1).d_.val());
  EXPECT_FLOAT_EQ(1000029,z(1,2).d_.val());
}
TEST(AgradFvarVarMatrix,elt_multiply_matrix_vd) {
  using stan::math::elt_multiply;
  using stan::math::matrix_d;
  using stan::agrad::matrix_fv;
  using stan::agrad::fvar;
  using stan::agrad::var;

  fvar<var> a(2.0,1.0);
  fvar<var> b(5.0,1.0);
  fvar<var> c(6.0,1.0);
  fvar<var> d(9.0,1.0);
  fvar<var> e(13.0,1.0);
  fvar<var> f(29.0,1.0);

  matrix_fv x(2,3);
  x << a,b,c,d,e,f;
  matrix_d y(2,3);
  y << 10, 100, 1000, 10000, 100000, 1000000;

  matrix_fv z = elt_multiply(x,y);
  EXPECT_FLOAT_EQ(20.0,z(0,0).val_.val());
  EXPECT_FLOAT_EQ(500.0,z(0,1).val_.val());
  EXPECT_FLOAT_EQ(29000000.0,z(1,2).val_.val());
  EXPECT_FLOAT_EQ(10,z(0,0).d_.val());
  EXPECT_FLOAT_EQ(100,z(0,1).d_.val());
  EXPECT_FLOAT_EQ(1000000,z(1,2).d_.val());
}
TEST(AgradFvarVarMatrix,elt_multiply_matrix_dv) {
  using stan::math::elt_multiply;
  using stan::math::matrix_d;
  using stan::agrad::matrix_fv;
  using stan::agrad::fvar;
  using stan::agrad::var;

  fvar<var> g(10.0,1.0);
  fvar<var> h(100.0,1.0);
  fvar<var> i(1000.0,1.0);
  fvar<var> j(10000.0,1.0);
  fvar<var> k(100000.0,1.0);
  fvar<var> l(1000000.0,1.0);

  matrix_d x(2,3);
  x << 2, 5, 6, 9, 13, 29;
  matrix_fv y(2,3);
  y << g,h,i,j,k,l;

  matrix_fv z = elt_multiply(x,y);
  EXPECT_FLOAT_EQ(20.0,z(0,0).val_.val());
  EXPECT_FLOAT_EQ(500.0,z(0,1).val_.val());
  EXPECT_FLOAT_EQ(29000000.0,z(1,2).val_.val());
  EXPECT_FLOAT_EQ(2,z(0,0).d_.val());
  EXPECT_FLOAT_EQ(5,z(0,1).d_.val());
  EXPECT_FLOAT_EQ(29,z(1,2).d_.val());
}
TEST(AgradFvarFvarMatrix,elt_multiply_vec_vv) {
  using stan::math::elt_multiply;
  using stan::agrad::vector_ffd;
  using stan::agrad::vector_ffd;
  using stan::agrad::fvar;

  fvar<fvar<double> > a,b,c,d;
  a.val_.val_ = 2.0;
  a.d_.val_ = 1.0;  
  b.val_.val_ = 5.0;
  b.d_.val_ = 1.0;
  c.val_.val_ = 10.0;
  c.d_.val_ = 1.0;
  d.val_.val_ = 100.0;
  d.d_.val_ = 1.0;  

  vector_ffd x(2);
  x << a,b;
  vector_ffd y(2);
  y << c,d;

  vector_ffd z = elt_multiply(x,y);
  EXPECT_FLOAT_EQ(20.0,z(0).val_.val());
  EXPECT_FLOAT_EQ(500.0,z(1).val_.val());
  EXPECT_FLOAT_EQ(12,z(0).d_.val());
  EXPECT_FLOAT_EQ(105,z(1).d_.val());
}

TEST(AgradFvarFvarMatrix,elt_multiply_vec_vd) {
  using stan::math::elt_multiply;
  using stan::math::vector_d;
  using stan::agrad::vector_ffd;
  using stan::agrad::fvar;

  fvar<fvar<double> > a,b;
  a.val_.val_ = 2.0;
  a.d_.val_ = 1.0;  
  b.val_.val_ = 5.0;
  b.d_.val_ = 1.0;

  vector_ffd x(2);
  x << a,b;
  vector_d y(2);
  y << 10, 100;

  vector_ffd z = elt_multiply(x,y);
  EXPECT_FLOAT_EQ(20.0,z(0).val_.val());
  EXPECT_FLOAT_EQ(500.0,z(1).val_.val());
  EXPECT_FLOAT_EQ(10,z(0).d_.val());
  EXPECT_FLOAT_EQ(100,z(1).d_.val());
}
TEST(AgradFvarFvarMatrix,elt_multiply_vec_dv) {
  using stan::math::elt_multiply;
  using stan::math::vector_d;
  using stan::agrad::vector_ffd;
  using stan::agrad::fvar;

  fvar<fvar<double> > c,d;
  c.val_.val_ = 10.0;
  c.d_.val_ = 1.0;
  d.val_.val_ = 100.0;
  d.d_.val_ = 1.0;  

  vector_d x(2);
  x << 2, 5;
  vector_ffd y(2);
  y << c,d;

  vector_ffd z = elt_multiply(x,y);
  EXPECT_FLOAT_EQ(20.0,z(0).val_.val());
  EXPECT_FLOAT_EQ(500.0,z(1).val_.val());
  EXPECT_FLOAT_EQ(2,z(0).d_.val());
  EXPECT_FLOAT_EQ(5,z(1).d_.val());
}

TEST(AgradFvarFvarMatrix,elt_multiply_row_vec_vv) {
  using stan::math::elt_multiply;
  using stan::agrad::row_vector_ffd;
  using stan::agrad::fvar;

  fvar<fvar<double> > a,b,c,d;
  a.val_.val_ = 2.0;
  a.d_.val_ = 1.0;  
  b.val_.val_ = 5.0;
  b.d_.val_ = 1.0;
  c.val_.val_ = 10.0;
  c.d_.val_ = 1.0;
  d.val_.val_ = 100.0;
  d.d_.val_ = 1.0;  

  row_vector_ffd x(2);
  x << a,b;
  row_vector_ffd y(2);
  y << c,d;

  row_vector_ffd z = elt_multiply(x,y);
  EXPECT_FLOAT_EQ(20.0,z(0).val_.val());
  EXPECT_FLOAT_EQ(500.0,z(1).val_.val());
  EXPECT_FLOAT_EQ(12,z(0).d_.val());
  EXPECT_FLOAT_EQ(105,z(1).d_.val());
}
TEST(AgradFvarFvarMatrix,elt_multiply_row_vec_vd) {
  using stan::math::elt_multiply;
  using stan::math::row_vector_d;
  using stan::agrad::row_vector_ffd;
  using stan::agrad::fvar;

  fvar<fvar<double> > a;
  fvar<fvar<double> > b;
  a.val_.val_ = 2.0;
  a.d_.val_ = 1.0;  
  b.val_.val_ = 5.0;
  b.d_.val_ = 1.0;

  row_vector_ffd x(2);
  x << a,b;
  row_vector_d y(2);
  y << 10, 100;

  row_vector_ffd z = elt_multiply(x,y);
  EXPECT_FLOAT_EQ(20.0,z(0).val_.val());
  EXPECT_FLOAT_EQ(500.0,z(1).val_.val());
  EXPECT_FLOAT_EQ(10,z(0).d_.val());
  EXPECT_FLOAT_EQ(100,z(1).d_.val());
}
TEST(AgradFvarFvarMatrix,elt_multiply_row_vec_dv) {
  using stan::math::elt_multiply;
  using stan::math::row_vector_d;
  using stan::agrad::row_vector_ffd;
  using stan::agrad::fvar;

  fvar<fvar<double> > c,d;
  c.val_.val_ = 10.0;
  c.d_.val_ = 1.0;
  d.val_.val_ = 100.0;
  d.d_.val_ = 1.0;  

  row_vector_d x(2);
  x << 2, 5;
  row_vector_ffd y(2);
  y << c,d;

  row_vector_ffd z = elt_multiply(x,y);
  EXPECT_FLOAT_EQ(20.0,z(0).val_.val());
  EXPECT_FLOAT_EQ(500.0,z(1).val_.val());
  EXPECT_FLOAT_EQ(2,z(0).d_.val());
  EXPECT_FLOAT_EQ(5,z(1).d_.val());
}

TEST(AgradFvarFvarMatrix,elt_multiply_matrix_vv) {
  using stan::math::elt_multiply;
  using stan::agrad::matrix_ffd;
  using stan::agrad::fvar;

  fvar<fvar<double> > a,b,c,d,e,f,g,h,i,j,k,l;
  a.val_.val_ = 2.0;
  a.d_.val_ = 1.0;  
  b.val_.val_ = 5.0;
  b.d_.val_ = 1.0;
  c.val_.val_ = 6.0;
  c.d_.val_ = 1.0;
  d.val_.val_ = 9.0;
  d.d_.val_ = 1.0;  
  e.val_.val_ = 13.0;
  e.d_.val_ = 1.0;
  f.val_.val_ = 29.0;
  f.d_.val_ = 1.0;
  g.val_.val_ = 10.0;
  g.d_.val_ = 1.0;  
  h.val_.val_ = 100.0;
  h.d_.val_ = 1.0;
  i.val_.val_ = 1000.0;
  i.d_.val_ = 1.0;
  j.val_.val_ = 10000.0;
  j.d_.val_ = 1.0;  
  k.val_.val_ = 100000.0;
  k.d_.val_ = 1.0;
  l.val_.val_ = 1000000.0;
  l.d_.val_ = 1.0;

  matrix_ffd x(2,3);
  x << a,b,c,d,e,f;
  matrix_ffd y(2,3);
  y << g,h,i,j,k,l;

  matrix_ffd z = elt_multiply(x,y);
  EXPECT_FLOAT_EQ(20.0,z(0,0).val_.val());
  EXPECT_FLOAT_EQ(500.0,z(0,1).val_.val());
  EXPECT_FLOAT_EQ(29000000.0,z(1,2).val_.val());
  EXPECT_FLOAT_EQ(12,z(0,0).d_.val());
  EXPECT_FLOAT_EQ(105,z(0,1).d_.val());
  EXPECT_FLOAT_EQ(1000029,z(1,2).d_.val());
}
TEST(AgradFvarFvarMatrix,elt_multiply_matrix_vd) {
  using stan::math::elt_multiply;
  using stan::math::matrix_d;
  using stan::agrad::matrix_ffd;
  using stan::agrad::fvar;

  fvar<fvar<double> > a,b,c,d,e,f;
  a.val_.val_ = 2.0;
  a.d_.val_ = 1.0;  
  b.val_.val_ = 5.0;
  b.d_.val_ = 1.0;
  c.val_.val_ = 6.0;
  c.d_.val_ = 1.0;
  d.val_.val_ = 9.0;
  d.d_.val_ = 1.0;  
  e.val_.val_ = 13.0;
  e.d_.val_ = 1.0;
  f.val_.val_ = 29.0;
  f.d_.val_ = 1.0;

  matrix_ffd x(2,3);
  x << a,b,c,d,e,f;
  matrix_d y(2,3);
  y << 10, 100, 1000, 10000, 100000, 1000000;

  matrix_ffd z = elt_multiply(x,y);
  EXPECT_FLOAT_EQ(20.0,z(0,0).val_.val());
  EXPECT_FLOAT_EQ(500.0,z(0,1).val_.val());
  EXPECT_FLOAT_EQ(29000000.0,z(1,2).val_.val());
  EXPECT_FLOAT_EQ(10,z(0,0).d_.val());
  EXPECT_FLOAT_EQ(100,z(0,1).d_.val());
  EXPECT_FLOAT_EQ(1000000,z(1,2).d_.val());
}
TEST(AgradFvarFvarMatrix,elt_multiply_matrix_dv) {
  using stan::math::elt_multiply;
  using stan::math::matrix_d;
  using stan::agrad::matrix_ffd;
  using stan::agrad::fvar;

  fvar<fvar<double> > g,h,i,j,k,l;
  g.val_.val_ = 10.0;
  g.d_.val_ = 1.0;  
  h.val_.val_ = 100.0;
  h.d_.val_ = 1.0;
  i.val_.val_ = 1000.0;
  i.d_.val_ = 1.0;
  j.val_.val_ = 10000.0;
  j.d_.val_ = 1.0;  
  k.val_.val_ = 100000.0;
  k.d_.val_ = 1.0;
  l.val_.val_ = 1000000.0;
  l.d_.val_ = 1.0;

  matrix_d x(2,3);
  x << 2, 5, 6, 9, 13, 29;
  matrix_ffd y(2,3);
  y << g,h,i,j,k,l;


  matrix_ffd z = elt_multiply(x,y);
  EXPECT_FLOAT_EQ(20.0,z(0,0).val_.val());
  EXPECT_FLOAT_EQ(500.0,z(0,1).val_.val());
  EXPECT_FLOAT_EQ(29000000.0,z(1,2).val_.val());
  EXPECT_FLOAT_EQ(2,z(0,0).d_.val());
  EXPECT_FLOAT_EQ(5,z(0,1).d_.val());
  EXPECT_FLOAT_EQ(29,z(1,2).d_.val());
}
