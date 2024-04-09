#include <iostream>
#include <string>
#include <vector>
#include <cmath>
#include <fstream>

#define TimeIncrementSeconds 0.1
#define TotalTimeSeconds 200

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

    double tick(double spring_constant, double mass, double dt) {  //spring_constant in N/m, mass in kg
      // calculate force: F = -kx (Hooke's Law)       (x = displacement, k = spring constant (stiffness))
      double force = -spring_constant * (length_old - rest_length);

      // calculate acceleration (a = F/m)             (m = mass)
      double acceleration = force / mass * dt;

      // calculate velocity
      velocity += acceleration;
      std::cout << "velocity: " << velocity << std::endl;

      // calculate position (of point2 (assuming point1 is fixed))
      point2.y += velocity * dt;

      // calculate length
      double length_new = sqrt(pow(point2.x - point1.x, 2) + pow(point2.y - point1.y, 2));
      std::cout << "length: " << length_new << std::endl << '\n';

      return length_new;
    }
};


std::fstream open_file() {
  std::fstream file;
  file.open("generated/spring.csv", std::ios::out);
  if (!file) {
         std::cout << "Error while creating the file";
     } else {
         std::cout << "File created successfully";
  }
  return file;
}


int main() {
  Spring spring({0, 0}, {0, 10}, 5);

  
  std::fstream file = open_file();
  file << "time,velocity,length\n";

  double time = 0;
  while (time <= TotalTimeSeconds) {

    file << time << "," << spring.velocity << "," << spring.length_old << '\n';
    spring.length_old = spring.tick(1, 10, TimeIncrementSeconds);

    time += TimeIncrementSeconds;
    std::cout << "time: " << time << std::endl;
  }
  return 0;
}

