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
  Convert scalar;
  scalar.scalarType(input);
}
