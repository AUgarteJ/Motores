#include "oeAplicationCustom.h"

#include <DirectXMath.h>

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
   
    //depht stencil

    m_DSV.CreateDSV(m_iScrWidth, m_iScrHeight);
  }

  void OECustomAplication::OnUpdate()
  {
  }

  using namespace DirectX;

  void OECustomAplication::OnRender()
  {
    oeGraphicsAPI* pGraphics = g_GraphicsAPI().instancePtr();

    IDXGISwapChain* pSwapChain = reinterpret_cast<IDXGISwapChain*>(pGraphics->m_SwapChain.getObject());

    //Limpiar back buffer
    float MyColor[4] = { 1, 1, 0, 1 };
    pGraphics->m_DeviceContext.clearRenderTarget(pGraphics->m_pRenderTargetView, MyColor);

    //Limpiar Depth Buffer
    pGraphics->m_DeviceContext.clearDepthStencilView(m_DSV, D3D11_CLEAR_DEPTH, 1.0f, 0);
    
    m_inputLayout.SetHardwareLayout(&pGraphics->m_DeviceContext);
    pGraphics->m_DeviceContext.setTopology();
    
    int iCBSize = sizeof(Matrix4) * 3;

    m_ConstantBuffer.CreateCB(iCBSize);

    //Inicializar las matriz de mundo con la identidad

    m_MatWorld.m_Elements.m00 = 1;
    m_MatWorld.m_Elements.m11 = 1;
    m_MatWorld.m_Elements.m22 = 1;
    m_MatWorld.m_Elements.m33 = 1;

    XMVECTOR xEye = XMVectorSet(0.0, 0.0, -36.0, 1.0);
    XMVECTOR xAt = XMVectorSet(0, 0, 0, 1);
    XMVECTOR xUp = XMVectorSet(0, 1, 0, 0);

    XMMATRIX xmatWorld = XMMatrixIdentity();
    XMMATRIX xmatView = XMMatrixLookAtLH(xEye, xAt, xUp);
    XMMATRIX xmatProj = XMMatrixPerspectiveFovLH(CMath::PI / 4.0f, (float)m_iScrWidth / (float)m_iScrHeight, 0.01f, 1000.0f);

    xmatWorld = XMMatrixTranspose(xmatWorld);
    xmatView = XMMatrixTranspose(xmatView);
    xmatProj = XMMatrixTranspose(xmatProj);

    //Inicializar la matriz de vista
    Vector4 Eye(0.0, 3.0, -56.0, 1.0);
    Vector4 At(0, 0, 0, 0);
    Vector4 Up(0, 1 ,0, 0);

    m_MatxView = m_MatxView.lookAtLH(Eye, At, Up);
    
    //Inicializar la mtriz de projeccion
    m_MatProjection = m_MatProjection.projectionFovLH(0.785398163f, (float)m_iScrWidth / (float)m_iScrHeight, 0.01f, 100.0f);

    XMMATRIX xmtxArray[3];
    xmtxArray[0] = xmatWorld;
    xmtxArray[1] = xmatView;
    xmtxArray[2] = xmatProj;

    Matrix4 mtxArray[3];
    mtxArray[0] = m_MatWorld;
    mtxArray[1] = m_MatxView;
    mtxArray[2] = m_MatProjection;

    m_ConstantBuffer.Update(xmtxArray, iCBSize);

    m_inputLayout.SetHardwareLayout(&pGraphics->m_DeviceContext);
    m_vertexShader.SetShader(&pGraphics->m_DeviceContext);
    m_pixelShader.SetShader(&pGraphics->m_DeviceContext);

    m_ConstantBuffer.SetVS();
    m_ConstantBuffer.SetPS();

    m_myModel.render(pGraphics->m_DeviceContext);

    //Sacar imagen a pantalla
    pSwapChain->Present(0, 0);
  }

  void OECustomAplication::OnDestroy()
  {
  }
}