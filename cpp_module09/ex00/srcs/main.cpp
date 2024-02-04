#include "BitcoinExchange.hpp"

int main(int ac, char **av) {
  BitcoinExchange btcoin;

  if (ac != 2) {
    std::cout << "argument must be 2" << std::endl;
    return 0;
  }
  std::ifstream database("data.csv");  // 파일 열기
  // std::ifstream inputdata(av[1]);      // 파일 열기

  if (!database.is_open()) {
    std::cerr << "파일을 열 수 없습니다." << std::endl;
    return 1;
  }
  // if (!inputdata.is_open()) {
  //   std::cerr << "can't open" << std::endl;
  //   return 1;
  // }
  std::cout << std::fixed << std::setprecision(2);
  std::string line;
  char *_end;
  std::map<std::string, std::string> _maps;
  while (std::getline(database, line)) {
    _maps[line.substr(0, 10)] = line.substr(11, 12);
    btcoin._yy = atoi(line.substr(0, 4).c_str());
    btcoin._mm = atoi(line.substr(5, 6).c_str());
    btcoin._dd = atoi(line.substr(8, 9).c_str());
    btcoin._val = strtod(line.substr(11, line.find('\0')).c_str(), &_end);
  }

  std::map<std::string, std::string>::iterator it;

  for (it = _maps.begin(); it != _maps.end(); it++) {
    std::cout << it->first << ":" << it->second << "만" << std::endl;
  }
  std::string input(av[1]);
  btcoin.validInput(input);
  // std::string _line;
  // if (std::getline(inputdata, _line)) {
  //   if (_line != "date | value")
  //     std::cout << "not valid" << std::endl;
  //   else
  //     std::cout << "valid" << std::endl;
  // }
  // while (std::getline(inputdata, _line)) {
  //   while (!_line.empty()) {
  //     if (_line.find('|') != std::string::npos) {
  //       if (_line[4] == '-' && _line[7] == '-') {
  //         std::cout << "-check!!" << std::endl;
  //       }
  //       if (!(_line[10] == ' ' && _line[12] == ' '))
  //         std::cout << "space error " << std::endl;

  //       if (_line.find('-')) {
  //         int yy = std::stod(_line.substr(0, 4));
  //         std::cout << yy << std::endl;
  //       }
  //       int mm = std::stod(_line.substr(5, 6));
  //       int dd = std::abs(std::stod(_line.substr(7, 8)));
  //       std::cout << mm << std::endl;
  //       std::cout << dd << std::endl;
  //       double val = std::stod(_line.substr(13, line.find('\0')));
  //       if (val >= INT_MAX || val < 0) {
  //         std::cout << "out of range : int" << std::endl;
  //       }
  //       std::cout << val << std::endl;
  //       _line.clear();
  //     } else {
  //       std::cout << "error" << std::endl;
  //       _line.clear();
  //     }
  //   }
  // }

  database.close();  // 파일 닫기

  return 0;
}
