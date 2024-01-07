#include "Form.hpp"

Form::Form(void) {}

Form::Form(std::string name, unsigned int authorize, unsigned int execute)
    : _name(name), _sign(0), _authorize(authorize), _execute(execute) {}

Form::Form(Form const &instance) { this = *instance; }

Form &Form::operator=(Form const &rhs) {
  if (this != &rhs) {
    _name = &rhs._name;
    _sign = &rhs._sign;
    _authorize = &rhs._authorize;
    _execute = &rhs._execute;
  }
  return *this;
}

Form::~Form() {}

void Form::beSigned(Bureaucrat &auth) {
  if (_grade > 150)
    throw(Form::GradeTooLowException());
  else if (_grade < 1)
    throw(Form::GradeTooHighException());
  if (_grade < auth._grade)
    throw(Form::GradeTooLowException());
  else {
    _sign = 1;
  }
}

std::string Form::getName() const { return _name; }

bool Form::getSign() const { return _sign; }

unsigned int Form::getAuth() const { return _authorize; }

unsigned int Form::getExecute() const { return _execute; }