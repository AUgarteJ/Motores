#pragma once
#include "oePrerequisites_Graphics.h"
#include "oeGraphicsAPI.h"
#include "oeDevice.h"
#include "oeDeviceContext.h"
#include <vector>
#if OE_ACTIVE_PLATFORM == OE_PLATFORM_WINDOWS
#include <d3d11.h>
#endif

namespace oeEngineSDK
{
  namespace  BUFFER_USAGE_FLAGS {
    enum  E {
      KDEFAULT = 0x00,
      KDYNAMIC = 0x01
    };
  }

  struct BufferData
  {
#if OE_ACTIVE_PLATFORM == OE_PLATFORM_WINDOWS
    BufferData() : m_Buffer(nullptr)
    {

    }
  public:
    void** GetReference()
    {
      return reinterpret_cast<void**>(&m_Buffer);
    }
    void* GetObject()
    {
      return reinterpret_cast<void*>(m_Buffer);
    }

    bool isBufferInitialized() {
      return nullptr != m_Buffer;
    }

  private:
    ID3D11Buffer* m_Buffer;

#endif
  };

  class OE_GRAPHICS_API_EXPORT CBuffer
  {
  public:
    CBuffer() {};
    virtual ~CBuffer() {}

    BufferData* m_BufferData;
    virtual void Create(const CDevice* pDevice, int32 flags) {}

    virtual void SetBuffer(const CDeviceContext* pDeviceContext, uint32 StartSlot = 0) {}
    virtual void Destroy() {}

  };
  //////////////////////////////////////////////////////////////////////////

  template<class T>
  class  oeIndexBuffer : public CBuffer
  {
  public:
    oeIndexBuffer();
    ~oeIndexBuffer();

    void Add(T nIndex);
    void Add(const std::vector <T>& m_indexArray);
    void Add(T* pArray, unsigned int nNumObjects);
    void Remove(unsigned int nIndex, unsigned int count = 1);
    void Clear();
    void CreateHardwareBuffer(int usageFlag = BUFFER_USAGE_FLAGS::KDEFAULT);
    void SetHardwareBuffer(uint32 Slot = 0, uint32 offset = 0);

    SIZE_T getIndexCount() {
      return m_indexArray.size();
    }
  private:
    std::vector<T> m_indexArray;


  };
  //////////////////////////////////////////////////////////////////////////

  template<typename T>
  class CVertexBuffer : public CBuffer
  {
  public:
    CVertexBuffer();
    ~CVertexBuffer();

    void Add(T nIndex);
    void Add(const std::vector<T>& vertexArray);
    void Add(T* pArray, unsigned int nNumObjects);

    void Remove(unsigned int nIndex, unsigned int count = 1);
    void Clear();

    void CreateHardwareBuffer(int usageFlag = BUFFER_USAGE_FLAGS::KDEFAULT);
    void SetHardwareBuffer(uint32 Slot = 0, uint32 offset = 0);

    SIZE_T getVertexCount() {
      return m_vertexArray.size();
    }

  private:
    std::vector<T> m_vertexArray;
  };
  //////////////////////////////////////////////////////////////////////////

  template<class T>
  CVertexBuffer<T>::CVertexBuffer() {
    m_BufferData = new BufferData();
  }

  template<class T>
  CVertexBuffer<T>::~CVertexBuffer() {
    delete m_BufferData;
  }

  template<typename T>
  void CVertexBuffer<T>::Add(T nVertex)
  {
    m_vertexArray.push_back(nVertex);
  }

  template<typename T>
  void CVertexBuffer<T>::Add(const std::vector<T>& nVertexArray)
  {
    Add( &(const_cast<std::vector<T>&>(nVertexArray)[0]) , nVertexArray.size());
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
      (m_vertexArray.begin() + nvertex) + (count));
   
  }

  template<typename T>
  void CVertexBuffer<T>::Clear()
  {
    m_vertexArray.clear();
  }

  template<typename T>
  void CVertexBuffer<T>::CreateHardwareBuffer(int usageFlag)
  {
    if (!m_vertexArray.size()) {
      return;
    }
    D3D11_BUFFER_DESC vertexBufferDesc;
    memset(&vertexBufferDesc, 0, sizeof(D3D11_BUFFER_DESC));


    if (BUFFER_USAGE_FLAGS::KDEFAULT & usageFlag) {
      vertexBufferDesc.Usage = D3D11_USAGE_DEFAULT;
    }

    if (BUFFER_USAGE_FLAGS::KDYNAMIC & usageFlag) {
      vertexBufferDesc.Usage = D3D11_USAGE_DYNAMIC;
    }

    vertexBufferDesc.ByteWidth = sizeof(T) * m_vertexArray.size();
    vertexBufferDesc.BindFlags = D3D11_BIND_VERTEX_BUFFER;
    vertexBufferDesc.CPUAccessFlags = 0;
    vertexBufferDesc.MiscFlags = 0;
    vertexBufferDesc.StructureByteStride = 0;

    oeGraphicsAPI* pGraphicsAPI = g_GraphicsAPI().instancePtr();
    if (nullptr == pGraphicsAPI) {
      return;
    }
    ID3D11Device* pDevice = reinterpret_cast<ID3D11Device*>(pGraphicsAPI->m_Device.getObject());
    if (nullptr == pDevice) {
      return;
    }

    D3D11_SUBRESOURCE_DATA srData;
    srData.pSysMem = &m_vertexArray[0];
    srData.SysMemPitch = 0;
    srData.SysMemSlicePitch = 0;

    ID3D11Buffer** pBuffer = reinterpret_cast<ID3D11Buffer**>(m_BufferData->GetReference());
    HRESULT result = pDevice->CreateBuffer(&vertexBufferDesc, &srData, pBuffer);
    if (FAILED(result))
    {
      return;
    }
  }
  //////////////////////////////////////////////////////////////////////////
  template<typename T>
  void CVertexBuffer<T>::SetHardwareBuffer(uint32 Slot, uint32 offset)
  {
    oeGraphicsAPI* pGraphicsAPI = g_GraphicsAPI().instancePtr();
    ID3D11DeviceContext* pDeviceContext = reinterpret_cast<ID3D11DeviceContext*>
      (pGraphicsAPI->m_DeviceContext.getObject());

    // Set vertex buffer
    uint32 stride = sizeof(T);
    ID3D11Buffer* pBuffer = reinterpret_cast<ID3D11Buffer*>(m_BufferData->GetObject());
    pDeviceContext->IASetVertexBuffers(Slot, 1, &pBuffer, &stride, &offset);
  }
