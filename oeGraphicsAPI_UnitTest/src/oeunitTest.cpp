//--------------------------------------------------------------------------------------
// File: Tutorial01.cpp
//
// This application demonstrates creating a Direct3D 11 device
//
// Copyright (c) Microsoft Corporation. All rights reserved.
//--------------------------------------------------------------------------------------
#include <windows.h>
#include <d3d11.h>
//#include <d3dx11.h>
#include <oeApplicationBase.h>
#include <oeVector4.h>
#include <oeDevice.h>
#include <oeDeviceContext.h>

//#include <D3Dcompiler.h>
//#include <d3dcompile.h>
#include <d3dcompiler.h>

using namespace  oeEngineSDK;
CApplicationBase App;

//--------------------------------------------------------------------------------------
// Global Variables
//--------------------------------------------------------------------------------------
HINSTANCE               g_hInst = NULL;
HWND                    g_hWnd = NULL;
D3D_DRIVER_TYPE         g_driverType = D3D_DRIVER_TYPE_NULL;
D3D_FEATURE_LEVEL       g_featureLevel = D3D_FEATURE_LEVEL_11_0;
CDevice                 m_Device;
CDeviceContext          m_DeviceContext;
IDXGISwapChain*         g_pSwapChain = NULL;
ID3D11RenderTargetView* g_pRenderTargetView = NULL;


//--------------------------------------------------------------------------------------
// Forward declarations
//--------------------------------------------------------------------------------------
HRESULT InitWindow(HINSTANCE hInstance, int nCmdShow);
HRESULT InitDevice();
void CleanupDevice();
LRESULT CALLBACK    WndProc(HWND, UINT, WPARAM, LPARAM);
void Render();


//--------------------------------------------------------------------------------------
// Entry point to the program. Initializes everything and goes into a message processing 
// loop. Idle time is used to render the scene.
//--------------------------------------------------------------------------------------
int WINAPI wWinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, LPWSTR lpCmdLine, int nCmdShow)
{
  UNREFERENCED_PARAMETER(hPrevInstance);
  UNREFERENCED_PARAMETER(lpCmdLine);

  if (FAILED(InitWindow(hInstance, nCmdShow)))
    return 0;

  if (FAILED(InitDevice()))
  {
    CleanupDevice();
    return 0;
  }

  // Main message loop
  MSG msg = { 0 };
  while (WM_QUIT != msg.message)
  {

    if (PeekMessage(&msg, NULL, 0, 0, PM_REMOVE))
    {
      TranslateMessage(&msg);
      DispatchMessage(&msg);
    }
    else
    {
      Render();

    }
  }

  CleanupDevice();

  return (int)msg.wParam;
}


//--------------------------------------------------------------------------------------
// Register class and create window
//--------------------------------------------------------------------------------------
HRESULT InitWindow(HINSTANCE hInstance, int nCmdShow)
{
  // Register class
  WNDCLASSEX wcex;
  wcex.cbSize = sizeof(WNDCLASSEX);
  wcex.style = CS_HREDRAW | CS_VREDRAW;
  wcex.lpfnWndProc = WndProc;
  wcex.cbClsExtra = 0;
  wcex.cbWndExtra = 0;
  wcex.hInstance = hInstance;
  wcex.hIcon = LoadIcon(hInstance, NULL);
  wcex.hCursor = LoadCursor(NULL, IDC_ARROW);
  wcex.hbrBackground = (HBRUSH)(COLOR_WINDOW + 1);
  wcex.lpszMenuName = NULL;
  wcex.lpszClassName = "TutorialWindowClass";
  wcex.hIconSm = LoadIcon(wcex.hInstance, NULL);
  if (!RegisterClassEx(&wcex))
    return E_FAIL;

  // Create window
  g_hInst = hInstance;
  RECT rc = { 0, 0, 640, 480 };
  AdjustWindowRect(&rc, WS_OVERLAPPEDWINDOW, FALSE);
  g_hWnd = CreateWindow("TutorialWindowClass", "Direct3D 11 Tutorial 1: Direct3D 11 Basics", WS_OVERLAPPEDWINDOW,
    CW_USEDEFAULT, CW_USEDEFAULT, rc.right - rc.left, rc.bottom - rc.top, NULL, NULL, hInstance,
    NULL);
  if (!g_hWnd)
    return E_FAIL;

  ShowWindow(g_hWnd, nCmdShow);

  return S_OK;
}


//--------------------------------------------------------------------------------------
// Called every time the application receives a message
//--------------------------------------------------------------------------------------
LRESULT CALLBACK WndProc(HWND hWnd, UINT message, WPARAM wParam, LPARAM lParam)
{
  PAINTSTRUCT ps;
  HDC hdc;

  switch (message)
  {
  case WM_PAINT:
    hdc = BeginPaint(hWnd, &ps);
    EndPaint(hWnd, &ps);

    break;

  case WM_DESTROY:
    PostQuitMessage(0);
    break;

  default:
    return DefWindowProc(hWnd, message, wParam, lParam);
  }

  return 0;
}


