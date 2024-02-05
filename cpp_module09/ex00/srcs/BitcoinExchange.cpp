#include "BitcoinExchange.hpp"

BitcoinExchange::BitcoinExchange(void) {}

BitcoinExchange::BitcoinExchange(BitcoinExchange const &instance) {
  *this = instance;
}

BitcoinExchange &BitcoinExchange::operator=(BitcoinExchange const &rhs) {
  if (this != &rhs) {
    _yy = rhs._yy;
    _mm = rhs._mm;
    _dd = rhs._dd;
    _val = rhs._val;
    _maps = rhs._maps;
    //_maps.insert(rhs._maps.begin(), rhs._maps.end())
  }
  return *this;
}

BitcoinExchange::~BitcoinExchange(void) {}

bool BitcoinExchange::validInput(std::string input) {
  std::ifstream inputdata(input);
  std::string _line;

  if (!inputdata.is_open()) {
    std::cerr << "can't open" << std::endl;
    return false;
  }
  if (std::getline(inputdata, _line)) {
    if ((_line != "date | value")) return false;
  }
  while (std::getline(inputdata, _line)) {
    while (!_line.empty()) {
      if (!(inputvalid(_line))) break;
      _yy = std::stod(_line.substr(0, 4));
      _mm = std::stod(_line.substr(5, 2));
      _dd = std::abs(std::stod(_line.substr(8, 2)));
      _val = std::stod(_line.substr(13, _line.find('\0')));
      if (!(calandervalid())) break;
      mapdata(_line);
      _line.clear();
    }
    _line.clear();
  }
  return 0;
}

bool BitcoinExchange::database(void) {
  std::ifstream database("data.csv");
  if (!database.is_open()) {
    std::cerr << "database can't open" << std::endl;
    return false;
  }
  std::cout << std::setprecision(2);
  std::string line;

  if (std::getline(database, line)) {
    if ((line != "date,exchange_rate")) return false;
  }
  while (std::getline(database, line)) {
    std::string _sum =
        line.substr(0, 4) + line.substr(5, 2) + line.substr(8, 2);
    int atoisum = atoi(_sum.c_str());
    _maps[atoisum] = std::stod(line.substr(11, line.find('\0')));
  }
  return true;
}

bool BitcoinExchange::inputvalid(std::string line) {
  if (line.find('|') != std::string::npos) {
    if (!(line[4] == '-' || line[7] == '-')) {
      std::cout << "Error: not valid input line\n";
      return false;
    } else if (!(line[10] == ' ' && line[12] == ' ')) {
      std::cout << "Error: not valid input line\n";
      return false;
    }
  } else {
    std::cout << "Error: not valid input line\n";
    return false;
  }
  return true;
}

bool BitcoinExchange::calandervalid(void) {
  if (_yy % 4 != 0) {
    if (_mm == 2 && _dd > 28) {
      std::cout << "Error: not valid day of month" << std::endl;
      return false;
    }
  } else {
    if (_mm == 2 && _dd > 29) {
      std::cout << "Error: not valid day of month" << std::endl;
      return false;
    }
  }

  if (_mm < 1 || _mm > 12) {
    std::cout << "Error: not valid month" << std::endl;
    return false;
  }
  if (_mm == 4 || _mm == 6 || _mm == 9 || _mm == 11) {
    if (_dd > 30) {
      std::cout << "Error: not valid day of month" << std::endl;
      return false;
    }
  } else {
    if (_dd > 31) {
      std::cout << "Error: not valid day of month" << std::endl;
      return false;
    }
  }
  if (_val > INT_MAX) {
    std::cout << "Error: too large a number" << std::endl;
    return false;
  } else if (_val < 0) {
    std::cout << "Error: not a positive number" << std::endl;
    return false;
  }
  return true;
}
// 2011-01-03 => 3 = 0.9
// 2011-01-03 => 2 = 0.6
// 2011-01-03 => 1 = 0.3
// 2011-01-03 => 1.2 = 0.36
// 2011-01-09 => 1 = 0.32
// Error: not a positive number.
// Error: bad input => 2001-42-42
// 2012-01-11 => 1 = 7.1
// Error: too large a number

bool BitcoinExchange::mapdata(std::string line) {
  std::string lineinput =
      line.substr(0, 4) + line.substr(5, 2) + line.substr(8, 2);
  int target = std::stod(lineinput);
  std::map<int, double>::iterator it;
  for (it = _maps.begin(); it != _maps.end(); it++) {
    if (it->first == target) {
      std::cout << line.substr(0, 10) << " => " << _val << " = "
                << it->second * _val << std::endl;
      return true;
    }
  }
  std::map<int, double>::iterator lower = _maps.lower_bound(target);
  std::map<int, double>::iterator prevLower = std::prev(lower);
  if (prevLower != _maps.begin()) {
    std::cout << line.substr(0, 10) << " => " << _val << " = "
              << prevLower->second * _val << std::endl;
    return true;
  } else {
    std::cout << "database isn't exist\n";
    return false;
  }

  return true;
}