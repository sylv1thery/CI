#ifndef _BB_H_
#define _BB_H_

#include <stdlib.h>
#include "circle.h"
#include "point.h"
typedef struct SBoundingBox
{
    Point min_;
    Point max_;
} BoundingBox;

BoundingBox bb_2circles(Circle* c1, Circle* c2);

Point* random_points(BoundingBox* bb, int nb);

float surface(BoundingBox* bb);

#endif