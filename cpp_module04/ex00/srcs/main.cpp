#include "Animal.hpp"
#include "Cat.hpp"
#include "Dog.hpp"
#include "WrongAnimal.hpp"
#include "WrongCat.hpp"

void leak() { system("leaks Zoo"); }

int main() {
  const Animal* meta = new Animal();
  const Animal* j = new Dog();
  const Animal* i = new Cat();
  const WrongAnimal* wrongani = new WrongAnimal();
  const WrongAnimal* wrongcat = new WrongCat();
  WrongAnimal* wrongcat2 = new WrongCat();

  std::cout << "----------Class TYPE---------" << std::endl;
  std::cout << j->getType() << " " << std::endl;
  std::cout << i->getType() << " " << std::endl;
  std::cout << "----------Make Noise---------" << std::endl;
  i->makeSound();  // will output the cat sound!
  j->makeSound();
  meta->makeSound();
  (void)wrongcat2;

  leak();
  std::cout << "\n------Wrong!------\nSituation that is not "
               "VIRTUAL\n------------------"
            << std::endl;
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