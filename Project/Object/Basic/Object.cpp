#include "Framework.h"
#include "Object.h"



Object::Object(Vector2 size)
{
    Vector3 pos  = {   0.0f,   0.0f, 0.0f };

    float L = pos.x - size.x * 0.5f;
    float R = pos.x + size.x * 0.5f;
    float B = pos.y - size.y * 0.5f;
    float T = pos.y + size.y * 0.5f;

    //Vertex Buffer
    vertices = {
        {Vector3(L,T,0.0f), Vector2(0.0f, 0.0f)},//LT
        {Vector3(R,T,0.0f), Vector2(1.0f, 0.0f)},//RT
        {Vector3(L,B,0.0f), Vector2(0.0f, 1.0f)},//LB
        {Vector3(R,B,0.0f), Vector2(1.0f, 1.0f)},//RB

        //BackFace Culling: 뒷면을 그리지 않는다-시계방향으로 그리면 화면방향으로 앞면이고 반시계로 그려지면 화면방향이 뒷면이다.

        //Polygon: 다각형, directx는 삼각형을 이어붙여서 도형을 만든다.
    };

    indices = {
        0, 1, 2,
        2, 1, 3,
    };


    vertexBuffer = new VertexBuffer(vertices);
    indexBuffer  = new  IndexBuffer(indices);

    vertexShader = new VertexShader(L"VertexTexture");
    pixelShader  = new  PixelShader(L"PixelTexture");


    worldBuffer = new MatrixBuffer();
    colorbuffer = new ColorBuffer();

    ////ViewPort
}

Object::Object(wstring file, Vector2 uvStart, Vector2 uvEnd)
{
    texture = Texture::GetTexture(file);

    XMFLOAT3 pos = { 0.0f,   0.0f, 0.0f };

    Vector2 size = texture->GetSize();


    float L = pos.x - size.x * 0.5f;
    float R = pos.x + size.x * 0.5f;
    float B = pos.y - size.y * 0.5f;
    float T = pos.y + size.y * 0.5f;

    //Vertex Buffer
    vertices = {
        {Vector3(L,T,0.0f), Vector2(uvStart.x, uvStart.y)},//LT
        {Vector3(R,T,0.0f), Vector2(  uvEnd.x, uvStart.y)},//RT
        {Vector3(L,B,0.0f), Vector2(uvStart.x,   uvEnd.y)},//LB
        {Vector3(R,B,0.0f), Vector2(  uvEnd.x,   uvEnd.y)},//RB

        //BackFace Culling: 뒷면을 그리지 않는다-시계방향으로 그리면 화면방향으로 앞면이고 반시계로 그려지면 화면방향이 뒷면이다.

        //Polygon: 다각형, directx는 삼각형을 이어붙여서 도형을 만든다.
    };

    indices = {
        0, 1, 2,
        2, 1, 3,
    };


    vertexBuffer = new VertexBuffer(vertices);
     indexBuffer = new  IndexBuffer(indices);

    vertexShader = new VertexShader(L"VertexTexture");
     pixelShader = new  PixelShader(L"PixelTexture");


    worldBuffer = new MatrixBuffer();
    colorbuffer = new ColorBuffer();

}



Object::~Object()
{
    delete vertexShader;
    delete vertexBuffer;
    delete  pixelShader;
    delete  indexBuffer;
    delete worldBuffer;
}

void Object::Render()
{
    vertexBuffer->SetBuffer();
     indexBuffer->SetBuffer();
    vertexShader->SetShader();
     pixelShader->SetShader();

     worldBuffer->SetData(world);
     worldBuffer->VSSetBuffer(0);
     colorbuffer->PSSetBuffer(0);
    if (texture)
    {
        texture->SetPS();
    }
    //Render - draw함수로 파이프라인을 작동시킨다.
    //DC->Draw(vertices.size(), 0);
    DC->DrawIndexed(indices.size(), 0, 0);
    ////////////////////////////////////////////
}
