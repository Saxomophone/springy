#include <iostream>
#include <string>
#include <vector>
#include <cmath>
#include <fstream>
using namespace std;

struct Point {
  double x;
  double y;
};

class Spring {
  public:
    Point point1;
    Point point2;
    double length_old;
    double length_new;
    double rest_length;
    double velocity = 0;

    Spring(Point point1, Point point2, double rest_length) : 
      point1{point1}, 
      point2{point2},  
      rest_length{rest_length} {

      length_old = sqrt(pow(point2.x - point1.x, 2) + pow(point2.y - point1.y, 2));
    }

    double tick(double spring_constant, double mass) {  //spring_constant in N/m, mass in kg
      // calculate force: F = -kx (Hooke's Law)       (x = displacement, k = spring constant (stiffness))
      double force = -spring_constant * (length_old - rest_length);

      // calculate acceleration (a = F/m)             (m = mass)
      double acceleration = force / mass;

      // calculate velocity
      velocity += acceleration;
      cout << "velocity: " << velocity << endl;

      // calculate position (of point2 (assuming point1 is fixed))
      point2.y += velocity;

      // calculate length
      double length_new = sqrt(pow(point2.x - point1.x, 2) + pow(point2.y - point1.y, 2));
      cout << "length: " << length_new << endl << '\n';

      return length_new;
    }
};


fstream open_file() {
  fstream file;
  file.open("generated/spring.csv", ios::out);
  if (!file) {
         cout << "Error while creating the file";
     } else {
         cout << "File created successfully";
  }
  return file;
}


int main() {
  Spring spring({0, 0}, {0, 10}, 5);
  cout << "length: " << spring.length_old << endl;
  cout << "point 1: " << spring.point1.x << ", " << spring.point1.y << endl;
  cout << "point 2: " << spring.point2.x << ", " << spring.point2.y << endl;

  
  fstream file = open_file();
  file << "time,velocity,length\n";

  double time = 1;
  while (time <= 50) {

    spring.length_old = spring.tick(1, 10);
    file << time << "," << spring.velocity << "," << spring.length_old << '\n';

    time++;
  }
  return 0;
}

