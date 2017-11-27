#pragma once

#include <oeApplicationBase.h>
#include <oeModel.h>
#include <oeInputLayout.h>
#include <oePixelShader.h>
#include <oeVertexShader.h>
#include <oeBuffer.h>

namespace oeEngineSDK {
  class OE_CORE_EXPORT OECustomAplication : public CApplicationBase
  {
  public:
    OECustomAplication();
    ~OECustomAplication();

    virtual void OnInitialize() override;
    virtual void OnUpdate() override;
    virtual void OnRender() override;
    virtual void OnDestroy() override;

    CModel m_myModel;
    oeInputLayout m_inputLayout;
    CVertexShader m_vertexShader;
    CPixelShader m_pixelShader;
  };
}