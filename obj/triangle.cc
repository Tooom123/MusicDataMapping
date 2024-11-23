#include "triangle.h"
#include "point.h"
#include <iostream>
#include "math.h"

Triangle::Triangle(Point* a, Point* b, Point* c)
{
    aa = a;
    bb = b;
    cc = c;
}

double Triangle::area(){
    Point *vecab = aa->vector(bb);
    Point *vecac = aa->vector(cc);
    double rebeu_deter = vecab->det(vecac);
    if (rebeu_deter < 0)
    {
        rebeu_deter *= (-1);
    }
    return rebeu_deter * 1/2;
}

Point* Triangle::random(){
    Point *vecab = aa->vector(bb);
    Point *vecac = aa->vector(cc);
    double r1 = ((double) rand() / (RAND_MAX));
    double r2 = ((double) rand() / (RAND_MAX));
    if (r1 + r2 < 1)
    {
        Point *a = vecab->scal(r1);
        Point *b = vecac->scal(r2);
        aa->translate(a);
        aa->translate(b);
        return aa;
    }
    else
    {
        Point *a = vecab->scal(1 - r1);
        Point *b = vecac->scal(1 - r2);
        aa->translate(a);
        aa->translate(b);
        return aa;
    }
}
