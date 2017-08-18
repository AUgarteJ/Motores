#pragma once
#include "oePrerequisites_Graphics.h"

#if OE_ACTIVE_PLATFORM == OE_PLATFORM_WINDOWS
#	include "d3d11.h"
#endif

namespace oeEngineSDK
{
  class OE_GRAPHICS_API_EXPORT CSwapChain
  {
  private:
#if OE_ACTIVE_PLATFORM == OE_PLATFORM_WINDOWS
    IDXGISwapChain* pSwapChain;
#endif

  public:


    CSwapChain();
    ~CSwapChain();
    void create();
    void Destroy();
    void* getObject();
    void** getReference();
  };
}