#include "Framework.h"
#include "ColliderRect.h"


ColliderRect::ColliderRect(Vector2 size)
    :size(size)
{
    SetVertex();
}

ColliderRect::~ColliderRect()
{
}

void ColliderRect::SetVertex()
{
    Vector3 pos = { 0.0f, 0.0f, 0.0f };

    float L = pos.x - size.x * 0.5f;
    float R = pos.x + size.x * 0.5f;
    float B = pos.y - size.y * 0.5f;
    float T = pos.y + size.y * 0.5f;

    //Vertex Buffer
    vertices = {
        {Vector3(L,T,0.0f)},//LT
        {Vector3(R,T,0.0f)},//RT
        {Vector3(R,B,0.0f)},//RB
        {Vector3(L,B,0.0f)},//LB
        {Vector3(L,T,0.0f)},//LT

        //BackFace Culling: 뒷면을 그리지 않는다-시계방향으로 그리면 화면방향으로 앞면이고 반시계로 그려지면 화면방향이 뒷면이다.
        //Polygon: 다각형, directx는 삼각형을 이어붙여서 도형을 만든다.
    };
    vertexBuffer = new VertexBuffer(vertices);
}

bool ColliderRect::Collision(Vector2 point)
{
    Matrix invWorld = XMMatrixInverse(nullptr, this->world);

    Vector2 invPoint = point * invWorld;

    if (abs(invPoint.x) <= this->size.x * 0.5f
         && abs(invPoint.y) <= this->size.y * 0.5f)
    {
        return true;
    }


    return false;
}

bool ColliderRect::Collision(ColliderRect* rect)
{
    //SAT sperating axis Theorem,
    //분리축이론을 사용해서 각 축을 분리하고 그것으로 정사영을 만들어서 두 정사영이 겹치는 지 확인하고
    //그것을 모든 축에 대해 진행하여 모든 축에서 겹치는게 발생하면 충돌이다.
    Vector2 distance = this->globalPosition - rect->globalPosition;

    Vector2 axes[4] =
    {
        this->right,
        this->up,
        rect->right,
        rect->up
    };

    Vector2 vectors[4] = {
        axes[0] * (this->Size().x * 0.5f),
        axes[1] * (this->Size().y * 0.5f),
        axes[2] * (rect->Size().x * 0.5f),
        axes[3] * (rect->Size().y * 0.5f),

    };
    for (UINT i = 0; i < 4; i++)
    {
        float sum = 0;
        for (UINT j = 0; j < 4; j++)
        {
            sum += abs(Vector2::Dot(axes[i], vectors[j]));
        }
        if(sum < abs(Vector2::Dot(axes[i], distance)))
            return false;
    }

    return true;
}

bool ColliderRect::Collision(ColliderCircle* other)
{
    
    Vector2 distance = this->globalPosition - other->GlobalPostion();
    Vector2 axes[2] =
    {
        this->right,
        this->up
    };

    float lengthX = abs(Vector2::Dot(axes[0], distance));
    float lengthY = abs(Vector2::Dot(axes[1], distance));

    float radius = other->Radius();

    if (lengthX > this->Size().x * 0.5f + radius) return false;
    if (lengthY > this->Size().y * 0.5f + radius) return false;


    if (lengthX <= this->Size().x * 0.5f) return true;
    if (lengthY <= this->Size().y * 0.5f) return true;

    float x = lengthX - this->Size().x * 0.5f;
    float y = lengthY - this->Size().y * 0.5f;

    float edgeTocircle = sqrt(pow(x, 2) + pow(y, 2));


    return edgeTocircle <= radius;
}
