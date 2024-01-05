#ifndef BUREAUCRAT_HPP
#define BUREAUCRAT_HPP

#include <exception>
#include <iostream>

class Bureaucrat {
 public:
  Bureaucrat(void);
  Bureaucrat(const std::string name, unsigned int grade);
  Bureaucrat(Bureaucrat const &instance);
  Bureaucrat &operator=(Bureaucrat const &rhs);
  virtual ~Bureaucrat(void);
  class GradeTooHighException : public std::exception {
   public:
    virtual char *what() throw() { return "Grade is too high"; }
  };
  class GradeTooLowException : public std::exception {
   public:
    virtual const char *what() throw() { return "Grade is too low"; }
  };

 private:
  const std::string _name;
  unsigned int _grade;
};

#endif