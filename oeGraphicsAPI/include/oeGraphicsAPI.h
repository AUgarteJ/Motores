#pragma once
#include <oeModule.h>
#include "oePlatfomDefines_Utilities.h"
#include "oePrerequisites_Graphics.h"
#include "oeDevice.h"
#include "oeDeviceContext.h"
#include "oeRenderTargetView.h"
#include "oeSwapChain.h"
namespace oeEngineSDK {

  class OE_GRAPHICS_API_EXPORT oeGraphicsAPI : public Module<oeGraphicsAPI>
  {
  public:
    CDevice         m_Device;
    CDeviceContext  m_DeviceContext;
    CSwapChain              m_SwapChain;
    CRenderTargetView       m_pRenderTargetView;

    oeGraphicsAPI() {}
    ~oeGraphicsAPI();
  };

  OE_GRAPHICS_API_EXPORT oeGraphicsAPI& g_GraphicsAPI();
}