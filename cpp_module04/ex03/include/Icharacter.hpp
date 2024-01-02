#ifndef ICHARACTER_HPP
#define ICHARACTER_HPP

#include <iostream>

#include "AMateria.hpp"

class AMateria;

class ICharacter {
 public:
  ICharacter(void);
  ICharacter(**replace parameters **);
  ICharacter(ICharacter const &instance);
  ICharacter &operator=(ICharacter const &rhs);
  ~ICharacter(void);
  virtual ~ICharacter() {}
  virtual std::string const &getName() const = 0;
  virtual void equip(AMateria *m) = 0;
  virtual void unequip(int idx) = 0;
  virtual void use(int idx, ICharacter &target) = 0;

 private:
};

#endif