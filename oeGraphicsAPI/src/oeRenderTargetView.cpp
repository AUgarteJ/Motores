#include "oeRenderTargetView.h"

namespace oeEngineSDK
{
  CRenderTargetView::CRenderTargetView()
  {
    p_RenderTargetView = nullptr;

  }

  CRenderTargetView::~CRenderTargetView()
  {
    destroy();
  }

  void CRenderTargetView::create()
  {
    //TODO
  }
  void CRenderTargetView::destroy()
  {
    if (p_RenderTargetView)
    {
      p_RenderTargetView->Release();
      p_RenderTargetView = nullptr;
    }
  }

  void* CRenderTargetView::getObject() const
  {
    return reinterpret_cast<void*>(p_RenderTargetView);
  }

  void** CRenderTargetView::getReference()
  {
    return reinterpret_cast<void**>(&p_RenderTargetView);
  }
}