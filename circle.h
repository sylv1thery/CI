#ifndef _CIRCLE_H_
#define _CIRCLE_H_

#include "point.h"
typedef struct Circle
{
    Point center_;
    float radius_;
} Circle;

float is_inside(Point* P, Circle* C);

#endif