#ifndef CONVERT_HPP
#define CONVERT_HPP
#include <iomanip>
#include <string>

#include "ScalarConverter.hpp"

class Convert {
 public:
  Convert(void);
  Convert(double input);
  Convert(std::string inputs);
  Convert(Convert const &instance);
  Convert &operator=(Convert const &rhs);
  ~Convert(void);
  bool validDigit(void);
  bool validPrint(std::string input);

 private:
  char *_endptr;
  double _dinput;
  int _int;
  float _float;
  char _char;
};

#endif