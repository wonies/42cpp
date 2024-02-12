#ifndef PMERGE_HPP
#define PMERGE_HPP

#include <deque>
#include <iostream>
#include <vector>

class Pmerge {
 public:
  std::vector<int> _vector;
  std::deque<int> _deque;
  void pairsplit(int low, int high);
  void pairsort(int low, int high);
  // void mergeFjsort(int low, int high);
  int _size;

 private:
  //   Pmerge(void);
  //   //   Pmerge(**replace parameters **);
  //   Pmerge(Pmerge const &instance);
  //   Pmerge &operator=(Pmerge const &rhs);
  //   ~Pmerge(void);
};

#endif