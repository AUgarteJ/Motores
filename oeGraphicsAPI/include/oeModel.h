#pragma once
#include "oePrerequisites_Graphics.h"
#include "oeBuffer.h"
#include "oeDevice.h"
#include "oeDeviceContext.h"
#include "oeMesh.h"
#include <assimp/Importer.hpp>      // C++ importer interface
#include <assimp/scene.h>           // Output data structure
#include <assimp/postprocess.h>     // Post processing flags
namespace oeEngineSDK
{

  class OE_GRAPHICS_API_EXPORT CModel
  {
  public:
   
    std::vector<CMesh*> m_MeshList;
    CModel();
    ~CModel();
    void loadModel(const String& fileName);
  /*  void CreateVertexBuffer();
    void CreateIndexBuffer ();*/
  
    void render(const CDeviceContext& DeviceContext);
  };
}
