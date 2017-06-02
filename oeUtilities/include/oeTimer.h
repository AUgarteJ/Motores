#pragma once

namespace oeEngineSDK
{
  class oeTimer
  {
  public:
    oeTimer();
    ~oeTimer();

    /*Reset the timer to zero. */
    void reset();
    
    /*Return time in milliseconds since timer was initialized or last reset.*/
    unsigned long getMilliseconds();

    /*Return time in microseconds since timer was initialized or last reset.*/
    unsigned long getMicroseconds();

    /**
    *Return time in milliseconds since timer was initialized  
    *Only CPU timer measured
    **/

    unsigned long getMilllisecondsCPU();

    /**
    *Return time in microseconds since timer was initialized
    *Only CPU timer measured
    **/

    unsigned long getMicrosecondsCPU();
    /**
    Returns the time at which time the timer was initialized, in milliseconds
    @Return time in milliseconds
    **/
  private:
    struct Data;
    Data* m_pData;
  };

}
