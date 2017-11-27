#pragma once

#include "oeShader.h"

struct ID3D11VertexShader;

namespace oeEngineSDK
{
  class CDevice;

  class OE_GRAPHICS_API_EXPORT CVertexShader : public CShaderBase
  {
  public:
    CVertexShader() : CShaderBase(), m_pIVertexShader(nullptr) {};
    ~CVertexShader() {};
    void SetShader(CDeviceContext* DeviceContext);
    void Create(CDevice* pDevice, String fileName, String entryPoint);

    ID3D11VertexShader* m_pIVertexShader;
  };
}
