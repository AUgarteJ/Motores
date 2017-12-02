#include "oeAplicationCustom.h"


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
    oeGraphicsAPI* pGraphics = g_GraphicsAPI().instancePtr();

    m_vertexShader.Create(&pGraphics->m_Device, "Resources/Shaders/ShaderTest.hlsl", "VS_Main");
    m_pixelShader.Create(&pGraphics->m_Device, "Resources/Shaders/ShaderTest.hlsl", "PS_Main");

    m_inputLayout.addInputElement("POSITION", 0, DXGI_FORMAT_R32G32B32A32_FLOAT, 0, 0, D3D11_INPUT_PER_VERTEX_DATA, 0);
    m_inputLayout.CreatHardwareLayout(&pGraphics->m_Device, &m_vertexShader);

    m_myModel.loadModel("Resources/Models/Cube.3ds");
  }

  void OECustomAplication::OnUpdate()
  {
  }

  void OECustomAplication::OnRender()
  {
    oeGraphicsAPI* pGraphics = g_GraphicsAPI().instancePtr();

    IDXGISwapChain* pSwapChain = reinterpret_cast<IDXGISwapChain*>(pGraphics->m_SwapChain.getObject());

    //Limpiar back buffer
    float MyColor[4] = { 0, 1, 0, 1 };
    pGraphics->m_DeviceContext.clearRenderTarget(pGraphics->m_pRenderTargetView, MyColor);
    m_inputLayout.SetHardwareLayout(&pGraphics->m_DeviceContext);
    pGraphics->m_DeviceContext.setTopology();
    
    int iCBSize = sizeof(Matrix4) * 3;

    m_ConstantBuffer.CreateCB(iCBSize);

    Matrix4 Array[3];
    Array[0].m_Elements.m00 = 1;
    Array[0].m_Elements.m11 = 1;
    Array[0].m_Elements.m22 = 1;
    Array[0].m_Elements.m33 = 1;

    Array[1].m_Elements.m00 = 1;
    Array[1].m_Elements.m11 = 1;
    Array[1].m_Elements.m22 = 1;
    Array[1].m_Elements.m33 = 1;

    Array[2].m_Elements.m00 = 1;
    Array[2].m_Elements.m11 = 1;
    Array[2].m_Elements.m22 = 1;
    Array[2].m_Elements.m33 = 1;

    m_ConstantBuffer.Update(Array, iCBSize);


    m_inputLayout.SetHardwareLayout(&pGraphics->m_DeviceContext);
    m_vertexShader.SetShader(&pGraphics->m_DeviceContext);
    m_pixelShader.SetShader(&pGraphics->m_DeviceContext);

    m_myModel.render(pGraphics->m_DeviceContext);

    //Sacar imagen a pantalla
    pSwapChain->Present(0, 0);
  }

  void OECustomAplication::OnDestroy()
  {
  }
}