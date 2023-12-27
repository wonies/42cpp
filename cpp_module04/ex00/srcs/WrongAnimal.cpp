#include "WrongAnimal.hpp"

WrongAnimal::WrongAnimal(void) {}
WrongAnimal::WrongAnimal(const WrongAnimal &instance) : type(instance.type) {
  *this = instance;
}
WrongAnimal &WrongAnimal::operator=(const WrongAnimal &rhs) {
  if (this != &rhs) {
    this->type = rhs.type;
  }
  return *this;
}
WrongAnimal::~WrongAnimal(void) {}

void WrongAnimal::makeSound(void) const {
  std::cout << "some Sound" << std::endl;
}
