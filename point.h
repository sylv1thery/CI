#ifndef _POINT_H_
#define _POINT_H_

struct SPoint
{
    float x_;
    float y_;
};

// struct Point
typedef struct SPoint Point;

float distance2(Point* A, Point* B);

#endif