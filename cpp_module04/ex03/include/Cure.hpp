#ifndef CURE_HPP
#define CURE_HPP

#include "Amateria.hpp"
#include "Icharacter.hpp"

class ICharacter;

class Cure : public AMateria {
 public:
  Cure(void);
  Cure(Cure const &instance);
  Cure &operator=(Cure const &rhs);
  ~Cure(void);
  AMateria *clone() const;
  void use(ICharacter &target);

 private:
};

#endif