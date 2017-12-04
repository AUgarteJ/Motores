#include "oeMatrix4D.h"

namespace oeEngineSDK
{

Matrix4::Matrix4()
  {
  memset(this, 0, sizeof(Matrix4));
  }


Matrix4::Matrix4(float a, float b, float c, float d, float e, float f, float g, float h, float i, float j, float k, float l, float m, float n, float o, float p)
  {
    fMatrix[0][0] = a;
    fMatrix[0][1] = b;
    fMatrix[0][2] = c;
    fMatrix[0][3] = d;

    fMatrix[1][0] = e;
    fMatrix[1][1] = f;
    fMatrix[1][2] = g;
    fMatrix[1][3] = h;

    fMatrix[2][0] = i;
    fMatrix[2][1] = j;
    fMatrix[2][2] = k;
    fMatrix[2][3] = l;

    fMatrix[3][0] = m;
    fMatrix[3][1] = n;
    fMatrix[3][2] = o;
    fMatrix[3][3] = p;
  }

Matrix4::Matrix4(Vector4* a, Vector4* b, Vector4* c, Vector4* d)
  {
    fMatrix[0][0] = a->x;
    fMatrix[0][1] = a->y;
    fMatrix[0][2] = a->z;
    fMatrix[0][3] = a->w;

    fMatrix[1][0] = b->x;
    fMatrix[1][1] = b->y;
    fMatrix[1][2] = b->z;
    fMatrix[1][3] = b->w;

    fMatrix[2][0] = c->x;
    fMatrix[2][1] = c->y;
    fMatrix[2][2] = c->z;
    fMatrix[2][3] = c->w;

    fMatrix[3][0] = d->x;
    fMatrix[3][1] = d->y;
    fMatrix[3][2] = d->z;
    fMatrix[3][3] = d->w;
  }


Matrix4::~Matrix4()
  {
  }


  void Matrix4::add(const Matrix4& fMa)
  {


    for (int i = 0; i < 4; i++)
    {

      for (int j = 0; i < 4; i++)
      {
        fMatrix[i][j] = fMatrix[i][j] + fMa.fMatrix[i][j];
      }

    }


  }
  void Matrix4::rest(const Matrix4& fMa)
  {


    for (int i = 0; i < 4; i++)
    {

      for (int j = 0; i < 4; i++)
      {
        fMatrix[i][j] = fMatrix[i][j] - fMa.fMatrix[i][j];
      }

    }


  }
Matrix4 Matrix4::mult(const Matrix4& fMa)
  {

  Matrix4 Result;

    Result.fMatrix[0][0] = (fMatrix[0][0] * fMa.fMatrix[0][0]) + (fMatrix[0][1] + fMa.fMatrix[1][0]) + (fMatrix[0][2] * fMa.fMatrix[2][0]);
    Result.fMatrix[0][1] = (fMatrix[0][0] * fMa.fMatrix[0][1]) + (fMatrix[0][1] * fMa.fMatrix[1][1]) + (fMatrix[0][2] * fMa.fMatrix[2][1]);
    Result.fMatrix[0][2] = (fMatrix[0][0] * fMa.fMatrix[0][2]) + (fMatrix[0][1] * fMa.fMatrix[1][2]) + (fMatrix[0][2] * fMa.fMatrix[2][2]);
    Result.fMatrix[0][3] = (fMatrix[0][0] * fMa.fMatrix[0][3]) + (fMatrix[0][1] * fMa.fMatrix[1][3]) + (fMatrix[0][2] * fMa.fMatrix[2][3]);


    Result.fMatrix[1][0] = (fMatrix[1][0] * fMa.fMatrix[0][0]) + (fMatrix[1][1] + fMa.fMatrix[1][0]) + (fMatrix[1][2] * fMa.fMatrix[2][0]);
    Result.fMatrix[1][1] = (fMatrix[1][0] * fMa.fMatrix[0][1]) + (fMatrix[1][1] * fMa.fMatrix[1][1]) + (fMatrix[1][2] * fMa.fMatrix[2][1]);
    Result.fMatrix[1][2] = (fMatrix[1][0] * fMa.fMatrix[0][2]) + (fMatrix[1][1] * fMa.fMatrix[1][2]) + (fMatrix[1][2] * fMa.fMatrix[2][2]);
    Result.fMatrix[1][3] = (fMatrix[1][0] * fMa.fMatrix[0][3]) + (fMatrix[1][1] * fMa.fMatrix[1][3]) + (fMatrix[1][2] * fMa.fMatrix[2][3]);


    Result.fMatrix[2][0] = (fMatrix[2][0] * fMa.fMatrix[0][0]) + (fMatrix[2][1] + fMa.fMatrix[1][0]) + (fMatrix[2][2] * fMa.fMatrix[2][0]);
    Result.fMatrix[2][1] = (fMatrix[2][0] * fMa.fMatrix[0][1]) + (fMatrix[2][1] * fMa.fMatrix[1][1]) + (fMatrix[2][2] * fMa.fMatrix[2][1]);
    Result.fMatrix[2][2] = (fMatrix[2][0] * fMa.fMatrix[0][2]) + (fMatrix[2][1] * fMa.fMatrix[1][2]) + (fMatrix[2][2] * fMa.fMatrix[2][2]);
    Result.fMatrix[2][3] = (fMatrix[2][0] * fMa.fMatrix[0][3]) + (fMatrix[2][1] * fMa.fMatrix[1][3]) + (fMatrix[2][2] * fMa.fMatrix[2][3]);


    return Result;

  }



