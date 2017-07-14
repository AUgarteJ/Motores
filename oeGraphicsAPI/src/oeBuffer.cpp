#include "oeBuffer.h"
namespace oeEngineSDK
{





  CBuffer::CBuffer()
  {

  }




  template <class T>
  oeIndexBuffer<T>::oeIndexBuffer()
  {

  }

  template <class T>
  oeIndexBuffer<T>::~oeIndexBuffer()
  {

  }

  template<class T>
  void oeIndexBuffer<T>::Add(T nIndex)
  {
    m_indexArray.push_back(nIndex);
  }

  template<class T>
  void oeIndexBuffer<T>::Add(const std::vector<T>& nIndexArray)
  {
  }

  template<class T>
  void oeIndexBuffer<T>::Add(T * pArray, unsigned int nNumObjects)
  {
    for (unsigned int i = 0; i < nNumObjects; ++i) {
      nIndexArray.push_back(pArray[i]);
    }
  }

  template<class T>
  void oeIndexBuffer<T>::Remove(unsigned int nIndex, unsigned int count)
  {
    nIndexArray.erase(nIndexArray.begin() + nIndex,
      (nIndexArray.begin() + nIndex) + (count - 1));
  }



  template<class T>
  void oeIndexBuffer<T>::CreateHardwareBuffer(int usageFlag)
  {
    if (!nIndexArray.size()) {
      return;
    }
    D3D11_BUFFER_DESC indexBufferDesc;
    memset(&indexBufferDesc, 0; sizeof(D3D11_BUFFER_DESC));


    if (BUFFER_USAGE_FLAGS::KDEFAULT & usageFags) {
      indexBufferDesc.Usage |= D3D11_USAGE_DEFAULT;
    }

    if (BUFFER_USAGE_FLAGS::KDYNAMIC & usageFags) {
      indexBufferDesc |= D3D11_USAGE_DEFAULT;
    }

    indexBufferDesc.ByteWidth = sizeof(T) * nIndexArray.size();
    indexBufferDesc.BindFlags = D3D11_BIND_CONSTANT_BUFFER;
    indexBufferDesc.CPUAccessFlags = 0;
    indexBufferDesc.MiscFlags = 0;
    indexBufferDesc.StructureByteStride = 0;

    HRESULT result = device->CreateBuffer(&indexBufferDesc, indexData, &m_pBuffer);
    if (FAILED(result))
    {
      return false;
    }

  }

  typedef oeIndexBuffer<unsigned short> oeIndexBuffer16;
  typedef oeIndexBuffer<unsigned int> oeIndexBuffer32;
}