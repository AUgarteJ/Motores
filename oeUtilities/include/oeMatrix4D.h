#pragma once
#include "oePrerequisites_Utilities.h"
#include "oeVector4.h"


namespace oeEngineSDK
{

  MS_ALIGN(16) class OE_UTILITIES_EXPORT Matrix4
  {
  public:
    union
    {
      struct
      {
        float m00, m01, m02, m03,
              m10, m11, m12, m13,
              m20, m21, m22, m23,
              m30, m31, m32, m33;
      }m_Elements;
      Vector4 m_row[4];
      float fMatrix[4][4];
      float m_Linear[16];
    };



    void add(const Matrix4& fMa);//, const Matrix4& fMb);
    void rest(const Matrix4& fMa);//, const Matrix4& fMb);
    Matrix4 mult(const Matrix4& fMa); //Matrix4& fMb);
   
    Matrix4 projectionFovLH(float FovAngleY, float AspectHByW, float NearZ, float FarZ);
    Matrix4 lookAtLH(Vector4 EyePosition, Vector4 FocusPosition, Vector4 UpDirection);
    Vector4 vectorSubtract(Vector4 V1, Vector4 V2);
    Matrix4 MatrixLooktoLH(Vector4 EyePosition, Vector4 EyeDirection, Vector4 UpDirection);
   
    void Transposed();//const Matrix4& fMa);
                      //Matrix4 Transposed(const Matrix4& fMa);



    Matrix4();
    //Matrix4(Matrix4 a);
    Matrix4(float a, float b, float c, float d,
            float e,float f, float g, float h, 
            float i, float j, float k, float l,
            float m, float n, float o, float p);

    Matrix4(Vector4* a, Vector4* b, Vector4* c, Vector4* d);
    ~Matrix4();

  }GCC_ALIGN(16);
}
