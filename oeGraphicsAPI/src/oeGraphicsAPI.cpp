#include "oeGraphicsAPI.h"

namespace oeEngineSDK{
  oeGraphicsAPI::~oeGraphicsAPI()
  {
    m_pRenderTargetView.destroy();
    m_SwapChain.destroy();
    m_DeviceContext.destroy();
    m_Device.destroy();
  }

  int32 oeGraphicsAPI::Initialize(void* pScreenHandle, bool fullscreen, uint32 bbufferCount)
  {
    HRESULT hr = S_OK;
    D3D_DRIVER_TYPE driverType = D3D_DRIVER_TYPE_NULL;
    D3D_FEATURE_LEVEL featureLevel = D3D_FEATURE_LEVEL_11_0;

    if (pScreenHandle == nullptr)
      return 0;

    HWND hwnd = reinterpret_cast<HWND>(pScreenHandle);

    RECT rc;
    GetClientRect(hwnd, &rc);
    UINT width = rc.right - rc.left;
    UINT height = rc.bottom - rc.top;

    UINT createDeviceFlags = 0;
#if OE_DEBUG_MODE
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
    sd.BufferCount = bbufferCount;
    sd.BufferDesc.Width = width;
    sd.BufferDesc.Height = height;
    sd.BufferDesc.Format = DXGI_FORMAT_R8G8B8A8_UNORM;
    sd.BufferDesc.RefreshRate.Numerator = 60;
    sd.BufferDesc.RefreshRate.Denominator = 1;
    sd.BufferUsage = DXGI_USAGE_RENDER_TARGET_OUTPUT;
    sd.OutputWindow = hwnd;
    sd.SampleDesc.Count = 1;
    sd.SampleDesc.Quality = 0;
    sd.Windowed = static_cast<BOOL>(!fullscreen);

    ID3D11Device** pRefDevice = reinterpret_cast<ID3D11Device**>(m_Device.getReference());
    ID3D11DeviceContext** pRefDeviceContext = reinterpret_cast<ID3D11DeviceContext**>(m_DeviceContext.getReference());
    IDXGISwapChain** pRefSwapChain = reinterpret_cast<IDXGISwapChain**>(m_SwapChain.getReference());

    for (UINT driverTypeIndex = 0; driverTypeIndex < numDriverTypes; driverTypeIndex++)
    {
      driverType = driverTypes[driverTypeIndex];
      hr = D3D11CreateDeviceAndSwapChain(NULL, driverType, NULL, createDeviceFlags, featureLevels, numFeatureLevels,
        D3D11_SDK_VERSION, &sd, pRefSwapChain, pRefDevice, &featureLevel, pRefDeviceContext);
      if (SUCCEEDED(hr))
        break;
    }
    if (FAILED(hr))
      return hr;

    ID3D11Device* pDevice = *pRefDevice;
    ID3D11DeviceContext* pDeviceContext = *pRefDeviceContext;
    IDXGISwapChain* pSwapChain = *pRefSwapChain;

    // Create a render target view
    ID3D11Texture2D* pBackBuffer = NULL;
    hr = pSwapChain->GetBuffer(0, __uuidof(ID3D11Texture2D), (LPVOID*)&pBackBuffer);
    if (FAILED(hr))
      return hr;

    ID3D11RenderTargetView** pRefRenderTargetView = reinterpret_cast<ID3D11RenderTargetView**>(m_pRenderTargetView.getReference());

    hr = pDevice->CreateRenderTargetView(pBackBuffer, NULL, pRefRenderTargetView);
    pBackBuffer->Release();
    if (FAILED(hr))
      return hr;

    return int32();
  }

  oeGraphicsAPI& g_GraphicsAPI()
  {
    return oeGraphicsAPI::instance();
  }
}