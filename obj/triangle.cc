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

Point* Triangle::random() {
    Point *vecab = aa->vector(bb);
    Point *vecac = aa->vector(cc);
    double r1 = ((double)rand() / RAND_MAX);
    double r2 = ((double)rand() / RAND_MAX);
    if (r1 + r2 > 1) {
        r1 = 1 - r1;
        r2 = 1 - r2;
    }
    Point *ab = vecab->scal(r1);
    Point *ac = vecac->scal(r2);
    Point *random_point = aa->translate(ab)->translate(ac);
    delete vecab;
    delete vecac;
    delete ab;
    delete ac;
    return random_point;
}
