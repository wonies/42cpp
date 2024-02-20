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
  void jnum(int n);
  void mainsort(int left, int mid, int right);
  void pendtomain(int index, int bindex);
  void binaryinsert(int value, int left, int right);
  void pendingorder(void);
  void sortpair(int left, int right);
  void pairvector(void);
  void pair(void);
  bool input(int ac, char** av);
  void execute(int ac, char** av);
  void pendorder(void);
  void printvector(void);
  void vector(void);
  int _vecsize;
  int _decsize;
  int _idx;
  int pairsize;
  int k;
  void prints(void);

 private:
  //   Pmerge(void);
  //   //   Pmerge(**replace parameters **);
  //   Pmerge(Pmerge const &instance);
  //   Pmerge &operator=(Pmerge const &rhs);
  //   ~Pmerge(void);
};

#endif