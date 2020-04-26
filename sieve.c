#include "sieve.h"
#include <stdio.h>

float sieve(Circle* c1, Circle *c2)
{
    BoundingBox bb = bb_2circles(c1,c2);
    printf("BB: %f,%f %f,%f \n",bb.min_.x_,bb.min_.y_,bb.max_.x_,bb.max_.y_);
    const int NB = 1000000;
    Point* table = random_points(&bb,NB);
    int count = 0;
    for (int i=0; i<NB; ++i)
    {
        Point* P = table+i;
        if (is_inside(P,c1) && is_inside(P,c2))
            count++;
    }
    float s = surface(&bb);
    printf("BB surface: %f\n",s);

    float ratio = ((float)count)/NB;
    printf("Ratio: %f \n",ratio);

    return s * ratio;
}

