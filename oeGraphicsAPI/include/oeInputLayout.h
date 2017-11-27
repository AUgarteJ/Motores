#pragma once
#include <d3d11.h>
#include <vector>
#include "oePrerequisites_Graphics.h"
# include "oeDevice.h"
#include "oeVertexShader.h"
#include "oeDeviceContext.h"

using std::vector;
namespace oeEngineSDK
{
  class OE_GRAPHICS_API_EXPORT oeInputLayout
  {
  public:
    oeInputLayout();
    ~oeInputLayout();

    void addInputElement(String semanticName,
      unsigned int semanticIndex,
      DXGI_FORMAT format,
      unsigned int inputSlot,
      unsigned int alignedByteOffset,
      D3D11_INPUT_CLASSIFICATION inputSlotClass,
      unsigned int instanceDataStepRate);

    bool CreatHardwareLayout(CDevice* pDevice, CVertexShader* pVSBlob);
    void SetHardwareLayout(CDeviceContext*  pDeviceContext);

    vector<D3D11_INPUT_ELEMENT_DESC> m_Layout;
    ID3D11InputLayout* m_d3dInputLayout;
  };
}