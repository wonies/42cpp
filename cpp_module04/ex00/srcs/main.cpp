#include "Animal.hpp"
#include "Cat.hpp"
#include "Dog.hpp"
#include "WrongAnimal.hpp"
#include "WrongCat.hpp"

int main() {
  const Animal* meta = new Animal();
  const Animal* j = new Dog();
  const Animal* i = new Cat();
  const WrongAnimal* wrongani = new WrongAnimal();
  const WrongAnimal* wrongcat = new WrongCat();
  //   std::cout << j->getType() << " " << std::endl;
  //   std::cout << i->getType() << " " << std::endl;
  i->makeSound();  // will output the cat sound!
  j->makeSound();
  meta->makeSound();

  std::cout << "------Wrong!------" << std::endl;
  wrongcat->makeSound();
  wrongani->makeSound();

  return 0;
}

// int main() {
//   const Animal meta = Animal();
//   const Animal j = Dog();
//   const Animal i = Cat();
//   //   std::cout << j->getType() << " " << std::endl;
//   //   std::cout << i->getType() << " " << std::endl;
//   i.makeSound();  // will output the cat sound!
//   j.makeSound();
//   meta.makeSound();
//   return 0;
// }