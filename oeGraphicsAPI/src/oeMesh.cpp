#include "oeMesh.h"
namespace oeEngineSDK
{
  CMesh::CMesh()
  {
  
  }

  CMesh:: ~CMesh()
  {
   
  }

  void CMesh::render(const CDeviceContext& DeviceContext)
  {
    m_indexBuffer.SetHardwareBuffer(0);
    m_vetexBuffer.SetHardwareBuffer(0);
    ID3D11DeviceContext* pDevideContext = reinterpret_cast<ID3D11DeviceContext*>(DeviceContext.getObject());
    pDevideContext->DrawIndexed(m_indexBuffer.getIndexCount(), 0, 0);
  }
}



