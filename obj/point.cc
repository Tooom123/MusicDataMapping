#include "point.h"
#include <iostream>

Point::Point(const double x, const double y): x(x),y(y){}

Point* Point::vector(Point* p){
    Point *a = new Point(p->x-x, p->y-y);
    return a;
}

Point* Point::center(Point* b) {
    Point *a = new Point((x+b->x)/2, (y+b->y)/2);
  return a;
}

Point* Point::translate(Point* p){
    Point *a = new Point(x+p->x, y+p->y);
  return a;
}

Point* Point::scal(double coef){
    Point *a = new Point(x*coef, y*coef);
  return a;
}

double Point::det(Point* p){
    return x*p->y - y*p->x;
}


// dont modify me, i'm used for the tests!
std::string Point::to_string (){
  return std::to_string(x) + " " + std::to_string(y);
}
