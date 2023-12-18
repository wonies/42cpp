#ifndef __CLAPTRAP__H__
#define __CLAPTRAP__H__

#include <string.h>

#include <iostream>

class ClapTrap {
 public:
  ClapTrap(void);
  ClapTrap(const ClapTrap &ct);
  ClapTrap &operator=(const ClapTrap &ct);
  ~ClapTrap(void);
  void attack(const std::string &target);

 protected:
 private:
  string Name;
  int HitPoints;
  int EnergyPoints;
  int AttackDamage;
}

#endif