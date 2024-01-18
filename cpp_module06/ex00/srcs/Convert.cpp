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
bool Convert::charInput(void) {
  if (_input.length() == 1 && _endptr != '\0') {
    c = _input[0] += 32;
    int _int = static_cast<int>(c);
    float _float = static_cast<float>(c);
    double _double = static_cast<double>(c);
    std::cout << "char : " << c << std::endl;
    std::cout << "int : " << _int << std::endl;
    std::cout << "float : " << _float << std::endl;
    std::cout << "double : " << _double << std::endl;
    return 1;
  }
  return 0;
}

int Convert::checkType(std::string input) {
  _dinput = strtod(input.c_str(), &_endptr);
  std::cout << "input : " << input << std::endl;
  int dotfinds = -1;
  dotfinds = input.find(".");
  std::cout << "double input : " << _dinput << std::endl;
  std::cout << "----1----" << std::endl;
  std::cout << "dot : " << dotfinds << std::endl;
  std::cout << "end ptr : " << *_endptr << std::endl;
  std::cout << _dinput << std::endl;
  if (input.find("nan")) std::cout << "nan!!" << std::endl;
  if (charInput()) return type_char;

  if (input != _endptr) {
    if (*_endptr == '\0') {
      if (_dinput == 0 ||
          (_dinput <= 2147483647 && _dinput >= -2147483648 && dotfinds == -1)) {
        std::cout << "int" << std::endl;
        return type_int;
      } else if (dotfinds == -1)
        return type_double;
    } else if (*_endptr == 'f' && dotfinds != -1) {
      ++*_endptr;
      if (*_endptr == '\0') return type_float;
    } else if (input.size() == 1)
      return type_char;
    else {
      return type_literal;
    }
  }
  return 0;
}

void Convert::scalarType(std::string input) {
  _input = input;
  int type = checkType(input);
  std::cout << "Type : " << type << std::endl;
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
  std::cout << "char : Non displayable" << std::endl;
  std::cout << "cast Int : " << _int << std::endl;
  std::cout << std::fixed << std::setprecision(1);
  float _float = static_cast<float>(_dinput);
  std::cout << "cast Float : " << _float << "f" << std::endl;
  std::cout << "cast Double : " << _dinput << std::endl;
}

void Convert::castFloat(void) {
  std::cout << std::fixed << std::setprecision(1);
  float _float = static_cast<float>(_dinput);
  char _char = static_cast<char>(_dinput);
  std::cout.unsetf(std::ios_base::fixed);
  std::cout.precision(1);
  int _int = static_cast<int>(_dinput);
  std::cout << "char : " << _char << std::endl;
  std::cout << "int : " << _int << std::endl;
  std::cout << "float : " << _float << "f" << std::endl;
  std::cout << "double : " << _dinput << std::endl;
}

void Convert::castDouble(void) {
  double _double = _dinput;
  float _float = static_cast<float>(_double);
  int _int = static_cast<int>(_double);
  if (_input == "nan" || _dinput < 2147483647 || _dinput > -2147483648) {
    std::cout << "char : "
              << "impossible" << std::endl;
    std::cout << "int : "
              << "impossible" << std::endl;
    std::cout << "float : " << _float << "f" << std::endl;
    std::cout << "double : " << _dinput << std::endl;
    return;
  }
  std::cout << "char : "
            << "impossible" << std::endl;
  std::cout << "int : " << _int << std::endl;
  std::cout << "float : " << _float << "f" << std::endl;
  std::cout << "double : " << _double << std::endl;
}

void Convert::castChar(void) {
  std::cout << "_input : " << _input[0] << std::endl;
  c = (_input[0] += 32);
  std::cout << "char : " << c << std::endl;
}

void Convert::caseLiteral(void) { std::cout << "it's literal" << std::endl; }