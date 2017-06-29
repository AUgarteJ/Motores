#pragma once
#include "oePrerequisites_Graphics.h"


#if OE_ACTIVE_PLATFORM == OE_PLATFORM_WINDOWS
#include <d3d11.h>
#endif

namespace oeEngineSDK
{
  class OE_GRAPHICS_API_EXPORT CDevice
  {
  private:
    ID3D11Device* p_Device;
  public:
    CDevice();
    ~CDevice();
    void Create();
    void Destroy();
    void* GetObject();
    void** GetReference();

  };





}

