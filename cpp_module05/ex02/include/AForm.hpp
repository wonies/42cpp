#ifndef AFORM_HPP
#define AFORM_HPP

#include "Bureaucrat.hpp"

class Bureaucrat;

class AForm {
 public:
  AForm(void);
  AForm(std::string name, unsigned int authorize, unsigned int execute);
  AForm(Form const &instance);
  AForm &operator=(AForm const &rhs);
  virtual ~AForm(void);
  void beSigned(Bureaucrat &);
  virtual void execute(Bureaucrat const &executor) const;
  std::string getName() const;
  bool getSign() const;
  unsigned int getAuth() const;
  unsigned int getExecute() const;
  class GradeTooHighException : public std::exception {
   public:
    virtual const char *what() const throw() {
      return "Form Grade is too high";
    }
  };
  class GradeTooLowException : public std::exception {
   public:
    virtual const char *what() const throw() { return "Form Grade is too low"; }
  };

 private:
  const std::string _name;
  bool _sign;
  unsigned int _authorize;
  unsigned int _execute;
};

std::ostream &operator<<(std::ostream &os, const AForm &obj);

#endif