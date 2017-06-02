#include "oeTimer.h"

#ifndef WIN32_LEAN_AND_MEAN
# define WIN32_LEAN_AND_MEAN
#endif
#if !defined(NOMINMAX)&& defined(_MSC_VER)
# define  NOMIMAX  //Required to stop windows.h messing up std::min
#endif
#include <windows.h>
#include <time.h>

namespace oeEngineSDK {

  struct oeTimer::Data
  {
    clock_t zeroClock;
    LARGE_INTEGER startTime;
    LARGE_INTEGER frequency;
   };

  oeTimer::oeTimer() {
    m_pData = new Data();
    reset();
  }
  oeTimer::~oeTimer() {
    delete m_pData;
  }
  void
    oeTimer::reset()
  {
    QueryPerformanceFrequency(&m_pData->frequency);
    QueryPerformanceCounter(&m_pData->startTime);
    m_pData->zeroClock = clock();
  }

  unsigned long
    oeTimer::getMilliseconds() {
    LARGE_INTEGER curTime;
    QueryPerformanceCounter(&curTime);
    
    LONGLONG newTime = curTime.QuadPart - m_pData->startTime.QuadPart;
    
    //scale by 1000 for millisecond
    unsigned long newTicks = static_cast <unsigned long>(1000 * newTime /
                                                         m_pData->frequency.QuadPart);
    return newTicks;
  }

  unsigned long 
    oeTimer::getMicroseconds() {
    LARGE_INTEGER curTime;
    QueryPerformanceCounter(&curTime);

    LONGLONG newTime = curTime.QuadPart - m_pData->startTime.QuadPart;

    //scale by 1000000 for millisecond
    unsigned long newMicro = static_cast <unsigned long>(1000000 * newTime /
                                                          m_pData->frequency.QuadPart);
    return newMicro;  
  }
  unsigned long
    oeTimer::getMilllisecondsCPU() {
    clock_t newClock = clock();
    return static_cast<unsigned long> (static_cast<float>(newClock - m_pData->zeroClock) /
                                      (static_cast<float>(CLOCKS_PER_SEC) / 1000.0F));
  }
  unsigned long
    oeTimer::getMicrosecondsCPU() {
    clock_t newClock = clock();
    return static_cast<unsigned long> (static_cast<float>(newClock - m_pData->zeroClock) /
                                      (static_cast<float>(CLOCKS_PER_SEC) / 1000000.0F));
  }
}