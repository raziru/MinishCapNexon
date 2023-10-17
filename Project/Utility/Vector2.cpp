#include "Framework.h"
#include "Vector2.h"

Vector2::Vector2()
    :XMFLOAT2(0, 0)
{
}

Vector2::Vector2(float x, float y)
    :XMFLOAT2(x, y)
{
}

float Vector2::Length()
{
    return sqrtf(powf(x,2) + powf(y,2));
}

Vector2 Vector2::GetNormal()
{
    if (Length() == 0)
        return *this ;

    return *this / (this->Length());
}

void Vector2::Normalize()
{
    
    *this /= this->Length();
     
}

float Vector2::Dot(const Vector2& v1, const Vector2& v2)//내적
{
    return v1.x*v2.x + v1.y*v2.y;
}

float Vector2::Cross(const Vector2& v1, const Vector2& v2)//외적
{
    return v1.x*v2.y - v1.y*v2.x;
}

bool Vector2::IsBetween(const Vector2& factor, const Vector2& v1, const Vector2& v2)
{
    if (Cross(factor, v1) * Cross(factor, v2) < 0)
    {
        return true;
    }
    return false;
    //return Cross(factor,v1)*Cross(factor,v2) < 0;
}

Vector2 Vector2::Lerp(const Vector2& start, const Vector2& end, const float& factor)
{
    return start + (end-start)*factor;
}

Vector2 Vector2::operator+(const Vector2& other) const
{
    
    return Vector2(this->x + other.x, this->y + other.y);
}

Vector2 Vector2::operator-(const Vector2& other) const
{
    
    return Vector2(this->x - other.x, this->y - other.y);
}

Vector2 Vector2::operator*(const float& value) const
{
    return Vector2(this->x*value, this->y * value);
}

Vector2 Vector2::operator/(const float& value) const
{
    return Vector2(this->x / value, this->y / value);
}

void Vector2::operator+=(const Vector2& other)
{
    this->x += other.x;
    this->y += other.y;

}

void Vector2::operator-=(const Vector2& other)
{
    this->x -= other.x;
    this->y -= other.y;
}

void Vector2::operator*=(const float& value)
{
    this->x *= value;
    this->y *= value;
}

void Vector2::operator/=(const float& value)
{
    this->x /= value;
    this->y /= value;
}

Vector2 Vector2::operator*(const Matrix& value) const
{
    XMVECTOR point = XMLoadFloat2(this);

    point = XMVector2TransformCoord(point, value);//coord: 위치 연산, normal: 벡터 연산

    Vector2 position;

    XMStoreFloat2(&position, point);

    return position;
}

void Vector2::operator*=(const Matrix& value)
{
    XMVECTOR point = XMLoadFloat2(this);

    point = XMVector2TransformCoord(point, value);//coord: 위치 연산, normal: 벡터 연산

    Vector2 position;

    XMStoreFloat2(&position, point);
    
    *this = position;
}