//--------------------------------------------------------------------------------------
// Create Direct3D device and swap chain
//--------------------------------------------------------------------------------------
HRESULT InitDevice()
{
  HRESULT hr = S_OK;

  RECT rc;
  GetClientRect(g_hWnd, &rc);
  UINT width = rc.right - rc.left;
  UINT height = rc.bottom - rc.top;

  UINT createDeviceFlags = 0;
#ifdef _DEBUG
  createDeviceFlags |= D3D11_CREATE_DEVICE_DEBUG;
#endif

  D3D_DRIVER_TYPE driverTypes[] =
  {
    D3D_DRIVER_TYPE_HARDWARE,
    D3D_DRIVER_TYPE_WARP,
    D3D_DRIVER_TYPE_REFERENCE,
  };
  UINT numDriverTypes = ARRAYSIZE(driverTypes);

  D3D_FEATURE_LEVEL featureLevels[] =
  {
    D3D_FEATURE_LEVEL_11_0,
    D3D_FEATURE_LEVEL_10_1,
    D3D_FEATURE_LEVEL_10_0,
  };
  UINT numFeatureLevels = ARRAYSIZE(featureLevels);

  DXGI_SWAP_CHAIN_DESC sd;
  ZeroMemory(&sd, sizeof(sd));
  sd.BufferCount = 1;
  sd.BufferDesc.Width = width;
  sd.BufferDesc.Height = height;
  sd.BufferDesc.Format = DXGI_FORMAT_R8G8B8A8_UNORM;
  sd.BufferDesc.RefreshRate.Numerator = 60;
  sd.BufferDesc.RefreshRate.Denominator = 1;
  sd.BufferUsage = DXGI_USAGE_RENDER_TARGET_OUTPUT;
  sd.OutputWindow = g_hWnd;
  sd.SampleDesc.Count = 1;
  sd.SampleDesc.Quality = 0;
  sd.Windowed = TRUE;
  
  ID3D11Device** p_Device = reinterpret_cast<ID3D11Device**>(m_Device.GetReference());
  ID3D11DeviceContext** p_DeviceContext = reinterpret_cast<ID3D11DeviceContext**>
    (m_DeviceContext.GetReference());
  for (UINT driverTypeIndex = 0; driverTypeIndex < numDriverTypes; driverTypeIndex++)
  {
    g_driverType = driverTypes[driverTypeIndex];
    hr = D3D11CreateDeviceAndSwapChain(NULL, g_driverType, NULL, createDeviceFlags, featureLevels, numFeatureLevels,
      D3D11_SDK_VERSION, &sd, &g_pSwapChain, p_Device, &g_featureLevel, p_DeviceContext);
    if (SUCCEEDED(hr))
      break;
  }
  if (FAILED(hr))
    return hr;

  // Create a render target view
  ID3D11Texture2D* pBackBuffer = NULL;
  hr = g_pSwapChain->GetBuffer(0, __uuidof(ID3D11Texture2D), (LPVOID*)&pBackBuffer);
  if (FAILED(hr))
    return hr;

  hr = (*p_Device)->CreateRenderTargetView(pBackBuffer, NULL, &g_pRenderTargetView);
  pBackBuffer->Release();
  if (FAILED(hr))
    return hr;

  (*p_DeviceContext)->OMSetRenderTargets(1, &g_pRenderTargetView, NULL);

  // Setup the viewport
  D3D11_VIEWPORT vp;
  vp.Width = (FLOAT)width;
  vp.Height = (FLOAT)height;
  vp.MinDepth = 0.0f;
  vp.MaxDepth = 1.0f;
  vp.TopLeftX = 0;
  vp.TopLeftY = 0;
  (*p_DeviceContext)->RSSetViewports(1, &vp);

  return S_OK;
}


//--------------------------------------------------------------------------------------
// Render the frame
//--------------------------------------------------------------------------------------

