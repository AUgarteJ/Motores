#pragma once
#include "oePrerequisites_Graphics.h"
#include "oeBuffer.h"
#include <oeVector4.h>

namespace oeEngineSDK
{

  class OE_GRAPHICS_API_EXPORT CMesh
  {
  public:
    oeIndexBuffer<unsigned int> m_indexBuffer;
    CVertexBuffer<Vector4> m_vetexBuffer;
    CMesh();
    ~CMesh();
  };
}