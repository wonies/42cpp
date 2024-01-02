#include "Icharacter.hpp"

ICharacter::ICharacter(void) {}

ICharacter::ICharacter(ICharacter const &instance) { *this = instance; }

ICharacter &ICharacter::operator=(ICharacter const &rhs) {
  if (this != &rhs) {
    this._name = rhs._name;
  }
  return *this;
}

ICharacter::~ICharacter(void) {}
