#include "Span.hpp"

Span::Span(void) {}

Span::Span(unsigned int n) { _arr.push_back(n); }

Span::Span(Span const &instance) { *this = instance; }

Span &Span::operator=(Span const &rhs) {
  if (this != &rhs) {
    for (unsigned long i = 0; i <= _arr.size(); i++) {
      _arr[i] = rhs._arr[i];
    }
  }
  return *this;
}

Span::~Span(void) {}

void Span::addNumber(unsigned int n) {
  std::vector<int>::iterator it;
  for (it = _arr.begin(); it != _arr.end(); it++) {
    if (*it == static_cast<int>(n)) throw std::runtime_error("already exist.");
  }
  _arr.push_back(n);
}

int Span::shortestSpan(void) {
  if ((_arr.empty()) || (_arr.size() == 1))
    throw std::runtime_error("can't find. array is empty");
  sort(_arr.begin(), _arr.end());
  return _arr[1] - _arr[0];
}

int Span::longestSpan(void) {
  if ((_arr.empty()) || (_arr.size() == 1))
    throw std::runtime_error("can't find. array is empty");
  sort(_arr.begin(), _arr.end());
  int _end = _arr.back();
  int _begin = _arr.front();
  return _end - _begin;
}