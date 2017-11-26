#include <gtest/gtest.h>

#include <oeApplicationBase.h>

#include <oePrerequisites_Utilities.h>

#include <assimp/Importer.hpp>      // C++ importer interface
#include <assimp/scene.h>           // Output data structure
#include <assimp/postprocess.h>     // Post processing flags

#define WIN32_LEAN_AND_MEAN
#include <windows.h>

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

using namespace oeEngineSDK;

void
loadModel(const String& fileName){
  //Create an instance of the Importer class
  Assimp::Importer importer;
  
  const aiScene* scene = importer.ReadFile(fileName,
    aiProcess_CalcTangentSpace |
    aiProcess_Triangulate |
    aiProcess_JoinIdenticalVertices |
    aiProcess_SortByPType);

  // If the import failed, report it
  if (!scene)
  {
    String error(importer.GetErrorString());
    return;
  }

  std::vector<float> listaVertices;
  if (scene->HasMeshes())
  {
    for (int i = 0; i < scene->mNumMeshes; ++i)
    {
      aiMesh* pMesh = scene->mMeshes[i];

      listaVertices.resize(pMesh->mNumVertices * 3);
      for (int j=0; j < pMesh->mNumVertices; ++j)
      {
        if (pMesh->HasPositions())
        {
          listaVertices[j * 3 + 0] = pMesh->mVertices[j].x;
          listaVertices[j * 3 + 1] = pMesh->mVertices[j].y;
          listaVertices[j * 3 + 2] = pMesh->mVertices[j].z;
        }
        if (pMesh->HasNormals())
        {

        }
        if (pMesh->GetNumUVChannels())
        {
          if (pMesh->HasTextureCoords(0))
          {
            //u = pMesh->mTextureCoords[0][j].x;
            //v = pMesh->mTextureCoords[0][j].y;
          }
        }
      }
      
      if (pMesh->HasFaces())
      {
        std::vector<uint32> indicesArray;
        for (int k=0; k<pMesh->mNumFaces; ++k)
        {
          aiFace& face = pMesh->mFaces[k];
          for (int kk = 0; kk < face.mNumIndices; ++kk)
          {
            indicesArray.push_back(face.mIndices[kk]);
          }
        }
      }

      int kkk = 0;
    }
  }
}

int
main(int/* argc*/, char /**argv[]*/){

  loadModel("Resources/Models/Hebe.3ds");

  return g_App.run();
}


