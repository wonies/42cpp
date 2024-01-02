#include "Character.hpp"

Character::Character(void) {}

Character::Character(const std::string &name) {
  for (int i = 0; i < slot; i++) inventory[i] = NULL;
}

Character::Character(Character const &instance) { *this = instance; }

Character &Character::operator=(const Character &rhs) {
  if (this != &rhs) {
    _name = rhs._name;
    for (int i = 0; i < slot; i++) {
      inventory[i] = rhs.inventory[i];
    }
  }
  return *this;
}

Character::~Character(void) {}

std::string &Character::getType() const { return Amateria.type; }

void Character::equip(Amateria *m) {
  for (int i = 0; i < slot; i++) {
    if (!inventory[i]) {
      inventory[i] = m;
      break;
    }
  }
}

void Character::unequip(int idx) {
  if (idx < 0 || idx > 4) {
    std::cout << "Invalid Slot INDEX." << std::endl;
    return;
  }
  if (inventory[idx]) {
    Amateria *removeMateria = inventory[idx];
    std::cout << "PUT HERE : " << removeMateria->getType() << std::endl;
    inventory[idx] = NULL;
  } else {
    std::cout << "Slot " << idx << "is already EMPTY" << std::endl;
  }
}

void Character::use(int idx, ICharacter &target) {
  inventory[idx] ::use(target);
}