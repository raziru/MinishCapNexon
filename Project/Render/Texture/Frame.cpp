#include "Framework.h"
#include "Frame.h"


Frame::Frame(wstring file, Vector2 uvStart, Vector2 uvEnd)
{
	texture = Texture::GetTexture(file);

	Vector2 pos = Vector2();

    size =
    {
        texture->GetSize().x * (uvEnd.x - uvStart.x),
        texture->GetSize().y * (uvEnd.y - uvStart.y),

    };

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

        //BackFace Culling: �޸��� �׸��� �ʴ´�-�ð�������� �׸��� ȭ��������� �ո��̰� �ݽð�� �׷����� ȭ������� �޸��̴�.

        //Polygon: �ٰ���, directx�� �ﰢ���� �̾�ٿ��� ������ �����.
    };

    indices = {
        0, 1, 2,
        2, 1, 3,
    };


    vertexBuffer = new VertexBuffer(vertices);
     indexBuffer = new  IndexBuffer(indices);
}

Frame::Frame(wstring file, UINT startX, UINT startY, UINT width, UINT height)
{
    texture = Texture::GetTexture(file);

	Vector2 pos = Vector2();

    Vector2 uvStart = Vector2( startX          / texture->GetSize().x,  startY           / texture->GetSize().y);
    Vector2 uvEnd   = Vector2((startX + width) / texture->GetSize().x, (startY + height) / texture->GetSize().y);

    size =
    {
        texture->GetSize().x * (uvEnd.x - uvStart.x),
        texture->GetSize().y * (uvEnd.y - uvStart.y),

    };

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

        //BackFace Culling: �޸��� �׸��� �ʴ´�-�ð�������� �׸��� ȭ��������� �ո��̰� �ݽð�� �׷����� ȭ������� �޸��̴�.

        //Polygon: �ٰ���, directx�� �ﰢ���� �̾�ٿ��� ������ �����.
    };

    indices = {
        0, 1, 2,
        2, 1, 3,
    };


    vertexBuffer = new VertexBuffer(vertices);
     indexBuffer = new  IndexBuffer(indices);
}

Frame::~Frame()
{
    delete vertexBuffer;
    delete  indexBuffer;
}

void Frame::Render()
{
    vertexBuffer->SetBuffer();
     indexBuffer->SetBuffer();


    texture->SetPS();

    DC->DrawIndexed(indices.size(), 0, 0);
}
