#include "circle.h"

float is_inside(Point* P, Circle* C)
{
    return distance2(P,&(C->center_)) <= C->radius_*C->radius_;
}

