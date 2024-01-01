#ifndef __ANIMAL__H__
#define __ANIMAL__H__

#include <iostream>

class AAnimal {
 protected:
  std::string type;

 public:
  Animal(void);
  Animal(const Animal &instance);
  Animal &operator=(const Animal &rhs);
  virtual ~Animal(void);
  virtual void makeSound(void) const = 0;
  virtual void brainAllocate() const = 0;
  virtual void brainSound() const = 0;
  virtual void brainAlert(void) const = 0;
  std::string getType(void) const;
};

#endif