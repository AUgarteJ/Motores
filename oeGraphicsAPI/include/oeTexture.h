#pragma once
#include "oePrerequisites_Graphics.h"
#if OE_ACTIVE_PLATFORM == OE_PLATFORM_WINDOWS
#include <d3d11.h>
#endif
namespace oeEngineSDK
{
  struct  TextureData
  {
#if OE_ACTIVE_PLATFORM == OE_PLATFORM_WINDOWS
    ID3D11Texture1D* m_Texture1D;
    ID3D11Texture2D* m_Texture2D;
    
#endif
  };
  class OE_GRAPHICS_API_EXPORT CTexture
  {
  public:
    CTexture() {};
    virtual ~CTexture() {};
    virtual void CreateFromFile(const char* FileName=0);
    virtual void CreateEmpty()=0;
    virtual void Release() = 0;

  };


}

