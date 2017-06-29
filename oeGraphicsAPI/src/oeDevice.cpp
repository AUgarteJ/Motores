#include "oeDevice.h"

namespace oeEngineSDK
{
  CDevice::CDevice()
  {
    p_Device = nullptr;

  }

  CDevice::~CDevice()
  {
    Destroy();
  }

  void CDevice::Destroy()
  {
    if (p_Device)
    {
      p_Device->Release();
      p_Device = nullptr;
    }
  }

  void* CDevice::GetObject()
  {
    return reinterpret_cast<void*>(p_Device);
  }

  void** CDevice::GetReference()
  {
    return reinterpret_cast<void**>(&p_Device);
  }
}
