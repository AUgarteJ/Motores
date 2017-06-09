#include <gtest/gtest.h>
#include <oePlatformMath.h>
#include<oeVector4.h>

 using namespace oeEngineSDK;
 TEST(Utilities, TypesTest) {
   EXPECT_TRUE(sizeof(uint8) == 1);
   EXPECT_TRUE(sizeof(uint16) == 2);
   EXPECT_TRUE(sizeof(uint32) == 4);
   EXPECT_TRUE(sizeof(uint32) == 4);
   EXPECT_TRUE(sizeof(uint64) == 8);
   EXPECT_TRUE(sizeof(int8) == 1);
   EXPECT_TRUE(sizeof(int16) == 2);
   EXPECT_TRUE(sizeof(int32) == 4);
   EXPECT_TRUE(sizeof(int64) == 8);
   EXPECT_TRUE(sizeof(SIZE_T) == 4);
   EXPECT_TRUE(sizeof(QWord) == 16);
 }

TEST(Utilities, MathTest) {

  EXPECT_TRUE(CMath::PI == std::atanf(1.f / 4.f));
  EXPECT_TRUE(CMath::MIN_UINT8 == 0);
  
  EXPECT_TRUE(CMath::Ceil(5.6f) == 6);
  EXPECT_TRUE(CMath::Trunc(6.8f) ==6);
  EXPECT_TRUE(CMath::Floor(3.9) == 3);
  EXPECT_TRUE(CMath::Round(7.6f) == 8);
  /*EXPECT_TRUE(CMath::Fractional(3.20f) == 0.2f);*/
  /*EXPECT_TRUE(CMath::ModuleFloat(1.1, 1) == 0.1);*/
  EXPECT_TRUE(CMath::Power(2, 2) == 4);
  EXPECT_TRUE(CMath::Exponential(0) == 1);
  EXPECT_TRUE(CMath::LogN(1) == 0);
  EXPECT_TRUE(CMath::LogX(10,10) == 1);
  EXPECT_TRUE(CMath::Sqrt(9) ==3);
  EXPECT_TRUE(CMath::InverseSqrt(1) == 1);
  EXPECT_TRUE(CMath::InvSqrtEst(1) == 1);
  EXPECT_TRUE(CMath::IsNan(2.32f) == false);
  /*EXPECT_TRUE(CMath::_Minimum(2, 3) == 2);*/
}
TEST(Utilities, Trigonometric) {
  CMath obj;
  EXPECT_TRUE(CMath::Sine(90.0f) == 0.8939966636f);
  EXPECT_TRUE(CMath::Cosine(0) == 1);
  EXPECT_TRUE(CMath::Tangent(10.0f) == 0.6483608275f);
  EXPECT_TRUE(CMath::Asin(1) == 1.570796327f);
  EXPECT_TRUE(CMath::Acos(-1) == 3.141592654f);
  EXPECT_TRUE(CMath::Atan(1) == 0.25f*3.141592654f);
}

TEST(Utilities, Vector4Test)
{
  Vector4 Vector;
  Vector.a_X = 8;
  Vector.a_Y = 0;
  Vector.a_Z = 0;
  Vector.a_W = 0;

  Vector4 Vector1;
  Vector1.a_X = 1;
  Vector1.a_Y = 0;
  Vector1.a_Z = 0;
  Vector1.a_W = 0;

  EXPECT_TRUE(Vector1 == Vector.Normalize());

  Vector4 Vector2;
  float temp;
  Vector2.a_X = 2;
  Vector2.a_Y = 2;
  Vector2.a_Z = 2;
  Vector2.a_W = 2;
  temp = Vector2.DotProduct(Vector2);
  EXPECT_TRUE(temp == 16.0f);

  Vector4 Vector0;
  Vector0.a_X = -3;
  Vector0.a_Y = -2;
  Vector0.a_Z = 5;
  Vector0.a_W = 0;
  
  Vector4 Vector01;
  Vector01 = 10;
  Vector01 = -6;
  Vector01 = -1;
  Vector01 = 0;

  Vector0 = Vector0.CrossProduct(Vector01);
  Vector4 Vector03;
  Vector03.a_X = 32;
  Vector03.a_Y = -47;
  Vector03.a_Z = 38;
  Vector03.a_W = 0;
 // ASSERT_TRUE(Vector0 == Vector03);
}


