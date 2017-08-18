#include "oeRenderTargetView.h"

namespace oeEngineSDK
{
  CRenderTargetView::CRenderTargetView()
  {
    p_RenderTargetView = nullptr;

  }

  CRenderTargetView::~CRenderTargetView()
  {
    Destroy();
  }

  void CRenderTargetView::Create()
  {
    //TODO
  }
  void CRenderTargetView::Destroy()
  {
    if (p_RenderTargetView)
    {
      p_RenderTargetView->Release();
      p_RenderTargetView = nullptr;
    }
  }

  void* CRenderTargetView::GetObject()
  {
    return reinterpret_cast<void*>(p_RenderTargetView);
  }

  void** CRenderTargetView::GetReference()
  {
    return reinterpret_cast<void**>(&p_RenderTargetView);
  }
}