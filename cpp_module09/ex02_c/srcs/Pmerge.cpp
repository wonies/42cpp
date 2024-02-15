#include "../include/Pmerge.hpp"

void Pmerge::pairvec(void) {
  int mid = vec.size() / 2;
  for (int i = 0; i < mid; ++i) {
    _vector.push_back(std::make_pair(vec[i], vec[i + mid]));
  }
  for (int i = 0; i < mid; ++i)
    std::cout << "vector first : " << _vector.first
              << " vector second : " << _vector.second << "\n";
}

void Pmerge::pair(void) { pairvec(); }
d