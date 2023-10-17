#include "Framework.h"
#include "Math.h"

int Math::Random(const int& min, const int& max)
{
    return rand() % (max - min) + min;
}

float Math::Random(const float& min, const float& max)
{
    return (rand() / (float)RAND_MAX) * (max - min) + min;
    //Normalize
}