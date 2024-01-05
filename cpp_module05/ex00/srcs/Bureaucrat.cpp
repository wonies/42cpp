#include "Bureaucrat.hpp"

Bureaucrat::Bureaucrat(void) {}

Bureaucrat::Bureaucrat(const std::string name, unsigned int grade)
    : _name(name), _grade(grade) {}

Bureaucrat::Bureaucrat(Bureaucrat const &instance) { *this = instance; }

Bureaucrat &Bureaucrat::operator(Bureaucrat const &rhs) {
  if (this != rhs) {
    _name = rhs._name;
    _grade = rhs._grade;
  }
}

Bureaucrat::~Bureaucrat() {}
