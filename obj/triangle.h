#ifndef TRIANGLE_H
#define TRIANGLE_H

#include "point.h"

class Triangle{
public:
    Point* aa;
    Point* bb;
    Point* cc;
  Triangle(Point* a, Point* b, Point* c);
  double area();
  Point* random();
};


#endif
