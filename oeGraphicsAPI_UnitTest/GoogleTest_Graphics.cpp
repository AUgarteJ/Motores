#include <gtest/gtest.h>
#include <oeVertexShader.h>
#include <oeBuffer.h>
#include "oeVector4.h"
#include <oeModel.h>
#include <oePrerequisites_Graphics.h>
#include <vector>

using namespace oeEngineSDK;
 

TEST(Graphics, VertexBuffer)
{
  CVertexBuffer<Vector4> m_vertexBuffer;

//ADD
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
 //Remove
 m_vertexBuffer.Remove(0);
 EXPECT_TRUE(m_vertexBuffer.getVertexCount() ==3);

 m_vertexBuffer.Remove(1,2);
 EXPECT_TRUE(m_vertexBuffer.getVertexCount() == 1);

 //Clear
 m_vertexBuffer.Clear();
 EXPECT_TRUE(m_vertexBuffer.getVertexCount() == 0);

// Create HNardware Buffer
 m_vertexBuffer.Add(myVector4);
 m_vertexBuffer.CreateHardwareBuffer(0x00);
 EXPECT_TRUE(m_vertexBuffer.m_BufferData->isBufferInitialized());
 
 // Set Hardware Buffer

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

  //Remove
  m_indexBuffer.Remove(0);
  EXPECT_TRUE(m_indexBuffer.getIndexCount() == 3);

  m_indexBuffer.Remove(1, 2);
  EXPECT_TRUE(m_indexBuffer.getIndexCount() == 1);

  //Clear

  m_indexBuffer.Clear();
  EXPECT_TRUE(m_indexBuffer.getIndexCount() == 0);


}

TEST(Graphics, loadModel)
{
  CModel m_myModel;
  m_myModel.loadModel("Resources/Models/Cube.3ds");
  EXPECT_EQ(m_myModel.m_MeshList.size(), 1);
  EXPECT_EQ(m_myModel.m_MeshList[0]->m_vetexBuffer.getVertexCount(), 8);

}

TEST(Graphics, Mesh_Index)
{
  CMesh m_myMesh;
  oeIndexBuffer<uint32> m_indexBuffer;
  std::vector<uint32> vectorIndex;
  uint32 Array[2];

  m_myMesh.m_indexBuffer.Add(2);

  EXPECT_TRUE(m_myMesh.m_indexBuffer.getIndexCount() == 1);

  m_myMesh.m_indexBuffer.Add(vectorIndex);

  EXPECT_TRUE(m_myMesh.m_indexBuffer.getIndexCount() == 1);

  m_myMesh.m_indexBuffer.Add(Array, 3);

  EXPECT_TRUE(m_myMesh.m_indexBuffer.getIndexCount() == 4);
}

TEST(Graphics, Mesh_Vertex)
{
  CMesh m_myMesh;
  CVertexBuffer<Vector4> m_vertexBuffer;

  //ADD
  std::vector<Vector4> vectorVertex;

  Vector4 myVector4;

  vectorVertex.push_back(myVector4);
  vectorVertex.push_back(myVector4);

  m_myMesh.m_vetexBuffer.Add(vectorVertex);

  EXPECT_TRUE(m_myMesh.m_vetexBuffer.getVertexCount() == 2);

  m_myMesh.m_vetexBuffer.Add(1);

  EXPECT_TRUE(m_myMesh.m_vetexBuffer.getVertexCount() == 3);

  m_myMesh.m_vetexBuffer.Add(myVector4);

  EXPECT_TRUE(m_myMesh.m_vetexBuffer.getVertexCount() == 4);
}

TEST(Graphics, ConstantBuffer)
{
 
}