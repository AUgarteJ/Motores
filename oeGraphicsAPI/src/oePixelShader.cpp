#include "oePixelShader.h"
#include "oeDevice.h"

#include <d3d11.h>

namespace oeEngineSDK
{

  void CPixelShader::Create(CDevice* pDevice, String fileName, String entryPoint)
  {
    Compile(fileName, entryPoint, "ps_5_0");

    //Create the vertex shader
    HRESULT hr = pDevice->m_Device->CreatePixelShader(m_pBlob->GetBufferPointer(),
      m_pBlob->GetBufferSize(),
      NULL,
      &m_pIPixelShader);
  }

  void CPixelShader::SetShader(CDeviceContext* DeviceContext)
  {
    ID3D11DeviceContext* PDeviceContext = reinterpret_cast<ID3D11DeviceContext*>(DeviceContext->getObject());
    PDeviceContext->PSSetShader(m_pIPixelShader, NULL, 0);
  }
}