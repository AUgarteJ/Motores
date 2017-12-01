#include <oeModel.h>
#include "oeAplicationCustom.h"

#include "gtest/gtest.h"



using namespace oeEngineSDK;

  int main(int argc, char **argv)
  {
    testing::InitGoogleTest(&argc, argv);
  
    OECustomAplication myApp;
    myApp.run();
    return RUN_ALL_TESTS();
   
  }
