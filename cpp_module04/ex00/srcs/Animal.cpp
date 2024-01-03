#include "Animal.hpp"

Animal::Animal(void) {}
Animal::Animal(const Animal &instance) : type(instance.type) {
  *this = instance;
}
Animal &Animal::operator=(const Animal &rhs) {
  if (this != &rhs) {
    this->type = rhs.type;
  }
  return *this;
}
Animal::~Animal(void) {}

// void Animal::makeSound(void) const { std::cout << "some Sound" << std::endl;
// }

std::string Animal::getType(void) const { return type; }