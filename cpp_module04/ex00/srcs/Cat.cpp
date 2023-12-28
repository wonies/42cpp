#include "Cat.hpp"

Cat::Cat(void) { type = "CAT"; }
Cat::Cat(const Cat &instance) : Animal(instance) { *this = instance; }
Cat &Cat::operator=(const Cat &rhs) {
  if (this != &rhs) {
    type = rhs.type;
  }
  return *this;
}
Cat::~Cat(void) {}

void Cat::makeSound(void) const { std::cout << "Meow!" << std::endl; }
