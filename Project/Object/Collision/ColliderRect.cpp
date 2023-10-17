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

        //BackFace Culling: �޸��� �׸��� �ʴ´�-�ð�������� �׸��� ȭ��������� �ո��̰� �ݽð�� �׷����� ȭ������� �޸��̴�.
        //Polygon: �ٰ���, directx�� �ﰢ���� �̾�ٿ��� ������ �����.
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
    //�и����̷��� ����ؼ� �� ���� �и��ϰ� �װ����� ���翵�� ���� �� ���翵�� ��ġ�� �� Ȯ���ϰ�
    //�װ��� ��� �࿡ ���� �����Ͽ� ��� �࿡�� ��ġ�°� �߻��ϸ� �浹�̴�.
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
