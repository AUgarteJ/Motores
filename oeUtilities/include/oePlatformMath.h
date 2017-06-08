#pragma once

#include "oePrerequisites_Utilities.h"


/*!
\namespace oeEngineSDK
\brief Declares every function (math, types, objects) for use in the engine
*/
namespace oeEngineSDK {
  //! Absolute
  template<class T> FORCE_INLINE T Absolute(const T prm_Value) {
    return (prm_Value >= (T)0) ? prm_Value : -prm_Value;
  }

  template <> FORCE_INLINE float Absolute<float>(const float prm_Value) {
    return (float)std::fabs(prm_Value);
  }

  /*!
  \class  Math 
  \brief Class that controls basic mathematical scalar operations
  */
  class OE_UTILITIES_EXPORT CMath {
   public:

    //! Constants
    //! Pi
    /*!
    \var a_PI
    \brief Value of Pi given in radians
    */
    static const float		PI;
    /*!
    \var a_INVERSE_PI
    \brief Pi constant = 3.141592535897
    */
    static const float		INVERSE_PI;
    /*!
    \var a_PI_BY_TWO
    \brief 
    */
    static const float		PI_BY_TWO;
    /*!
    \var a_TWO_PI
    \brief 
    */
    static const float		TWO_PI;

    //! Euler number
    /*!
    \var a_EULER
    \brief 
    */
    static const float		EULER;

    //! Minimum type limits
    /*!
    \var a_UINT8
    \brief
    */
    static const uint8		MIN_UINT8;
    /*!
    \var a_UINT16
    \brief 
   */
    static const uint16		MIN_UINT16;
    /*!
    \var a_UINT32
    \brief 
    */
    static const uint32		MIN_UINT32;
    /*!
    \var a_MIN_INT8
    \brief 
    */
    static const int8		MIN_INT8;
    /*!
    \var a_MIN_INT16
    \brief
    */
    static const int16		MIN_INT16;
    /*!
    \var a_MIN_INT32
    \brief 
    */
    static const int32	MIN_INT32;
    /*!
    \var a_MIN_FLOAT
    \brief
    */
    static const float		MIN_FLOAT;

    //! Maximum type limits
    /*!
    \var a_MAX_UINT8
    \brief 
    */
    static const uint8		MAX_UINT8;
    /*!
    \var a_UINT16
    \brief 
    */
    static const uint16		MAX_UINT16;
    /*!
    \var a_UINT32
    \brief 
    */
    static const uint32		MAX_UINT32;
    /*!
    \var a_MAX_INT8
    \brief 
    */
    static const int8		MAX_INT8;
    /*!
    \var a_MAX_INT16
    \brief 
    */
    static const int16		MAX_INT16;
    /*!
    \var a_MAX_INT32
    \brief 
    */
    static const int32		MAX_INT32;
    /*!
    \var a_MAX_FLOAT
    \brief
    */
    static const float		MAX_FLOAT;

    //! Degree - Radian Transformations
    /*!
    \var a_DEG_TO_RAD
    \brief Transforms degrees to radians
    */
    static const float		DEG_TO_RAD;
    /*!
    \var a_RAD_TO_DEG
    \brief Transforms radians to degrees
    */
    static const float		RAD_TO_DEG;

    //! Infinity
    /*!
    \var a_POS_INFINITY
    \brief Defines the positive infinity
    */
    static const float		POS_INFINITY;

    /*!
    \var a_NEG_INFINITY
    \brief Defines the negative infinity
    */
    static const float		NEG_INFINITY;


    //! Error margins
    /*!
    \var a_LOG2
    \brief Constant for the natural logarithm (base 2 logarithm)
    */
    static const float		LOG2;
    /*!
    \var a_DELTA
    \brief Defines the lowest increment
    */
    static const float		DELTA;
    /*!*/
    static const float		SMALL_NUMBER;
    /*!*/
    static const float		FLOAT_SMALL_NUMBER;
    /*!*/
    static const float		KINDA_SMALL_NUMBER;
    /*!*/
    static const float		BIG_NUMBER;
    /*!*/
    static const float		FLOAT_EPSILON;
    /*!*/
    static const double		FDOUBLE_EPSILON;

    //! Thresholds
    /*!*/
    static const float		THRESH_POINT_ON_PLANE;
    /*!*/
    static const float		THRESH_POINT_ON_SIDE;
    /*!*/
    static const float		THRESH_POINTS_ARE_SAME;
    /*!*/
    static const float		THRESH_POINTS_ARE_NEAR;
    /*!*/
    static const float		THRESH_NORMALS_ARE_SAME;
    /*!*/
    static const float		THRESH_VECTORS_ARE_NEAR;
    /*!*/
    static const float		THRESH_SPLIT_POLY_WITH_PLANE;
    /*!*/
    static const float		THRESH_SPLIT_POLY_PRECISELY;
    /*!*/
    static const float		THRESH_ZERO_ON_PLANE;
    /*!*/
    static const float		THRESH_NORMALS_ARE_PARALLEL;
    /*!*/
    static const float		THRESH_NORMALS_ARE_ORTHOGONAL;
    /*!*/
    static const float		THRESH_VECTOR_NORMALIZED;
    /*!*/
    static const float		THRESH_QUAT_NORMALIZED;

