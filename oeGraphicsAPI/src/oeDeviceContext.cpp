#include "oeDeviceContext.h"

namespace oeEngineSDK
{
  CDeviceContext::CDeviceContext()
  {
    p_DeviceContext= nullptr;

  }

  CDeviceContext::~CDeviceContext()
  {
    destroy();
  }

  void CDeviceContext::destroy()
  {
    if (p_DeviceContext)
    {
      p_DeviceContext->Release();
      p_DeviceContext = nullptr;
    }
  }

  void* CDeviceContext::getObject()
  {
    return reinterpret_cast<void*>(p_DeviceContext);
  }

  void** CDeviceContext::getReference()
  {
    return reinterpret_cast<void**>(&p_DeviceContext);
  }
}
