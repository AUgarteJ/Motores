#include "oeDeviceContext.h"

namespace oeEngineSDK
{
  CDeviceContext::CDeviceContext()
  {
    p_DeviceContext= nullptr;

  }

  CDeviceContext::~CDeviceContext()
  {
    Destroy();
  }

  void CDeviceContext::Destroy()
  {
    if (p_DeviceContext)
    {
      p_DeviceContext->Release();
      p_DeviceContext = nullptr;
    }
  }

  void* CDeviceContext::GetObject()
  {
    return reinterpret_cast<void*>(p_DeviceContext);
  }

  void** CDeviceContext::GetReference()
  {
    return reinterpret_cast<void**>(&p_DeviceContext);
  }
}
