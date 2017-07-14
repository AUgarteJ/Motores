#pragma once
#include "oePrerequisites_Graphics.h"
#include "oeDevice.h"
#include "oeDeviceContext.h"
#include <vector>
#if OE_ACTIVE_PLATFORM == OE_PLATFORM_WINDOWS
#include <d3d11.h>
#endif

namespace oeEngineSDK
{
  namespace BUFFER_USAGE_FLAGS {
    enum E {
      KDEFAULT =0x00,
      KDYNAMIC =0x01
    };
  }

  struct BufferData
  {
#if OE_ACTIVE_PLATFORM == OE_PLATFORM_WINDOWS
    BufferData() : m_Buffer(nullptr)
    {

    }
  private:
    ID3D11Buffer* m_Buffer;

#endif
  };

  class OE_GRAPHICS_API_EXPORT CBuffer
  {
  public:
    CBuffer();




    virtual ~CBuffer(){}
    BufferData* m_BufferData;
    virtual void Create(const CDevice* pDevice, int32 flags)
    {

    }
    virtual void SetBuffer(const CDeviceContext* pDeviceContext, uint32 StartSlot = 0){}
    virtual void Destroy(){}

  };

  template<class T>
  class OE_GRAPHICS_API_EXPORT oeIndexBuffer : public CBuffer
  {
  public:
    oeIndexBuffer();
   ~oeIndexBuffer();

   void Add(T nIndex);
   void Add(const std::vector <T>& nIndexArray);
   void Add(T* pArray, unsigned int nNumObjects);
   void Remove(unsigned int nIndex,unsigned int count = 1);
   void Clear();
   void CreateHardwareBuffer(int usageFlag=BUFFER_USAGE_FLAGS::KDEFAULT);

  private:
   std::vector<T> m_indexArray;


  };
}