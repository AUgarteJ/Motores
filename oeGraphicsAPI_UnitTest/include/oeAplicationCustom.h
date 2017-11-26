#pragma once

#include <oeApplicationBase.h>
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
  };
}