#ifndef SPAN_HPP
#define SPAN_HPP

#include <iostream>
#include <list>
#include <vector>
class Span {
 public:
  Span(void);
  Span(unsigned int n);
  Span(Span const &instance);
  Span &operator=(Span const &rhs);
  ~Span(void);
  void addNumber(unsigned int n);
  // void getarr() {
  //   std::vector<int>::iterator it;
  //   int i = 0;
  //   for (it = _arr.begin();it != _arr.end(); it++) {
  //     std::cout << _arr[i++] << std::endl;
  //   }
  // }
  int shortestSpan(void);
  int longestSpan(void);

 private:
  std::vector<int> _arr;
};

#endif