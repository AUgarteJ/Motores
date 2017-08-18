 #include "oeDevice.h"

namespace oeEngineSDK
{
  CDevice::CDevice()
  {
    m_Device = nullptr;

  }

  CDevice::~CDevice()
  {
    Destroy();
  }

  void CDevice::Destroy()
  {
    if (m_Device)
    {
      m_Device->Release();
      m_Device = nullptr;
    }
  }

  void* CDevice::GetObject()
  {
    return reinterpret_cast<void*>(m_Device);
  }

  void** CDevice::GetReference()
  {
    return reinterpret_cast<void**>(&m_Device);
  }
}
