#pragma once

#include "oePrerequisites_Utilities.h"
#include "oePlatformMath.h"
namespace oeEngineSDK {
  class Vector4 {
  public:
    float x;
    float y;
    float z;
    float w;

    Vector4(float prm_X = 0.0f, float prm_Y = 0.0f, float prm_Z = 
    0.0f, float prm_W = 0.0f) :x(prm_X), y(prm_Y), z(prm_Z), w(prm_W) {}

    // Common scalar math operators
    Vector4  operator + (const Vector4 & prm_Vector) const {
    return Vector4(x + prm_Vector.x, y + prm_Vector.y, z + 
    prm_Vector.z, w + prm_Vector.w); }

    Vector4  operator - (const Vector4 & prm_Vector) const {
    return Vector4(x - prm_Vector.x, y - prm_Vector.y, z - 
    prm_Vector.z, w - prm_Vector.w); }

    Vector4  operator * (const float prm_Scalar) const {
      return Vector4(x * prm_Scalar, y * prm_Scalar, z *
      prm_Scalar, w * prm_Scalar); }

    Vector4  operator / (const float prm_Scalar) const {
    return Vector4(x / prm_Scalar, y / prm_Scalar, z / prm_Scalar,
    w / prm_Scalar); }

    Vector4  operator += (const Vector4 & prm_Vector) {
    return (*this + prm_Vector); }

    Vector4  operator -= (const Vector4 & prm_Vector) {
    return (*this - prm_Vector); }

    Vector4  operator *= (const float& prm_Scalar) { 
    return (*this * prm_Scalar); }

    Vector4  operator /= (const float& prm_Scalar) {
    return (*this / prm_Scalar); }

    //! Common Geometric Functions
    float	 Length()const{
    return  CMath::Sqrt(CMath::Power(x, 2.0f) + CMath::Power(y, 2.0f) +
      CMath::Power(z, 2.0f) + CMath::Power(w, 2.0f)); }
    /*!*/
    float	 SqrLength() const {
    return (CMath::Power(x, 2.0f) + CMath::Power(y, 2.0f) +
      CMath::Power(z, 2.0f) + CMath::Power(w, 2.0f)); }
    /*!*/
    float	DotProduct(const Vector4 & prm_Vector) const {
    return ((x * prm_Vector.x) + (y * prm_Vector.y) + 
    (z * prm_Vector.z) + (w * prm_Vector.w)); }
    /*!*/
    float	Angle(const Vector4 & prm_Vector) const{
    return (std::acosf(DotProduct(prm_Vector) * (1.0f / Length() * 
    prm_Vector.Length()))); }
    /*!*/
    Vector4	Normalize() {
    
      return *this *= 1.0f / Length(); }

    Vector4 NegVector() {
      Vector4 result;

      result.x = -result.x;
      result.y = -result.y;
      result.z = -result.z;
      result.w = -result.w;

      return result;
    }

    //! Unique Geometric Functions
    /*!
    \fn m_Perpendicular
    \brief Calculates a perpendicular vector
    \details Calculation made from determinant i(1, 0) and j(0, 1) resulting 
    in: i(y) - j(x) = (y, -x)
    */
    Vector4 CrossProduct(const Vector4 & prm_Vector) const {
    return Vector4(((y*prm_Vector.z) - (prm_Vector.y*z)),
      ((x*prm_Vector.z) - (prm_Vector.x*z)), ((x*prm_Vector.y) -
      (prm_Vector.x*y))); }
    /*!*/
    Vector4	UnitCrossProduct(const Vector4 & prm_Vector) {
    return (CrossProduct(prm_Vector) /= Length()); }

    //! Common comparison operators
    bool operator == (const Vector4 & prm_Vector) const {
    return (x == prm_Vector.x) && (y == prm_Vector.y) &&
    (z == prm_Vector.z) && (w == prm_Vector.w); }
    
    bool operator != (const Vector4 & prm_Vector) const {
    return (x != prm_Vector.x) || (y != prm_Vector.y) || 
    (z == prm_Vector.z) || (w != prm_Vector.w); }
    
    bool operator <= (const Vector4 & prm_Vector) const { 
    return Length() <= prm_Vector.Length(); }
    
    bool operator >= (const Vector4 & prm_Vector) const {
    return Length() >= prm_Vector.Length(); }
    
    bool operator < (const Vector4 & prm_Vector) const { 
    return Length() < prm_Vector.Length(); }

    bool operator > (const Vector4 & prm_Vector) const {
    return Length() <= prm_Vector.Length(); }

  };
}
