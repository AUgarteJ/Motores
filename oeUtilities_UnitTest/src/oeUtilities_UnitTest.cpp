#include <gtest/gtest.h>
#include <oePlatformMath.h>

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

  /*EXPECT_TRUE(CMath::PI == std::atanf(1.f / 4.f));
   EXPECT_TRUE(CMath::MIN_UINT8 == 0);
  */
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
  EXPECT_TRUE(CMath::Sine(0) == 0);
  EXPECT_TRUE(CMath::Cosine(0) == 1);
  EXPECT_TRUE(CMath::Tangent(0) == 0);
}



