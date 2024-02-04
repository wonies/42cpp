#ifndef BITCOINEXCHANGE_HPP
#define BITCOINEXCHANGE_HPP

#include <cmath>
#include <fstream>
#include <iostream>
#include <map>
#include <string>

class BitcoinExchange {
 public:
  //   BitcoinExchange(void);
  //   BitcoinExchange(BitcoinExchange const &instance);
  //   BitcoinExchange &operator=(BitcoinExchange const &rhs);
  //   ~BitcoinExchange(void);
  bool validInput(std::string input);
  int _yy;
  int _mm;
  int _dd;
  double _val;
  bool calandervalid();

 private:
};

#endif
