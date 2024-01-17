#include "ScalarConverter.hpp"

#include "Convert.hpp"

double ScalarConverter::_conv = 0.0;
char *ScalarConverter::_endptr = nullptr;

ScalarConverter::ScalarConverter(void) {}

ScalarConverter::ScalarConverter(const ScalarConverter &instance) {
  *this = instance;
}

ScalarConverter &ScalarConverter::operator=(const ScalarConverter &rhs) {
  if (this != &rhs) {
    _char = rhs._char;
    _int = rhs._int;
    _float = rhs._float;
    _double = rhs._double;
  }
  return *this;
}

ScalarConverter::~ScalarConverter(void) {}

void ScalarConverter::convert(std::string input) {
  // Convert scalar(input);

  // std::cout << _conv << std::endl;
  // valid.validPrint(input);
  // _conv = strtod(input.c_str(), &_endptr);

  Convert scalar;
  scalar.scalarType(input);
  _conv = strtod(input.c_str(), &_endptr);
  // if (_endptr != '\0') {
  //   valid.validDigit();
  // }
  char _char = static_cast<char>(_conv);
  std::cout << "check : " << _endptr << std::endl;
  int _int = static_cast<int>(_conv);
  std::cout << "check : " << _endptr << std::endl;

  float _float = static_cast<float>(_conv);
  std::cout << "check : " << _endptr << std::endl;
  std::cout << "main_char: " << _char << std::endl;
  std::cout << "main_int: " << _int << std::endl;
  std::cout << "main_float: " << _float << std::endl;
  std::cout << "main_double: " << _conv << std::endl;
}
