#include "Cat.hpp"

Cat::Cat(void) {
  type = "CAT";
  brain = new Brain();
  std::cout << "\033[0;34m*냥냥이 생성자*\033[0;30m" << std::endl;
}

Cat::Cat(const Cat &instance) : Animal(instance) { *this = instance; }
Cat &Cat::operator=(const Cat &rhs) {
  if (this != &rhs) {
    type = rhs.type;
    delete brain;
    if (rhs.brain)
      brain = new Brain(*rhs.brain);
    else
      brain = NULL;
  }
  return *this;
}
Cat::~Cat(void) {
  std::cout << "\033[0;34m~냥냥이 소멸자~\033[0;30m" << std::endl;
  delete brain;
}

void Cat::makeSound(void) const { std::cout << "Meow!" << std::endl; }

void Cat::brainAllocate(void) const { brain[0] = Brain("wonie"); }
void Cat::brainSound(void) const { std::cout << "zzz" << std::endl; }