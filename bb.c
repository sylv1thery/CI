#include "bb.h"

BoundingBox bb_init_circle(Circle* c)
{
    BoundingBox bb = {{ c->center_.x_ - c->radius_, c->center_.y_ - c->radius_},
                      { c->center_.x_ + c->radius_, c->center_.y_ + c->radius_}};
    return bb;
}
#define MAX(A,B) ((A)>(B))?(A):(B)
#define MIN(A,B) ((A)<(B))?(A):(B)
void add_circle(BoundingBox* bb, Circle* c)
{
    bb->min_.x_ = MIN(bb->min_.x_, c->center_.x_ - c->radius_);
    bb->min_.y_ = MIN(bb->min_.y_, c->center_.y_ - c->radius_);
    bb->max_.x_ = MAX(bb->max_.x_, c->center_.x_ + c->radius_);
    bb->max_.y_ = MAX(bb->max_.y_, c->center_.y_ + c->radius_);
}

BoundingBox bb_2circles(Circle* c1, Circle* c2)
{
    BoundingBox bb = bb_init_circle(c1);
    add_circle(&bb,c2);
    return bb;
}

Point* random_points(BoundingBox* bb, int nb)
{
    float dx = bb->max_.x_ - bb->min_.x_;
    float dy = bb->max_.y_ - bb->min_.y_;

    Point* table = malloc(nb*sizeof(Point));
    for (int i=0; i<nb; ++i)
    {
        float r = (float)(rand())/RAND_MAX;
        table[i].x_ = bb->min_.x_ + dx * r;
        r = (float)(rand())/RAND_MAX;
        table[i].y_ = bb->min_.y_ + dy * r;
    }
    return table;
}

float surface(BoundingBox* bb)
{
   float dx = bb->max_.x_ - bb->min_.x_;
   float dy = bb->max_.y_ - bb->min_.y_;
   return dx*dy;
}
