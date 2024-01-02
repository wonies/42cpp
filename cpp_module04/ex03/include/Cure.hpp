#ifndef CURE_HPP
#define CURE_HPP

#include "Amateria.hpp"

class Cure {
 public:
  Cure(void);
  //   Cure(**replace parameters **);
  Cure(Cure const &instance);
  Cure &operator=(Cure const &rhs);
  ~Cure(void);

 private:
};

#endif