#ifndef ICE_HPP
#define ICE_HPP

#include "Amateria.hpp"

class ICharacter;

class Ice : public AMateria {
 public:
  Ice(void);
  Ice(Ice const &instance);
  Ice &operator=(Ice const &rhs);
  ~Ice(void);
  AMateria *clone() const;
  void use(ICharacter &target);

 private:
};

#endif
