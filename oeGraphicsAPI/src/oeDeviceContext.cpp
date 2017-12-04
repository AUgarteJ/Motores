#include "oeDeviceContext.h"
#include "oeBuffer.h"

namespace oeEngineSDK
{
  CDeviceContext::CDeviceContext()
  {
    p_DeviceContext= nullptr;

  }

  CDeviceContext::~CDeviceContext()
  {
    destroy();
  }

  void CDeviceContext::destroy()
  {
    if (p_DeviceContext)
    {
      p_DeviceContext->Release();
      p_DeviceContext = nullptr;
    }
  }

  void* CDeviceContext::getObject() const
  {
    return reinterpret_cast<void*>(p_DeviceContext);
  }

  void** CDeviceContext::getReference()
  {
    return reinterpret_cast<void**>(&p_DeviceContext);
  }

  void CDeviceContext::clearRenderTarget(const CRenderTargetView& rtv, float color[4])
  {
    ID3D11RenderTargetView* pRTV = reinterpret_cast<ID3D11RenderTargetView*>(rtv.getObject());
    p_DeviceContext->ClearRenderTargetView(pRTV, color);
  }

  void CDeviceContext::clearDepthStencilView(const CDepthStencilV& dsv, uint32 flags, float Depth, uint8 Stencil)
  {
    p_DeviceContext->ClearDepthStencilView(dsv.m_pDepthSV, flags, Depth, Stencil);
  }

  void CDeviceContext::setTopology()
  {
    p_DeviceContext->IASetPrimitiveTopology(D3D11_PRIMITIVE_TOPOLOGY_TRIANGLELIST);
  }
}
