#include "oeSwapChain.h"

namespace oeEngineSDK
{
  CSwapChain::CSwapChain()
  {
    pSwapChain = nullptr;
  }

  CSwapChain::~CSwapChain()
  {
    Destroy();
  }
  void CSwapChain::create()
  {

  }

 

  void* CSwapChain::getObject()
  {
    return reinterpret_cast<void*>(pSwapChain);
  }

  void** CSwapChain::getReference()
  {
    return reinterpret_cast<void**>(&pSwapChain);
  }

  void CSwapChain::Destroy()
  {
    if (pSwapChain)
    {
      pSwapChain->Release();
      pSwapChain = nullptr;
    }
  }
}
