#include "point.h"

float distance2(Point* A, Point* B)
{
    float dx =  B->x_ - A->x_;
    float dy =  B->y_ - A->y_;
    return dx*dx + dy*dy;
}