#include "RPN.hpp"
// RPN::~RPN(void) {}

bool RPN::err(std::string input) {
  int ccnt = 0;
  int ncnt = 0;
  try {
    for (size_t i = 0; i < input.length(); i++) {
      char c = input[i];
      if (!((c >= '0' && c <= '9') ||
            (c == '+' || c == '-' || c == '*' || c == '/' || c == ' '))) {
        throw std::out_of_range("Index : out of range");
      } else if (c >= '0' && c <= '9') {
        ccnt++;
      } else if (c == '+' || c == '-' || c == '*' || c == '/')
        ncnt++;
    }
  } catch (const std::exception& e) {
    std::cerr << e.what() << "\n";
    return false;
  }
  if (ccnt - 1 != ncnt) {
    std::cout << "Error: can't calculate\n";
    return false;
  }
  return true;
}

bool RPN::enter(std::string input) {
  if (!err(input)) return false;
  std::stack<int_least32_t> _stack;
  int value = 0;

  for (size_t i = 0; i < input.length(); i++) {
    char c = input[i];
    if (c == '+' || c == '-' || c == '*' || c == '/') {
      if (_stack.size() < 2) {
        std::cerr << "Error\n";
        return false;
      }
      int operandL = _stack.top();
      _stack.pop();
      int operandR = _stack.top();
      _stack.pop();
      if (c == '+')
        value = operandL + operandR;
      else if (c == '*')
        value = operandL * operandR;
      else if (c == '-')
        value = operandL - operandR;
      else if (c == '/')
        value = operandL / operandR;
    }
    _stack.push(c - '0');
  }
  return true;
}