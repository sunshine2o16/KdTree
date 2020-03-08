#include <iostream>
#include "../include/kdtree/static_kd_tree_3d.hpp"
#include "../include/point_cloud/point_cloud.hpp"
#include "../include/point_type/point_type.hpp"

int main() {
  kdtree::StaticKdTree3d<point_type::Point3f, point_cloud::PointCloud>
      kd_tree_3d;
  for (int i = 0; i < 20; i++) {
    kd_tree_3d.add(
        point_type::Point3f(static_cast<float>(i), 0.f, static_cast<float>(i)));
  }
  kd_tree_3d.build();

  point_type::Point3f point_to_search(4.2f, 0.f, 3.9f);
  std::vector<int> indices;
  std::vector<float> squared_distances;

  std::cout << "=====================nearestKSearch======================"
            << std::endl;
  int num_3d =
      kd_tree_3d.nearestKSearch(point_to_search, 6, indices, squared_distances);

  std::cout << "Find:" << num_3d << "points," << std::endl;
  for (int i = 0; i < num_3d; i++) {
    std::cout << "Point" << i << ": " << kd_tree_3d[indices[i]];
    std::cout << ", Distance: " << std::sqrt(squared_distances[i]) << std::endl;
  }
  std::cout << "======================radiusSearch======================="
            << std::endl;
  num_3d = kd_tree_3d.radiusSearch(point_to_search, 8.5f, indices,
                                   squared_distances);
  std::cout << "Find:" << num_3d << "points," << std::endl;
  for (int i = 0; i < num_3d; i++) {
    std::cout << "Point" << i << ": " << kd_tree_3d[indices[i]];
    std::cout << ", Distance: " << std::sqrt(squared_distances[i]) << std::endl;
  }

  return 0;
}