  void Matrix4::Transposed()
  {
    Matrix4 Temp;

    for (int i = 0; i < 4; i++)
    {
      for (int j = 0; j < 4; j++)
      {
        Temp.fMatrix[i][j] = fMatrix[i][j];
      }
    }

    for (int i = 0; i < 4; i++)
    {
      for (int j = 0; j < 4; j++)
      {
        fMatrix[j][i] = Temp.fMatrix[i][j];
      }
    }
  }

  Matrix4  Matrix4 :: projectionFovLH(float FovAngleY, float AspectHByW, float NearZ, float FarZ)
  {
    float    SinFov;
    float    CosFov;

    SinFov = CMath::Sine(FovAngleY * 0.5f);
    CosFov = CMath::Cosine(FovAngleY * 0.5f);

    float Height = CosFov / SinFov;
    float Width = Height / AspectHByW;
    float fRange = FarZ / (FarZ - NearZ);

    Matrix4 M;
    M.m_Elements.m00 = Width;
    M.m_Elements.m01 = 0.0f;
    M.m_Elements.m02 = 0.0f;
    M.m_Elements.m03 = 0.0f;

    M.m_Elements.m10 = 0.0f;
    M.m_Elements.m11 = Height;
    M.m_Elements.m12 = 0.0f;
    M.m_Elements.m13 = 0.0f;

    M.m_Elements.m20 = 0.0f;
    M.m_Elements.m21 = 0.0f;
    M.m_Elements.m22 = fRange;
    M.m_Elements.m23 = 0.0f;

    M.m_Elements.m30 = 0.0f;
    M.m_Elements.m31 = 0.0f;
    M.m_Elements.m32 = -fRange * NearZ;
    M.m_Elements.m33 = 0.0f;

    return M;

  }
  Vector4 Matrix4::vectorSubtract(Vector4 V1, Vector4 V2)
  {
    Vector4 Result;

    Result.x = V1.x - V2.x;
    Result.y = V1.y - V2.y;
    Result.z = V1.z - V2.z;
    Result.w = V1.w - V2.w;
    return Result;

  }
  Matrix4 Matrix4::MatrixLooktoLH(Vector4 EyePosition, Vector4 EyeDirection, Vector4 UpDirection)
  {
    Matrix4 M;
    
    Vector4 ZAxis = EyeDirection.Normalize();
    Vector4 XAxis = UpDirection.CrossProduct(ZAxis).Normalize();
    Vector4 YAxis = ZAxis.CrossProduct(XAxis);

    for (uint32 RowIndex = 0; RowIndex < 3; ++RowIndex)
    {
      M.fMatrix[RowIndex][0] = (&XAxis.x)[RowIndex];
      M.fMatrix[RowIndex][1] = (&YAxis.x)[RowIndex];
      M.fMatrix[RowIndex][2] = (&ZAxis.x)[RowIndex];
      M.fMatrix[RowIndex][3] = 0.0f;
    }
    
    Vector4 negEyePosition = EyePosition.NegVector();
    M.fMatrix[3][0] = negEyePosition.DotProduct(XAxis);
    M.fMatrix[3][1] = negEyePosition.DotProduct(YAxis);
    M.fMatrix[3][2] = negEyePosition.DotProduct(ZAxis);
    M.fMatrix[3][3] = 1.0f;

    return M;

  }
  Matrix4 Matrix4::lookAtLH(Vector4 EyePosition, Vector4 FocusPosition, Vector4 UpDirection)
  { 
    Vector4 EyeDirection = FocusPosition - EyePosition;
    return MatrixLooktoLH(EyePosition, EyeDirection, UpDirection);
  }

}
