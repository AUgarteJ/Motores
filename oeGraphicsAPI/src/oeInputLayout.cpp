#include "oeInputLayout.h"


oeEngineSDK::oeInputLayout::oeInputLayout()
{
  m_d3dInputLayout = nullptr;
}

oeEngineSDK::oeInputLayout::~oeInputLayout()
{
  //Hay que desalojar la memoria de los strings de la lista
  for (auto& element : m_Layout) {
    delete element.SemanticName;
  }
  m_Layout.clear();

  if (nullptr != m_d3dInputLayout)
  {
    m_d3dInputLayout->Release();
    m_d3dInputLayout = nullptr;
  }
}

void oeEngineSDK::oeInputLayout::addInputElement(
  String semanticName, 
  unsigned int sematicIndex,
  DXGI_FORMAT format, 
  unsigned int inputSlot,
  unsigned int alignedByteOffsset,
  D3D11_INPUT_CLASSIFICATION inputSlotClass, 
  unsigned int istanceDataStepRate)

{
  D3D11_INPUT_ELEMENT_DESC desc;

  char* nSmName = new char[semanticName.size() + 1];
  strcpy(nSmName, semanticName.c_str());
  nSmName[semanticName.size()] = 0;

  desc.SemanticName = nSmName;
  desc.SemanticIndex = sematicIndex;
  desc.Format = format;
  desc.InputSlot = inputSlot;
  desc.AlignedByteOffset = alignedByteOffsset;
  desc.InputSlotClass = inputSlotClass;
  desc.InstanceDataStepRate = istanceDataStepRate;

  m_Layout.push_back(desc);
}

bool oeEngineSDK::oeInputLayout::CreatHardwareLayout(CDevice* pDevice, CVertexShader* pVSBlob)
{
  if (nullptr == pDevice || 0 == m_Layout.size())
  {
    return false;
  }

  ID3D11Device* pd3dDevice = reinterpret_cast<ID3D11Device*>(pDevice->getObject());
  HRESULT hr = pd3dDevice->CreateInputLayout(&m_Layout[0],
    m_Layout.size(),
    pVSBlob->m_pBlob->GetBufferPointer(),
    pVSBlob->m_pBlob->GetBufferSize(),
    &m_d3dInputLayout);
  if (FAILED(hr))
  {
    return false;
  }

  return hr;
}


void oeEngineSDK::oeInputLayout::SetHardwareLayout(CDeviceContext * pDeviceContext)
{
  if (nullptr == m_d3dInputLayout)
  {
    return;
  }
  ID3D11DeviceContext* pd3deviceContext = reinterpret_cast<ID3D11DeviceContext*>
                                                  (pDeviceContext->getObject());
  pd3deviceContext->IASetInputLayout(m_d3dInputLayout);
}
