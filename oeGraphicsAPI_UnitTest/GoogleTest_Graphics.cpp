#include <gtest/gtest.h>
#include <oeVertexShader.h>
#include <oeBuffer.h>
#include "oeVector4.h"

#include <oePrerequisites_Graphics.h>
#include <vector>

using namespace oeEngineSDK;
 

TEST(Graphics, VertexBuffer)
{
  CVertexBuffer<Vector4> m_vertexBuffer;

 //m_vertexBuffer.Add(1);
 //m_vertexBuffer.Add(1);
 //m_vertexBuffer.Add(1);

 std::vector<Vector4> vectorVertex;

 Vector4 myVector4;

 vectorVertex.push_back(myVector4);
 vectorVertex.push_back(myVector4);

 m_vertexBuffer.Add(vectorVertex);

 EXPECT_TRUE(m_vertexBuffer.getVertexCount() == 2);

 m_vertexBuffer.Add(1);

 EXPECT_TRUE(m_vertexBuffer.getVertexCount() == 3);

 m_vertexBuffer.Add(myVector4);

 EXPECT_TRUE(m_vertexBuffer.getVertexCount() == 4);



}

TEST(Graphics, IndexBuffer)
{


  oeIndexBuffer<uint32> m_indexBuffer;
  std::vector<uint32> vectorIndex;
  uint32 Array[2];

  m_indexBuffer.Add(2);

  EXPECT_TRUE(m_indexBuffer.getIndexCount() == 1);

  m_indexBuffer.Add(vectorIndex);

  EXPECT_TRUE(m_indexBuffer.getIndexCount() == 1);

  m_indexBuffer.Add(Array, 3);

  EXPECT_TRUE(m_indexBuffer.getIndexCount() == 4);

}
