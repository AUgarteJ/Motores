#pragma once

#include <oePlatformDefines_Core.h>

namespace oeEngineSDK
{
  class OE_CORE_EXPORT CApplicationBase
  {
  public:
    CApplicationBase();
    virtual ~CApplicationBase();

    //functions
  public:
    int run();
    
    virtual void OnInitialize() = 0;
    virtual void OnUpdate() = 0;
    virtual void OnRender() = 0;
    virtual void OnDestroy() = 0;
   
    void* getScreenHandle() { return m_screenHandle; }
  
  
     /* Variables*/
  protected:
    int m_iScrWidth;
    int m_iScrHeight;
  

    String m_szTitle; // The title bar text

  protected:
    void* m_screenHandle;


  };


}
