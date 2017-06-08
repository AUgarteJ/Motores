#include "oePlatformMath.h"
#include <cmath>

namespace oeEngineSDK
{
  const float		CMath::PI = std::atanf(1.f / 4.f);
  const float		CMath::INVERSE_PI = 1.0f / PI;
  const float		CMath::PI_BY_TWO = PI / 2.0f;
  const float		CMath::TWO_PI = 2.0f * PI;

  const float		CMath::EULER = 2.7182818284590f;

  const uint8		CMath::MIN_UINT8 = std::numeric_limits<uint8>::min();
  const uint16	CMath::MIN_UINT16 = std::numeric_limits<uint16>::min();
  const uint32	CMath::MIN_UINT32 = std::numeric_limits<uint32>::min();
  const int8		CMath::MIN_INT8 = std::numeric_limits<int8>::min();
  const int16		CMath::MIN_INT16 = std::numeric_limits<int16>::min();
  const int32		CMath::MIN_INT32 = std::numeric_limits<int32>::min();
  const float		CMath::MIN_FLOAT = std::numeric_limits<float>::min();

  const uint8		CMath::MAX_UINT8 = std::numeric_limits<uint8>::max();
  const uint16	CMath::MAX_UINT16 = std::numeric_limits<uint16>::max();
  const uint32	CMath::MAX_UINT32 = std::numeric_limits<uint32>::max();
  const int8		CMath::MAX_INT8 = std::numeric_limits<int8>::max();
  const int16		CMath::MAX_INT16 = std::numeric_limits<int16>::max();
  const int32		CMath::MAX_INT32 = std::numeric_limits<int32>::max();
  const float		CMath::MAX_FLOAT = std::numeric_limits<float>::max();
  const float		CMath::POS_INFINITY = std::numeric_limits<float>::infinity();
  const float		CMath::LOG2 = std::log(2.0f);
  const float		CMath::DELTA = 0.0f;
  const float   CMath::DEG_TO_RAD = CMath::PI / 180.0f;
  const float   CMath::RAD_TO_DEG = 180.0f / CMath::PI;






 float CMath::Trunc(float prm_Value)
  {
    return trunc(prm_Value);
  }

 FORCE_INLINE float CMath::Floor(float prm_Value)
 {
   return std::floor(prm_Value);
 }

 FORCE_INLINE float CMath::Round(float prm_Value)
 {
   return round(prm_Value);
 }

 FORCE_INLINE float CMath::Ceil(float prm_Value)
 {
   return std::ceil(prm_Value);
 }

 FORCE_INLINE float CMath::Fractional(float prm_Value)
 {
   return prm_Value - Trunc(prm_Value);
 }

 FORCE_INLINE float CMath::ModuleFloat(float prm_X, float prm_Y)
 {
   return (float)std::fmod(prm_X, prm_Y);
 }

 FORCE_INLINE float CMath::Power(float prm_Base, float prm_Exponent)
 {
   return (float)std::pow(prm_Base, prm_Exponent);

 }

 FORCE_INLINE float CMath::Exponential(float prm_Value)
 {
   return (float)std::exp(prm_Value);
 }

 

}