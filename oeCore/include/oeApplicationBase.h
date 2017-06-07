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

    int getScreenHandle() { return m_screenHandle; }
  
  
     /* Variables*/
  protected:
    int m_iScrWidth;
    int m_iScrHeight;
  

    String m_szTitle; // The title bar text

  protected:
    int m_screenHandle;


  };


}
