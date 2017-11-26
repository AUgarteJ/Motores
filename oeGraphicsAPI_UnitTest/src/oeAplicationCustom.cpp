#include "oeAplicationCustom.h"
#include <oeModel.h>

namespace oeEngineSDK {

  OECustomAplication::OECustomAplication()
  { 
    m_szTitle = "La ventana y asi";
    m_iScrWidth = 1280;
    m_iScrHeight = 720;
  }

  OECustomAplication::~OECustomAplication()
  {
  }

  void OECustomAplication::OnInitialize()
  {
    CModel myModel;
    myModel.loadModel("Resources/Models/Cube.3ds");
  }

  void OECustomAplication::OnUpdate()
  {
  }

  void OECustomAplication::OnRender()
  {
    oeGraphicsAPI* pGraphics = g_GraphicsAPI().instancePtr();

    IDXGISwapChain* pSwapChain = reinterpret_cast<IDXGISwapChain*>(pGraphics->m_SwapChain.getObject());
    ID3D11DeviceContext* pContext = reinterpret_cast<ID3D11DeviceContext*>(pGraphics->m_DeviceContext.getObject());
    ID3D11RenderTargetView* pRTV = reinterpret_cast<ID3D11RenderTargetView*>(pGraphics->m_pRenderTargetView.getObject());

    float MyColor[4] = { 0,1,0,1 };
    pContext->ClearRenderTargetView(pRTV, MyColor);
    pSwapChain->Present(0, 0);
    
  }

  void OECustomAplication::OnDestroy()
  {
  }
}