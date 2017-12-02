#pragma once


#include <oeApplicationBase.h>
#include <oeModel.h>
#include <oeInputLayout.h>
#include <oePixelShader.h>
#include <oeVertexShader.h>
#include <oeBuffer.h>
#include <oeMatrix4D.h>




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
    Matrix4 m_MatxView;
    Matrix4 m_MatProjection;
    Matrix4 m_MatWorld;
    CConstantBuffer m_ConstantBuffer;
    
  };
}