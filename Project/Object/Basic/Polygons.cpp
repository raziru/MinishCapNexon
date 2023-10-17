#include "Framework.h"
#include "Polygons.h"


Polygons::Polygons(float radius, UINT sectorCount, Vector4 color)
{
   
    //Vertex Buffer
    for (UINT i = 0; i < sectorCount; i++)
    {
        float angle = XM_2PI / sectorCount * i;

        Vector3 pos = {
            radius * cosf(angle),
            radius * sinf(angle),
            0.0f
        };

        vertices.push_back(VertexColor( pos,color ));

    }
    vertices.push_back(VertexColor({ 0.0f,0.0f,0.0f }, color));

    for (UINT i = 0; i < sectorCount - 2 ; i++)
    {
        indices.push_back(0);
        indices.push_back(i + 2);
        indices.push_back(i + 1);

    }


    vertexBuffer = new VertexBuffer(vertices);
    indexBuffer  = new  IndexBuffer(indices);

    vertexShader = new VertexShader(L"VertexTutorial");
    pixelShader  = new  PixelShader(L"PixelTutorial");

    worldBuffer = new MatrixBuffer();

}

Polygons::~Polygons()
{
    delete vertexShader;
    delete vertexBuffer;
    delete  pixelShader;
    delete  indexBuffer;
    delete  worldBuffer;
}

void Polygons::Render()
{

    vertexBuffer->SetBuffer();
     indexBuffer->SetBuffer();
    vertexShader->SetShader();
     pixelShader->SetShader();

     worldBuffer->SetData(world);
     worldBuffer->VSSetBuffer(0);
    //Render - draw함수로 파이프라인을 작동시킨다.
    //DC->Draw(vertices.size(), 0);
    DC->DrawIndexed(indices.size(), 0, 0);
    ////////////////////////////////////////////
}
