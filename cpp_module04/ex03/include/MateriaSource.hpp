#ifndef MATERIASOURCE_HPP
#define MATERIASOURCE_HPP

#include "ImateriaSource.hpp"

class MateriaSource : IMateriaSource {
 public:
  MateriaSource(void);
  MateriaSource(**replace parameters **);
  MateriaSource(MateriaSource const &instance);
  MateriaSource &operator=(MateriaSource const &rhs);
  ~MateriaSource(void);

 private:
};

#endif