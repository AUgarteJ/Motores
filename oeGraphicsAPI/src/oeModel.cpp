#include "oeModel.h"
namespace oeEngineSDK
{
  CModel::CModel()
  {

  }
  
  CModel::~CModel()
  {

  }

  void CModel::loadModel(const String& fileName)
  {

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

    ///////
    CMesh* tempMesh = nullptr;
    Vector4 pTempVector;

    if (scene->HasMeshes())
    {
      for (int i = 0; i < scene->mNumMeshes; ++i)
      {
        tempMesh = new CMesh();
        m_MeshList.push_back(tempMesh);
        aiMesh* pMesh = scene->mMeshes[i];

        ////////////////////////////////////////////////////////////////////
        for (int j = 0; j < pMesh->mNumVertices; ++j)
        {
          if (pMesh->HasPositions())
          {
            pTempVector.x = pMesh->mVertices[j].x;
            pTempVector.y = pMesh->mVertices[j].y;
            pTempVector.z = pMesh->mVertices[j].z;
            pTempVector.w = 1.0f;

            m_MeshList[i]->m_vetexBuffer.Add(pTempVector);
          }
        }

        if (pMesh->HasFaces())
        {
          for (int k = 0; k < pMesh->mNumFaces; ++k)
          {
            aiFace& face = pMesh->mFaces[k];
            for (int kk = 0; kk < face.mNumIndices; ++kk)
            {
              m_MeshList[i]->m_indexBuffer.Add(face.mIndices[kk]);
            }
          }
        }
        
        m_MeshList[i]->m_vetexBuffer.CreateHardwareBuffer(0x00);
        m_MeshList[i]->m_indexBuffer.CreateHardwareBuffer(0x00);
      } 
    }
  }

  void CModel::render(const CDeviceContext& DeviceContext)
  {
    //Dibuja modelo en pantalla
    for (auto mesh : m_MeshList) {
      mesh->render(DeviceContext);
    }
  }
}
  