    //! Truncate
    /*!
    \fn m_Trunc
    \brief Truncates a int32 value
    \param prm_Value Value to be truncated
    */
    static FORCE_INLINE float
      Trunc(float prm_Value);
 

  
    //! Roundings
    /*!
    \fn m_Floor
    \brief Rounds a value to the lowest
    \param prm_Value Value to be floored
    */
    static  float
      Floor(float prm_Value);


    /*!
    \fn m_Round
    \brief Rounds a value to the half
    \param prm_Value Value to be half rounded
    */
    static  float
      Round(float prm_Value);

    /*!
    \fn m_Ceil
    \brief Rounds a value to the highest
    \param prm_Value Value to be ceiled
    */
    static  float
      Ceil(float prm_Value);

    //! Fraccional
    /*!
    \Fractional
    \brief Obtains the fractional of a value
    \param prm_Value Value to be fractionalized
    */
    static  float
      Fractional(float prm_Value);
    //! Module
    /*!
    \fn m_ModuleFloat
    \brief Obtains modulo of two values
    \param prm_X Divider
    \param prm_Y Dividend
    */
    static  float
      ModuleFloat(float prm_X, float prm_Y);
    

    //! Power
    /*!
    \fn m_Power
    \brief Raise a value to a given power
    \param prm_Base Base of the power operation
    \param prm_Exponent Exponent of the power operation
    */
    static  float
    Power(float prm_Base, float prm_Exponent);
    //! Exponential
    /*!
    \fn m_Exponential
    \brief Obtains the exponential function of a value
    \param prm_Value Value to obtain the exponential function
    */
    static  float
      Exponential(float prm_Value);


    //! Natural Logarithm
    /*!
    */
    static  float
      LogN(float prm_Value);
    //! Binary Logarithm (Base 2)
    /*!
    */
    //->static  float	m_Log2(float prm_Value);

    //! Base 'x' Logarithm
    /*!
    */
    static  float
      LogX(float prm_Base, float prm_Value);

    //! Square root
    /*!
    */
    static  float
      Sqrt(float prm_Value);
    //! Square root degrees
    /*!
    */
    /*   	static  C_Degree m_Sqrt(const C_Degree& prm_Value) {
       return C_Degree(m_Sqrt(prm_Value.m_ValueDegrees()));
       }*/
    //! Square root radians
    /*!
    */
    /*static  C_Radian m_Sqrt(const C_Radian& prm_Value) {
    return C_Radian(m_Sqrt(prm_Value.m_ValueRadians()));
    }*/


    //! Inverse Square root
    /*!
    */
    static  float
      InverseSqrt(float prm_F);
    //! Inverse Square root 
    /*!
    */
    static  float
      InvSqrtEst(float prm_F);

    //! CHECK is nan?
    /*!
    */
    static  bool
      IsNan(float prm_Value);

    //! CHECK is finite?
    /*!
    */
    static  bool	
    IsFinite(float prm_Value);

    //! CHECK is Negative float?
    /*!
    */
    static  bool
      IsNegativeFloat(float prm_Value);

    //! Trigonometric
    /*!
    */
    static  float	
    Sine(float prm_Value);

    /*!
    */
    static  float
      Cosine(float prm_Value);

    /*!
    */
    static  float
      Tangent(float prm_Value);

    //! Radian trigonometric
    /*!
    \fn m_RadianSine
    \brief
    */
    /*static  float	m_RadianSine(const C_Radian& prm_Radian) {
    return (float)std::sin(prm_Radian.m_ValueRadians());
    }*/

    /*!
    \fn m_RadianCosine
    \brief
    */
    /*	static  float	m_RadianCosine(const C_Radian& prm_Radian) {
    return (float)std::cos(prm_Radian.m_ValueRadians());
    }*/

    /*!
    \fn m_RadianTangent
    \brief
    */
    /*static  float	m_RadianTangent(const C_Radian& prm_Radian) {
    return (float)std::tan(prm_Radian.m_ValueRadians());
    }*/

    //! Radian arcs
    /*!
    \fn m_Acos
    \brief
    */
    //->static C_Radian	m_Acos(float prm_Value);

    /*!
    \fn m_Asin
    \brief
    */
    //		static C_Radian	m_Asin(float prm_Value);

    /*!
    \fn m_Atan
    \brief
    */
    //static C_Radian	m_Atan(float prm_Value) { return C_Radian(std::atan(prm_Value)); }

    /*!
    \fn m_Atan2
    \brief
    */
    //static C_Radian	m_Atan2(float prm_Y, float prm_X) { return C_Radian(std::atan2(prm_Y, prm_X)); }

    template<class T, class U>
    /*!
    \fn m_Linear_Interpolation
    \brief Obtains linear interpolation between two scalar with a given alpha
    \param prm_A Reference to a scalar
    \param prm_B Reference to a scalar
    \param prm_Alpha Reference to the alpha
    */
    static  T	
    Linear_Interpolation(const T& prm_A, const T& prm_B, const U& prm_Alpha);
   

    template<class T>
    /*!
    \fn m_Minimum
    \brief Obtains minimum between two scalars
    \param prm_A Reference to a scalar
    \param prm_B Reference to a scalar
    */
    static 	T
      _Minimum(const T& prm_A, const T& prm_B);

    template<class T>
    /*!
    \fn m_Maximum
    \brief Obtains maximum between two scalars
    \param prm_A Reference to a scalar
    \param prm_B Reference to a scalar
    */
    static  T
      _Maximum(const T& prm_A, const T& prm_B);
  };
}
