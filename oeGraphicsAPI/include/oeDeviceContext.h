#pragma once
#include "oePrerequisites_Graphics.h"
#include "oeRenderTargetView.h"



#if OE_ACTIVE_PLATFORM == OE_PLATFORM_WINDOWS
#include <d3d11.h>
#endif

namespace oeEngineSDK
{
  class CDepthStencilV;
  class OE_GRAPHICS_API_EXPORT CDeviceContext
  {
  private:
    ID3D11DeviceContext* p_DeviceContext;
  public:
    CDeviceContext();
    ~CDeviceContext();
    
    void create();
    void destroy();
    void* getObject() const;
    void** getReference();

    void clearRenderTarget(const CRenderTargetView& rtv, float color[4]);
    void clearDepthStencilView(const CDepthStencilV& dsv, uint32 flags, float Depth, uint8 Stencil);
    void setTopology();
  };





}

