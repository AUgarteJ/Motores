#pragma once
#include "oePrerequisites_Graphics.h"


#if OE_ACTIVE_PLATFORM == OE_PLATFORM_WINDOWS
#include <d3d11.h>
#endif

namespace oeEngineSDK
{
  class OE_GRAPHICS_API_EXPORT CRenderTargetView
  {
  private:
    ID3D11RenderTargetView* p_RenderTargetView;
  public:
    CRenderTargetView();
    ~CRenderTargetView();
    void Create();
    void Destroy();
    void* GetObject();
    void** GetReference();

  };

}