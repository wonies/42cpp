#include "WrongCat.hpp"

WrongCat::WrongCat(void) {}
WrongCat::WrongCat(const WrongCat &instance) : WrongAnimal(instance) {
  *this = instance;
}
WrongCat &WrongCat::operator=(const WrongCat &rhs) {
  if (this != &rhs) {
    type = rhs.type;
  }
  return *this;
}
WrongCat::~WrongCat(void) {}

void WrongCat::makeSound(void) const { std::cout << "Meow!" << std::endl; }
