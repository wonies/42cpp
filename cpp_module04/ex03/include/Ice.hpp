#ifndef ICE_HPP
#define ICE_HPP

#include "Amateria.hpp"

class ICharacter;

class Ice : public Amateria {
 public:
  Ice(void);
  //   Ice(**replace parameters **);
  Ice(Ice const &instance);
  Ice &operator=(Ice const &rhs);
  ~Ice(void);

 private:
};

#endif