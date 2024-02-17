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
  std::vector<int> mainchain;
  void pair(void);
  void pairvec(void);
  void sortpair(int left, int right, int k);
  void comparesort(int left, int mid, int right);
  void jnum(int n);
  void jsort(int n);
  void insertsort(int left, int right);
  void pendorder(void);
  int _size;
  void pendtomain(int index);
  int _idx;

 private:
  //   Pmerge(void);
  //   //   Pmerge(**replace parameters **);
  //   Pmerge(Pmerge const &instance);
  //   Pmerge &operator=(Pmerge const &rhs);
  //   ~Pmerge(void);
};

#endif