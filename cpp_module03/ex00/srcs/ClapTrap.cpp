#include "include/ClapTrap.hpp"

ClapTrap::ClapTrap(void) {}

ClapTrap::ClapTrap(const ClapTrap &ct) { *this = ct; }

ClapTrap &ClapTrap::operator=(const ClapTrap &ct) {
  //   if (this != ct) {
  //   }
  (void)&ct;
  return (*this);
}

ClapTrap::~ClapTrap(void) {}

ClapTrap::ClapTrap(std::string _name)
    : Name(_name), HitPoints(10), EnergyPoints(10), AttackDamage(10) {}
