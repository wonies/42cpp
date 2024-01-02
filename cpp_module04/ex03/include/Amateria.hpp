#ifndef AMATERIA_HPP
#define AMATERIA_HPP

#include <iostream>

#include "ICharacter.hpp"

class ICharacter;

class Amateria {
 public:
  Amateria(void);
  Amateria(std::string const &type);
  Amateria(Amateria const &instance);
  Amateria &operator=(Amateria const &rhs);
  virtual ~Amateria(void);
  std::string const &getType() const;
  virtual Amateria *clone() const = 0;
  virtual void use(ICharacter &target) = 0;

 protected:
  std::string _type;

 private:
};

#endif