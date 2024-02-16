#ifndef PMERGE_HPP
#define PMERGE_HPP

#include <deque>
#include <iostream>
#include <utility>
#include <vector>

class Pmerge {
 public:
  std::vector<int> vec;
  std::deque<int> deq;
  std::vector<std::pair<int, int> > _vector;
  std::pair<int, int> _deque;
  std::vector<int> _sequence;
  void pair(void);
  void pairvec(void);
  void sortpair(int left, int right);
  void comparesort(int left, int mid, int right);
  void jnum(int n);

 private:
  //   Pmerge(void);
  //   //   Pmerge(**replace parameters **);
  //   Pmerge(Pmerge const &instance);
  //   Pmerge &operator=(Pmerge const &rhs);
  //   ~Pmerge(void);
};

#endif