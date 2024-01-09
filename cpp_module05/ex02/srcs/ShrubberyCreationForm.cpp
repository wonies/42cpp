#include "ShrubberyCreationForm.hpp"

ShrubberyCreationForm::ShrubberyCreationForm(void) {}

ShrubberyCreationForm::ShrubberyCreationForm(std::string name)
    : Form(name, 145, 137) {}

ShrubberyCreationForm::ShrubberyCreationForm(const &instance) {
  *this = instance;
}

ShrubberyCreationForm &ShrubberyCreationForm::operator=(
    ShrubberyCreationForm const &rhs) {
  if (this != &rhs) {
    this->_sign = rhs._sign;
    this->_authorize = rhs._authorize;
    this->_execute = rhs._execute;
  }
  return *this;
}

ShrubberyCreationForm::~ShrubberyCreationForm() {}
