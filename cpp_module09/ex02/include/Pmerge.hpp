#ifndef PMERGE_HPP
#define PMERGE_HPP

#include <deque>
#include <iostream>
#include <vector>

class Pmerge {
 public:
  std::vector<int> _vector;
  std::deque<int> _deque;
  void pairsplit(void);
  void pairsort(int low, int high);
  // void mergeFjsort(int low, int high);
  int _size;
  std::vector<int> _mainchain;
  std::vector<int> _pending;
  std::vector<int> jacobsthal(int n);
  void pendtomain(void);
  void pair(int low, int high, int depth);

 private:
  //   Pmerge(void);
  //   //   Pmerge(**replace parameters **);
  //   Pmerge(Pmerge const &instance);
  //   Pmerge &operator=(Pmerge const &rhs);
  //   ~Pmerge(void);
};

#endif