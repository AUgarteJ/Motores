#include <gtest/gtest.h>
#include <oeApplicationBase.h>
                                                                                              

//TEST(Game, Test1){
//  ASSERT_TRUE(1 == 1);
//}
namespace oeEngineSDK {
  class CGameAplication : public CApplicationBase
  {
  public:
    CGameAplication()
    {
      m_iScrHeight = 600;
      m_iScrWidth = 800;
      m_szTitle = "bentanon";
    }

  };
}

oeEngineSDK::CGameAplication g_App;

int
main(int/* argc*/, char /**argv[]*/){
  return g_App.run();
}


