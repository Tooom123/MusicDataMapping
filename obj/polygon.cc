#include <cmath>
#include <vector>

#include "polygon.h"
#include "point.h"

Polygon::Polygon(std::vector<Point*> vert){
  if (vert.size() >= 3)
    {
      sommets = vert;
    }
}

double Polygon::area(){
  double total_area = 0;
  for (size_t i = 1; i < sommets.size() - 1; ++i) {
    Triangle triangle(sommets[0], sommets[i], sommets[i + 1]);
    total_area += triangle.area();
  }
  return total_area;
}

Point* Polygon::random(){
  size_t triangle_index = rand() % (sommets.size() - 2);
  Triangle chosen_triangle(
			   sommets[0],
			   sommets[triangle_index + 1],
			   sommets[triangle_index + 2]
			   );
  return chosen_triangle.random();
}