void SetInfoToRender()
{
  ID3DBlob* MyShaderCompileInfoCode;

  ID3D11InputLayout* ILayOut;

  ID3D11Device** p_Device = reinterpret_cast<ID3D11Device**>
    (m_Device.GetReference());
  ID3D11DeviceContext** p_DeviceContext = reinterpret_cast<ID3D11DeviceContext**>
    (m_DeviceContext.GetReference());

  D3D11_INPUT_ELEMENT_DESC layout[] =
  {
    { "POSITION", 0, DXGI_FORMAT_R32G32B32_FLOAT, 0, 0, D3D11_INPUT_PER_VERTEX_DATA, 0 },
  };


  //To Do: compilar shader
  ID3DBlob* pErrorBlob;
  ID3DBlob* VertexShader;
  ID3D11VertexShader* VerShader;

  
    //if(FAILED(D3DCompileFromFile("Resourse/Shaders/ShaderTest.hlsl", NULL, D3D_COMPILE_STANDARD_FILE_INCLUDE, "VS_Main", "vs_5_0",
    //  D3DCOMPILE_DEBUG | D3DCOMPILE_ENABLE_STRICTNESS, 0, MyShaderCompileInfoCode, &pErrorBlob)))
    //{
    //  //Generar una cadena que muestre los errores obtenidos al compilar el shader
    //  OutputDebugString((char*)pErrorBlob->GetBufferPointer());
    //  std::string s = (char*)pErrorBlob->GetBufferPointer();
    //}

    (*p_Device)->CreateVertexShader(VertexShader->GetBufferPointer(), VertexShader->GetBufferSize(), NULL, &VerShader);

    (*p_DeviceContext)->VSSetShader(VerShader, NULL, 0);


  (*p_Device)->CreateInputLayout(layout, 0, MyShaderCompileInfoCode->GetBufferPointer(), MyShaderCompileInfoCode->GetBufferSize(), &ILayOut);


  ID3D11Buffer* pVertexB;
  ID3D11Buffer* pIndexB;

  //Create VertexBuffer

  struct Vertex
  {
    Vector4 m_Pos;

  };

  Vertex VerToRender[3]
  {
    Vector4(0.0f, 0.5f, 0.5f, 0.f),
    Vector4(0.5f, -0.5f,   0.5f, 0.f),
    Vector4(-0.5f, -0.5f,  0.5f, 0.f)
  };


  D3D11_BUFFER_DESC DesVerBuffer;
  DesVerBuffer.BindFlags = D3D11_BIND_VERTEX_BUFFER;
  DesVerBuffer.ByteWidth = sizeof(Vertex) * 3; //Tamaño quw tendrá el buffer  
  DesVerBuffer.CPUAccessFlags = 0;
  DesVerBuffer.MiscFlags = 0;
  DesVerBuffer.Usage = D3D11_USAGE_DEFAULT;

  D3D11_SUBRESOURCE_DATA InitData;
  ZeroMemory(&InitData, sizeof(InitData));
  InitData.pSysMem = VerToRender;

  (*p_Device)->CreateBuffer(&DesVerBuffer, &InitData, &pVertexB);


  //Reate Iex Buffer
  struct INDEX
  {
    float m_Pos;

  };

  INDEX IndexToRender[3]
  {
    float(1.0f),
    float(2.0f),
    float(3.0f)
  };

  /*
  D3D11_BUFFER_DESC DesIndBuffer;
  DesIndBuffer.BindFlags = D3D11_BIND_INDEX_BUFFER;
  DesIndBuffer.ByteWidth = sizeof(INDEX) * 3; //Tamaño quw tendrá el buffer
  DesIndBuffer.CPUAccessFlags = 0;
  DesIndBuffer.MiscFlags = 0;
  DesIndBuffer.Usage = D3D11_USAGE_DEFAULT;

  D3D11_SUBRESOURCE_DATA InitData;
  ZeroMemory(&InitData, sizeof(InitData));
  InitData.pSysMem = IndexToRender;

  (*pDevice)->CreateBuffer(&DesIndBuffer, &InitData, &pIndexB);

  */

  UINT  stride = sizeof(Vertex);

  (*p_DeviceContext)->IASetVertexBuffers(0, 1, &pVertexB, &stride, 0);

  
     
  (*p_DeviceContext)->IASetPrimitiveTopology(D3D11_PRIMITIVE_TOPOLOGY_TRIANGLELIST);

  (*p_DeviceContext)->IASetInputLayout(ILayOut);

}


void Render()
{
  

  ID3D11Device** p_Device = reinterpret_cast<ID3D11Device**>(m_Device.GetReference());
  ID3D11DeviceContext** p_DeviceContext = reinterpret_cast<ID3D11DeviceContext**>
    (m_DeviceContext.GetReference());
  // Just clear the backbuffer
  float ClearColor[4] = { 1.0f, 1.0f, 0.f, 0.0f }; //red,green,blue,alpha
  (*p_DeviceContext)->ClearRenderTargetView(g_pRenderTargetView, ClearColor);
  g_pSwapChain->Present(0, 0);

}


//--------------------------------------------------------------------------------------
// Clean up the objects we've created
//--------------------------------------------------------------------------------------
void CleanupDevice()
{
  ID3D11DeviceContext* p_DeviceContext = reinterpret_cast<ID3D11DeviceContext*>
    (m_DeviceContext.GetObject());


  if (p_DeviceContext) p_DeviceContext->ClearState();

  if (g_pRenderTargetView) g_pRenderTargetView->Release();
  if (g_pSwapChain) g_pSwapChain->Release();
  if (p_DeviceContext)p_DeviceContext->Release();
  m_Device.Destroy();
}
