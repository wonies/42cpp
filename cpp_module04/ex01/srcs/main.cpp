#include "Animal.hpp"
#include "Brain.hpp"
#include "Cat.hpp"
#include "Dog.hpp"

void leak() { system("leaks Brain"); }
int main(void) {
  const Animal* j = new Dog();
  const Animal* i = new Cat();

  j->makeSound();
  i->brainAllocate();
  i->brainSound();
  const Animal* copy(i);
  copy->brainSound();

  delete j;  // should not create a leak
  delete i;
  leak();
  return 0;
}