//////////////////////////////////////////////////////////////////////////
                           ////   index    ////

  template <class T>
  void oeIndexBuffer<T>::SetHardwareBuffer(uint32 Slot = 0, uint32 offset = 0)
  {
    oeGraphicsAPI* pGraphicsAPI = g_GraphicsAPI().instancePtr();
    ID3D11DeviceContext* pDeviceContext = reinterpret_cast<ID3D11DeviceContext*>
      (pGraphicsAPI->m_DeviceContext.getObject());

    // Set vertex buffer
    uint32 stride = sizeof(T);
    ID3D11Buffer* pBuffer = reinterpret_cast<ID3D11Buffer*>(m_BufferData->GetObject());
    pDeviceContext->IASetIndexBuffer(pBuffer, DXGI_FORMAT_R32_UINT, 0);
  }

  template <class T>
  oeIndexBuffer<T>::oeIndexBuffer()
  {
    m_BufferData = new BufferData();
  }

  template <class T>
  oeIndexBuffer<T>::~oeIndexBuffer()
  {
    delete m_BufferData;
  }

  template<class T>
  void oeIndexBuffer<T>::Add(T nIndex)
  {
    m_indexArray.push_back(nIndex);
  }

  template<class T>
  void oeIndexBuffer<T>::Add(const std::vector<T>& m_indexArray)
  {
  }

  template<class T>
  void oeIndexBuffer<T>::Add(T * pArray, unsigned int nNumObjects)
  {
    for (unsigned int i = 0; i < nNumObjects; ++i) {
      m_indexArray.push_back(pArray[i]);
    }
  }

  template<class T>
  void oeIndexBuffer<T>::Remove(unsigned int nIndex, unsigned int count)
  {
    m_indexArray.erase(m_indexArray.begin() + nIndex,
      (m_indexArray.begin() + nIndex) + (count ));
  }

  template<typename T>
  void oeIndexBuffer<T>::Clear()
  {
    m_indexArray.clear();
  }

  template<class T>
  void oeIndexBuffer<T>::CreateHardwareBuffer(int usageFlag)
  {
    if (!m_indexArray.size()) {
      return;
    }
    D3D11_BUFFER_DESC indexBufferDesc;
    memset(&indexBufferDesc, 0, sizeof(D3D11_BUFFER_DESC));


    if (BUFFER_USAGE_FLAGS::KDEFAULT & usageFlag) {
      indexBufferDesc.Usage = D3D11_USAGE_DEFAULT;
    }

    if (BUFFER_USAGE_FLAGS::KDYNAMIC & usageFlag) {
      indexBufferDesc.Usage = D3D11_USAGE_DYNAMIC;
    }

    D3D11_SUBRESOURCE_DATA srData;
    srData.pSysMem = &m_indexArray[0];
    srData.SysMemPitch = 0;
    srData.SysMemSlicePitch = 0;

    indexBufferDesc.ByteWidth = sizeof(T) * m_indexArray.size();
    indexBufferDesc.BindFlags = D3D11_BIND_INDEX_BUFFER;
    indexBufferDesc.CPUAccessFlags = 0;
    indexBufferDesc.MiscFlags = 0;
    indexBufferDesc.StructureByteStride = 0;

    oeGraphicsAPI* pGraphicsAPI = g_GraphicsAPI().instancePtr();
    if (nullptr == pGraphicsAPI) {
      return;
    }
    ID3D11Device* pDevice = reinterpret_cast<ID3D11Device*>(pGraphicsAPI->m_Device.getObject());
    if (nullptr == pDevice) {
      return;
    }

    ID3D11Buffer** pBuffer = reinterpret_cast<ID3D11Buffer**>(m_BufferData->GetReference());
    HRESULT result = pDevice->CreateBuffer(&indexBufferDesc, &srData, pBuffer);

    if (FAILED(result))
    {
      return ;
    }

  }

  typedef oeIndexBuffer<unsigned short> oeIndexBuffer16;
  typedef oeIndexBuffer<unsigned int> oeIndexBuffer32;
}