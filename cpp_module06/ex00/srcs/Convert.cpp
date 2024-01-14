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