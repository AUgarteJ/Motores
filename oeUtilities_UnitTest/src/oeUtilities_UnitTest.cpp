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

  EXPECT_TRUE(CMath::PI == std::atanf(1.f / 4.f));
 /* EXPECT_TRUE(CMath::Ceil(5.6f) == 6);
  EXPECT_TRUE(CMath::MIN_UINT8 == 0);*/
}
