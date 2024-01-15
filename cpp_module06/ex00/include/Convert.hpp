#ifndef CONVERT_HPP
#define CONVERT_HPP
#include <iomanip>
#include <string>

#include "ScalarConverter.hpp"

enum type_define {
  type_int = 0,
  type_float,
  type_double,
  type_char,
  type_literal,
};

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
  void scalarType(std::string input);
  int checkType(std::string input);
  void castInt(void);
  void castFloat(void);
  void castDouble(void);
  void castChar(void);
  void caseLiteral(void);
  void caseIntShout(void);
  void caseFloatShout(void);
  void caseDoubleShout(void);
  void caseCharShout(void);

 private:
  char *_endptr;
  double _dinput;
  int _int;
  float _float;
  char _char;
  double _double;
  unsigned int c;
  std::string _input;
};

#endif