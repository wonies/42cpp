#include "Ice.hpp"

Ice::Ice(void) : Amateria("ice") {}

Ice::Ice(Ice const &instance) : Amateria("ice") { *this = instance; }

Ice &Ice::operator=(const Ice &rhs) {
  if (this != &rhs) {
    this.type = rhs.type;
  }
  return *this;
}

Ice::~Ice(void) {}

Amateria *Ice::clone() const { return *this; }

void Ice::use(ICharacter &target) {
  std::cout << "* shoots an ice bolt at " << target.name << " *" << std::endl;
}