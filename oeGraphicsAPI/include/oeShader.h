#pragma once
#include "oePrerequisites_Graphics.h"
#include "oeDeviceContext.h"

#if OE_ACTIVE_PLATFORM == OE_PLATFORM_WINDOWS
#	include<d3d11.h>
#endif

namespace oeEngineSDK
{
  class OE_GRAPHICS_API_EXPORT CShaderBase
  {
  public:
    CShaderBase() {}
    virtual ~CShaderBase() {}
   
    void Compile(String fileName, String entryPoint, String targetStr);
    virtual void SetShader(CDeviceContext* DeviceContext) = 0;
 /* public:
    static const String SM_VS;
    static const String SM_PS;*/

  public:
    ID3DBlob* m_pBlob;
  };
}
