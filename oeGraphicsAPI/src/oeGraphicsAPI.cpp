#include "oeGraphicsAPI.h"

namespace oeEngineSDK{
  oeGraphicsAPI::~oeGraphicsAPI()
  {
    m_pRenderTargetView.Destroy();
    m_SwapChain.Destroy();
    m_DeviceContext.Destroy();
    m_Device.Destroy();
  }

  oeGraphicsAPI& g_GraphicsAPI()
  {
    return oeGraphicsAPI::instance();
  }
}