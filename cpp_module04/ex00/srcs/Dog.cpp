#include "Dog.hpp"

Dog::Dog(void) { type = "DOG"; }
Dog::Dog(const Dog &instance) : Animal(instance) { *this = instance; }
Dog &Dog::operator=(const Dog &rhs) {
  if (this != &rhs) {
    type = rhs.type;
  }
  return *this;
}
Dog::~Dog(void) {}

void Dog::makeSound(void) const { std::cout << "Bark!" << std::endl; }
