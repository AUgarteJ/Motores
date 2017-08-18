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

  template<typename T>
  class CVertexBuffer : public CBuffer
  {
  public:
    CVertexBuffer();
    ~CVertexBuffer();

    void Add(T nIndex);
    void Add(const std::vector<T>& nIndexArray);
    void Add(T* pArray, unsigned int nNumObjects);

    void Remove(unsigned int nIndex, unsigned int count = 1);
    void Clear();

    void CreateHardwareBuffer(int usageFlags = BUFFER_USAGE_FLAGS::kDEFAULT);
    void SetHardwareBuffer(uint32 Slot = 0, uint32 offset = 0);

  private:
    std::vector<T> m_vertexArray;
  };

  template<class T>
  CVertexBuffer<T>::CVertexBuffer() {

  }

  template<class T>
  CVertexBuffer<T>::~CVertexBuffer() {

  }

  template<typename T>
  void CVertexBuffer<T>::Add(T nVertex)
  {
    m_vertexArray.push_back(nVertex);
  }

  template<typename T>
  void CVertexBuffer<T>::Add(const std::vector<T>& nVertexArray)
  {
    Add(&nVertexArray[0], nVertexArray.size());
  }

  template<typename T>
  void CVertexBuffer<T>::Add(T * pArray, unsigned int nNumObjects)
  {
    for (unsigned int i = 0; i < nNumObjects; ++i) {
      m_vertexArray.push_back(pArray[i]);
    }
  }

  template<typename T>
  void CVertexBuffer<T>::Remove(unsigned int nvertex, unsigned int count)
  {
    m_vertexArray.erase(m_vertexArray.begin() + nvertex,
      (m_vertexArray.begin() + nvertex) + (count - 1));
  }

  template<typename T>
  void CVertexBuffer<T>::Clear()
  {
    m_vertexArray.clear();
  }

  template<typename T>
  void CVertexBuffer<T>::CreateHardwareBuffer(int usageFags)
  {
    if (!m_vertexArray.size()) {
      return;
    }
    D3D11_BUFFER_DESC vertexBufferDesc;
    memset(&vertexBufferDesc, 0, sizeof(D3D11_BUFFER_DESC));


    if (BUFFER_USAGE_FLAGS::KDEFAULT & usageFags) {
      vertexBufferDesc.Usage = D3D11_USAGE_DEFAULT;
    }

    if (BUFFER_USAGE_FLAGS::KDYNAMIC & usageFags) {
      vertexBufferDesc.Usage = D3D11_USAGE_DYNAMIC;
    }

    vertexBufferDesc.ByteWidth = sizeof(T) * m_vertexArray.size();
    vertexBufferDesc.BindFlags = D3D11_BIND_VERTEX_BUFFER;
    vertexBufferDesc.CPUAccessFlags = 0;
    vertexBufferDesc.MiscFlags = 0;
    vertexBufferDesc.StructureByteStride = 0;

    oeGraphicsAPI* pGraphicsAPI = g_GraphicsAPI().instancePtr();
    ID3D11Device* pDevice = reinterpret_cast<ID3D11Device*>(pGraphicsAPI->m_Device.getObject());

    D3D11_SUBRESOURCE_DATA srData;
    srData.pSysMem = &m_vertexArray[0];
    srData.SysMemPitch = 0;
    srData.SysMemSlicePitch = 0;

    HRESULT result = pDevice->CreateBuffer(&vertexBufferDesc, &srData, &m_pBuffer);
    if (FAILED(result))
    {
      return;
    }
  }

  template<typename T>
  void CVertexBuffer<T>::SetHardwareBuffer(uint32 Slot, uint32 offset)
  {
    oeGraphicsAPI* pGraphicsAPI = g_GraphicsAPI().instancePtr();
    ID3D11DeviceContext* pDeviceContext = reinterpret_cast<ID3D11DeviceContext*>
      (pGraphicsAPI->m_DeviceContext.getObject());

    // Set vertex buffer
    uint32 stride = sizeof(T);
    pDeviceContext->IASetVertexBuffers(Slot, 1, &m_pBuffer, &stride, &offset);
  }
}