#ifndef MUSTACK_HPP
#define MUSTACK_HPP

#include <iostream>
#include <stack>

template <typename T>
class MutantStack {
 public:
  MutantStack(void){};
  MutantStack(MutantStack const &instance);
  MutantStack &operator=(MutantStack const &rhs);
  ~MutantStack(void);

 private:
  std::stack<T> _stack;
};

#endif