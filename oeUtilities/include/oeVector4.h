#pragma once

#include "oePrerequisites_Utilities.h"
#include "oePlatformMath.h"
namespace oeEngineSDK {
  class OE_UTILITIES_EXPORT Vector4 {
  public:
    float a_X;
    float a_Y;
    float a_Z;
    float a_W;

    float X_Axis;
    float Y_Axis;
    float Z_Axis;
    float W_Axis;

    Vector4(float prm_X = 0.0f, float prm_Y = 0.0f, float prm_Z = 
    0.0f, float prm_W = 0.0f) :a_X(prm_X), a_Y(prm_Y), a_Z(prm_Z), a_W(prm_W) {}

    // Common scalar math operators
    Vector4  operator + (const Vector4 & prm_Vector) const {
    return Vector4(a_X + prm_Vector.a_X, a_Y + prm_Vector.a_Y, a_Z + 
    prm_Vector.a_Z, a_W + prm_Vector.a_W); }

    Vector4  operator - (const Vector4 & prm_Vector) const {
    return Vector4(a_X - prm_Vector.a_X, a_Y - prm_Vector.a_Y, a_Z - 
    prm_Vector.a_Z, a_W - prm_Vector.a_W); }

    Vector4  operator * (const float prm_Scalar) const {
      return Vector4(a_X * prm_Scalar, a_Y * prm_Scalar, a_Z *
      prm_Scalar, a_W * prm_Scalar); }

    Vector4  operator / (const float prm_Scalar) const {
    return Vector4(a_X / prm_Scalar, a_Y / prm_Scalar, a_Z / prm_Scalar,
    a_W / prm_Scalar); }

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
    return  CMath::Sqrt(CMath::Power(a_X, 2.0f) + CMath::Power(a_Y, 2.0f) +
      CMath::Power(a_Z, 2.0f) + CMath::Power(a_W, 2.0f)); }
    /*!*/
    float	 SqrLength() const {
    return (CMath::Power(a_X, 2.0f) + CMath::Power(a_Y, 2.0f) +
      CMath::Power(a_Z, 2.0f) + CMath::Power(a_W, 2.0f)); }
    /*!*/
    float	DotProduct(const Vector4 & prm_Vector) const {
    return ((a_X * prm_Vector.a_X) + (a_Y * prm_Vector.a_Y) + 
    (a_Z * prm_Vector.a_Z) + (a_W * prm_Vector.a_W)); }
    /*!*/
    float	Angle(const Vector4 & prm_Vector) const{
    return (std::acosf(DotProduct(prm_Vector) * (1.0f / Length() * 
    prm_Vector.Length()))); }
    /*!*/
    Vector4	Normalize() {
    
      return *this *= 1.0f / Length(); }

    //! Unique Geometric Functions
    /*!
    \fn m_Perpendicular
    \brief Calculates a perpendicular vector
    \details Calculation made from determinant i(1, 0) and j(0, 1) resulting 
    in: i(y) - j(x) = (y, -x)
    */
    Vector4 CrossProduct(const Vector4 & prm_Vector) const {
    return Vector4(((a_Y*prm_Vector.a_Z) - (prm_Vector.a_Y*a_Z)),
      ((a_X*prm_Vector.a_Z) - (prm_Vector.a_X*a_Z)), ((a_X*prm_Vector.a_Y) -
      (prm_Vector.a_X*a_Y))); }
    /*!*/
    Vector4	UnitCrossProduct(const Vector4 & prm_Vector) {
    return (CrossProduct(prm_Vector) /= Length()); }

    //! Common comparison operators
    bool operator == (const Vector4 & prm_Vector) const {
    return (a_X == prm_Vector.a_X) && (a_Y == prm_Vector.a_Y) &&
    (a_Z == prm_Vector.a_Z) && (a_W == prm_Vector.a_W); }
    
    bool operator != (const Vector4 & prm_Vector) const {
    return (a_X != prm_Vector.a_X) || (a_Y != prm_Vector.a_Y) || 
    (a_Z == prm_Vector.a_Z) || (a_W != prm_Vector.a_W); }
    
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
