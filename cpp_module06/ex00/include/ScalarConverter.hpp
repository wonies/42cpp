#ifndef SCALARCONVERTER_HPP
#define SCALARCONVERTER_HPP

#include <stdlib.h>

#include <iostream>

// class Convert;

class ScalarConverter {
 public:
  static void convert(std::string input);

 private:
  ScalarConverter(void);
  ScalarConverter(ScalarConverter const &instance);
  ScalarConverter &operator=(ScalarConverter const &rhs);
  ~ScalarConverter(void);
  static double _conv;
  char _char;
  int _int;
  float _float;
  double _double;
  static char *_endptr;
};

#endif