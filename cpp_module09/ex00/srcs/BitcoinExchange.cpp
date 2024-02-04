#include "BitcoinExchange.hpp"

bool BitcoinExchange::validInput(std::string input) {
  std::ifstream inputdata(input);
  std::string _line;

  if (!inputdata.is_open()) {
    std::cerr << "can't open" << std::endl;
    return 1;
  }
  if (std::getline(inputdata, _line)) {
    if ((_line != "date | value")) return 1;
  }
  while (std::getline(inputdata, _line)) {
    while (!_line.empty()) {
      if (_line.find('|') != std::string::npos) {
        if (!(_line[4] == '-' || _line[7] == '-'))
          break;
        else if (!(_line[10] == ' ' && _line[12] == ' '))
          break;

        int yy = std::stod(_line.substr(0, 4));
        int mm = std::stod(_line.substr(5, 6));
        int dd = std::abs(std::stod(_line.substr(7, 8)));
        double val = std::stod(_line.substr(13, _line.find('\0')));
        (void)yy;
        (void)mm;
        (void)dd;
        if (mm < 1 || mm > 12) std::cout << "month err" << std::endl;

        if (yy % 4 != 0) {
          if (mm == 2 && dd > 28)
            std::cout << "2-29" << std::endl;
          else if (mm == 4 || mm == 6 || mm == 9 || mm == 11) {
            if (dd > 30) std::cout << "day error - 4, 6, 9, 11" << std::endl;
          } else {
            if (dd > 31) std::cout << "day error - remaining " << std::endl;
          }
        }

        if (yy % 4 == 0) {
          if (mm == 2 && dd > 29) std::cout << "over 2month 29day" << std::endl;
        }

        if (val >= INT_MAX || val < 0) {
          std::cout << "out of range : int" << std::endl;
          break;
        }
        _line.clear();
      } else
        _line.clear();
    }
  }
  return 0;
}