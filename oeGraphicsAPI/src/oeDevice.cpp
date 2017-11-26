 #include "oeDevice.h"

namespace oeEngineSDK
{
  CDevice::CDevice()
  {
    m_Device = nullptr;

  }

  CDevice::~CDevice()
  {
    destroy();
  }

  void CDevice::destroy()
  {
    if (m_Device)
    {
      m_Device->Release();
      m_Device = nullptr;
    }
  }

  void* CDevice::getObject()
  {
    return reinterpret_cast<void*>(m_Device);
  }

  void** CDevice::getReference()
  {
    return reinterpret_cast<void**>(&m_Device);
  }
}
