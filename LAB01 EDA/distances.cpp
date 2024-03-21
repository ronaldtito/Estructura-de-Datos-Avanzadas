#include <iostream>
#include <vector>
#include <random>
#include <fstream>
#include <string>

using namespace std;

//to generate random coordinate
std::random_device rd;
std::mt19937 gen(rd());
std::uniform_real_distribution<> dis(0.0, 1.0);

class Point{
public:
  vector<double> coordinates;
  Point(int dimension){
    for(int i = 0; i < dimension; i++)
      coordinates.push_back(dis(gen));
  }
  int size_of_coordinates(){
    return coordinates.size();
  }
};

vector<Point> generate_points(int n, int dimension){
  vector<Point> points_in_x_dimention;
  for(int i = 0; i < n; i++)
    points_in_x_dimention.push_back(Point(dimension));
  return points_in_x_dimention;
}

double euclidian_distance(Point p1, Point p2){
  double distance = 0;
  for(int i = 0; i < p1.size_of_coordinates(); i++)
    distance += pow(p1.coordinates[i] - p2.coordinates[i], 2);
  return sqrt(distance);
}

vector<double> calculate_distances(vector<Point> points, int dimension,int n_points){
  vector<double> distances;
  for(int i = 0; i < n_points-1; i++){
    for(int j = i+1; j < n_points; j++)
        distances.push_back(euclidian_distance(points[i], points[j]));
  }
  return distances;
}

void create_file(vector<double> distances, int dimension){
  string name_file = "dimension_" + to_string(dimension) + ".txt";
  ofstream out_file;

  out_file.open(name_file,ios::out);
  for(auto i:distances)
    out_file << i << endl;
  out_file.close();
}

int main() {
  int dimension[8] = {2,10,50,100,500,1000,2000,5000};
  int n = 100; // cantidad de puntos
  for(int i = 0; i < 8; i++){
    vector<Point> points = generate_points(n, dimension[i]);
    vector<double> distances = calculate_distances(points, dimension[i], n);
    create_file(distances,dimension[i]);
  }
}