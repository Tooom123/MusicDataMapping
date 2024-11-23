#include <iostream>
#include <vector>
using namespace std;

#include "point.h"
#include "polygon.h"
#include "triangle.h"

int pass=0;
int fail=0;

int test_string (string name, Point* actual, string expected){
  if (actual!=NULL) {
    string actual_str = actual->to_string();
    if (actual_str == expected){
      pass++;
      cout << name << " PASS" << endl;
    } else {
      fail++;
      cout << name << " FAIL: '" << actual_str << "' instead of '" << expected << "'" << endl;
    }
  } else {
    fail++;
    cout << name << " FAIL: point NULL instead of '" << expected << "'" << endl;
  }
  return 0;
}

int test_double (string name, double actual, double expected){
  if (actual == expected) {
    pass++;
    cout << name << " PASS" << endl;
  } else {
    cout << name << " FAIL: " << actual << " instead of " << expected << endl;
    fail++;
  }
  return 0;
}


int main() {
  Point* p1 = new Point (0,0);
  Point* p2 = new Point (0,1);
  Point* p3 = new Point (1,1);
  Point* p4 = new Point (1,0);
  Point* p5 = p2->translate(p2);
  Point* p6 = p2->scal(2);
  Point* v1_2 = p1->vector(p2);
  Point* mid1_2 = p1->center(p2);

  Triangle* t1 = new Triangle(p1,p2,p3);
  Triangle* t2 = new Triangle(p1,p5,p3);
  Triangle* t3 = new Triangle(p1,p1,p1);
  vector<Point*> pts1{p1, p2, p3, p4};
  Polygon* poly1 = new Polygon(pts1);
  vector<Point*> pts2{p1, p5, p3, p4};
  Polygon* poly2 = new Polygon(pts2);
  vector<Point*> pts3{p1, p1, p1};
  Polygon* poly3 = new Polygon(pts3);

  test_string ("point creation", p1, "0.000000 0.000000");
  test_string ("vector creation", v1_2, "0.000000 1.000000");
  test_string ("center", mid1_2, "0.000000 0.500000");
  test_string ("translation", p5, "0.000000 2.000000");
  test_string ("scal", p6, "0.000000 2.000000");
  test_double ("det 1", p1->det(p3), 0.0);
  test_double ("det 2", p4->det(p3), 1.0);
  test_double ("triangle volume 1", t1->area(), 0.5);
  test_double ("triangle volume 2", t2->area(), 1.);
  test_double ("triangle volume 3", t3->area(), 0.);
  test_string ("triangle random", t3->random(), "0.000000 0.000000");
  test_double ("polygon volume", poly1->area(), 1.0);
  test_double ("polygon volume", poly2->area(), 1.5);
  test_double ("polygon volume", poly3->area(), 0.);
  test_string ("polygon random", poly3->random(), "0.000000 0.000000");

  cout << "Pass: " << pass << ", Fail: " << fail << endl;

  return 0;
}
