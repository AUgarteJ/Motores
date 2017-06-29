#pragma once
#include "oePrerequisites_Graphics.h"
#include "oeDevice.h"
#include "oeDeviceContext.h"
#if OE_ACTIVE_PLATFORM == OE_PLATFORM_WINDOWS
#include <d3d11.h>
#endif

namespace oeEngineSDK
{

  struct BufferData
  {
#if OE_ACTIVE_PLATFORM == OE_PLATFORM_WINDOWS
    BufferData() : m_Buffer(nullptr)
    {

    }
    ID3D11Buffer* m_Buffer;

#endif
  };

  class OE_GRAPHICS_API_EXPORT CBuffer
  {
  public:
    CBuffer();
    virtual ~CBuffer();

    BufferData* m_BufferData;
    virtual void  Create(const CDevice* pDevice, int32 flags) = 0;
    virtual void SetBuffer(const CDeviceContext* pDeviceContext, uint32 StartSlot = 0) = 0;
    virtual void Release() = 0;

  };
}
