#include "Framework.h"
#include "ColliderCircle.h"


ColliderCircle::ColliderCircle(float radius)
    :radius(radius)
{
    SetVertex();

}

ColliderCircle::~ColliderCircle()
{
}

void ColliderCircle::SetVertex()
{
    for (UINT i = 0; i < VERTEX_COUNT + 1; i++)//출발한 점이 원래 위치로 돌아오기 위한 +1
    {
        float angle = XM_2PI / VERTEX_COUNT * i;
        Vertex vertex;

        vertex.pos = {
            radius * cosf(angle),
            radius * sinf(angle),
            0.0f
        };

        vertices.push_back(vertex);

    }
    vertexBuffer = new VertexBuffer(vertices);
}

bool ColliderCircle::Collision(Vector2 point)
{
    float distance = (point - this->globalPosition).Length();

	return distance <= Radius();
}

bool ColliderCircle::Collision(ColliderRect* other)
{

	return other->Collision(this);
}

bool ColliderCircle::Collision(ColliderCircle* other)
{
    float distance = (other->GlobalPostion() - this->globalPosition).Length();

	return distance <= this->Radius() + other->Radius();
}
