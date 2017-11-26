#pragma once
#include "oePrerequisites_Graphics.h"


#if OE_ACTIVE_PLATFORM == OE_PLATFORM_WINDOWS
#include <d3d11.h>
#endif

namespace oeEngineSDK
{
  class OE_GRAPHICS_API_EXPORT CDevice
  {
  
   
  public:
    ID3D11Device* m_Device;
    CDevice();
    ~CDevice();
    void create();
    void destroy();
    void* getObject();
    void** getReference();

  };





}

