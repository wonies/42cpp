#include "Convert.hpp"

Convert::Convert(void) {}

Convert::Convert(Convert const &instance) { *this = instance; }

Convert &Convert::operator=(Convert const &rhs) {
  if (this != &rhs) {
  }
  return *this;
}

Convert::~Convert(void) {}

Convert::Convert(double input) : _dinput(input) {}

bool Convert::validPrint(std::string input) {
  if (input.find("inf")) {
    std::cout << "-----------" << std::endl;
    double df;
    df = strtod(input.c_str(), &_endptr);
    std::cout << "char: impossible" << std::endl;
    int _int = static_cast<int>(df);
    std::cout << "int: " << _int << std::endl;
    std::cout << std::fixed << std::setprecision(1);
    float _float = static_cast<float>(df);
    std::cout << "float: " << _float << "f" << std::endl;
    std::cout.precision(1);
    std::cout << "double: " << _dinput << std::endl;
  }
  return 0;
}

bool Convert::validDigit() {
  if (_dinput == 0) {
    std::cout << "char: "
              << "Non displayable" << std::endl;
    int _int = static_cast<int>(_dinput);
    std::cout << "int: " << _int << std::endl;
    float _float = static_cast<float>(_dinput);
    std::cout << std::fixed << std::setprecision(1);
    std::cout << "float: " << _float << "f" << std::endl;
    std::cout.unsetf(std::ios_base::fixed);
    std::cout.precision(6);
    std::cout << "double: " << _dinput << std::endl;
    return 1;
  } else if (_dinput > 2147483647 || _dinput < -2147483648) {
    std::cout << "char: impossible" << std::endl;
    std::cout << "int: impossible" << std::endl;
    std::cout << std::fixed << std::setprecision(1);
    float _float = static_cast<float>(_dinput);
    std::cout << "float: " << _float << "f" << std::endl;
    std::cout.precision(1);
    std::cout << "double: " << _dinput << std::endl;
    return 1;
  } else {
    std::cout << "char: Non displayable" << std::endl;
    int _int = static_cast<int>(_dinput);
    std::cout << "int: " << _int << std::endl;
    float _float = static_cast<float>(_dinput);
    std::cout << std::fixed << std::setprecision(1);
    std::cout << "float: " << _float << "f" << std::endl;
    std::cout.precision(1);
    std::cout << "double: " << _dinput << std::endl;
  }
  return 0;
  //   } else if (_dinput == nan || _dinput == nanf) {
  //     std::cout << "char : impossible\n";
  //     std::cout << "int : impossible\n";
  //     std::cout << "float : " << _dinput << "f" << std::endl;
  //     std::cout << "double: " << _dinput << std::endl;
  //     return 0;
  //   }
}

int Convert::checkType(std::string input) {
  _dinput = strtod(input.c_str(), &_endptr);
  if (input != _endptr) {
    if (*_endptr == '\0') {
      if (_dinput <= 2147483647 && _dinput >= -2147483648)
        return type_int;
      else
        return type_double;
    } else if (*_endptr == 'f' && ++*_endptr == '\0')
      return type_double;
    else if (input.size() == 1)
      return type_char;
    else
      return type_literal;
  }
  return 0;
}

void Convert::scalarType(std::string input) {
  type_define type = checkType(input);
  _input = input;
  if (type == type_int)
    castInt();
  else if (type == type_float)
    castFloat();
  else if (type == type_double)
    castDouble();
  else if (type == type_char)
    castChar();
  else
    caseLiteral();
}

void Convert::castInt(void) {
  int _int = static_cast<int>(_dinput);
  std::cout << std::fixed << std::setprecision(1);
  float _float = static_cast<float>(_int);
  std::cout.unsetf(std::ios_base::fixed);
  std::cout.precision(1);
  double _double = static_cast<double>(_int);
  caseIntShout();
}

void Convert::caseIntShout(void) {
  std::cout << "char : Non displayable" << std::endl;
  std::cout << "int : " << _int << std::endl;
  std::cout << "float : " << _float << "f" << std::endl;
  std::cout << "double : " << _double << std::endl;
}

void Convert::castFloat(void) {
  std::cout << std::fixed << std::setprecision(1);
  float _float = static_cast<float>(_dinput);
  char _char = static_cast<char>(_float);
  std::cout.unsetf(std::ios_base::fixed);
  std::cout.precision(1);
  int _int = static_cast<int>(_float);
  double _double = static_cast<double>(_float);
  caseFloatShout();
}

void Convert::caseFloatShout(void) {
  std::cout << "char : " << _char << std::endl;
  std::cout << "int : " << _int << std::endl;
  std::cout << "float : " << _float << "f" << std::endl;
  std::cout << "double : " << _double << std::endl;
}

void Convert::castDouble(void) {
  double _double = static_cast<double>(_dinput);
  std::cout << std::fixed << std::setprecision(1);
  float _float = static_cast<float>(_dinput);
  std::cout.unsetf(std::ios_base::fixed);
  std::cout.precision(1);
  int _int = static_cast<int>(_float);
  caseDoubleShout();
}

void Convert::caseDoubleShout(void) {
  std::cout << "char : "
            << "impossible" << std::endl;
  std::cout << "int : "
            << "impossible" << std::endl;
  std::cout << "float : " << _float << "f" << std::endl;
  std::cout << "double : " << _double << std::endl;
}

void Convert::castChar(void) {
  c = _input[0] += 32;
  caseCharShout();
}

void Convert::caseCharShout(void) {
  std::cout << "char : " << c << std::endl;
  std::cout << "int : "
            << "impossible" << std::endl;
  std::cout << "float : "
            << "impossible" << std::endl;
  std::cout << "double : "
            << "impossible" << std::endl;
}

void Convert::caseLiteral(void) { std::cout << "it's literal" << std::endl; }