#ifndef PMERGE_HPP
#define PMERGE_HPP

#include <ctime>
#include <deque>
#include <iostream>
#include <sstream>
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
  void insertsort(int value);
  void pendorder(void);
  void pendtomain(int index, int bindex);
  void printvector(void);
  void excute(int ac, char** av);
  bool input(int ac, char** av);
  int _size;
  int _idx;
  clock_t _vecstart;
  clock_t _vecend;
  clock_t _deqstart;
  clock_t _deqend;
  double _usec;

 private:
  //   Pmerge(void);
  //   //   Pmerge(**replace parameters **);
  //   Pmerge(Pmerge const &instance);
  //   Pmerge &operator=(Pmerge const &rhs);
  //   ~Pmerge(void);
};

#endif