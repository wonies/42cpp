#ifndef CHARACTER_HPP
#define CHARACTER_HPP

#include "Amateria.hpp"

#define slot 4

class Character : public ICharacter {
 public:
  Character(void);
  Character(const std::string &name);
  Character(Character const &instance);
  Character &operator=(Character const &rhs);
  ~Character(void);
  std::string const &getName() const;
  void equip(Amateria *m);
  void unequip(int idx);
  void use(int idx, ICharacter &target);

 private:
  Amateria *inventory[slot];
  std::string _name;
};

#endif