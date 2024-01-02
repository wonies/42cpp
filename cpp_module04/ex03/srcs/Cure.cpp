#include "Cure.hpp"

Cure::Cure(void) : Amateria("cure") {}

Cure::Cure(Cure const &instance) : Amateria("cure") { *this = instance; }

Cure &Cure::operator=(Cure const &rhs) {
  if (this != &rhs) {
    this.type = rhs.type;
  }
  return *this;
}

Cure::~Cure(void) {}

Amateria *Cure::clone() const { return *this; }

void Cure::use(ICharacter &target) {
  std::cout << "* heals " << target.name << "'s wounds *" << std::endl;
}