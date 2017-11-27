#pragma once
#include "oePrerequisites_Graphics.h"
#include "oeShader.h"
#if OE_ACTIVE_PLATFORM == OE_PLATFORM_WINDOWS
#include <d3d11.h>
#endif

namespace oeEngineSDK
{

  class CDevice;

  class OE_GRAPHICS_API_EXPORT CPixelShader : public CShaderBase
  {
  public:
    CPixelShader() : CShaderBase(), m_pIPixelShader(nullptr) {}
    ~CPixelShader() {};

    void Create(CDevice* pDevice, String fileName, String entryPoint);
    void SetShader(CDeviceContext* DeviceContext);
    ID3D11PixelShader* m_pIPixelShader;
  };
  }