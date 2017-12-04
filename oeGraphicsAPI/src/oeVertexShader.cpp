#include "oeVertexShader.h"
#include "oeDevice.h"

#include <d3d11.h>

namespace oeEngineSDK
{

  void CVertexShader::Create(CDevice* pDevice, String fileName, String entryPoint)
  {
    Compile(fileName, entryPoint, "vs_5_0");

    //Create the vertex shader
    pDevice->m_Device->CreateVertexShader( m_pBlob->GetBufferPointer(),
                                                        m_pBlob->GetBufferSize(),
                                                        NULL,
                                                        &m_pIVertexShader);
  }

  void CVertexShader::SetShader(CDeviceContext* DeviceContext)
  {
    ID3D11DeviceContext* PDeviceContext = reinterpret_cast<ID3D11DeviceContext*>(DeviceContext->getObject());
    PDeviceContext->VSSetShader(m_pIVertexShader, NULL, 0);
  }
}