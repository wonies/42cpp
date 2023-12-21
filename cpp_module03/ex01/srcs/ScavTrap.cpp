#include "ScavTrap.hpp"

ScavTrap::ScavTrap(void) { std::cout << "🍳Derived Constructor" << std::endl; }

ScavTrap::ScavTrap(const std::string _name) : ClapTrap(_name) {}

ScavTrap::ScavTrap(const ScavTrap &instance) { *this = instance; };

ScavTrap &ScavTrap::operator=(const ScavTrap &rhs) {
  if (this != &rhs) {
    Name = ClapTrap.name;
    HitPoints = rhs.HitPoints;
    EnergyPoints = rhs.EnergyPoints;
    AttackDamage = rhs.AttackDamage;
  }
  return *this;
}

ScavTrap::~ScavTrap(void) { std::cout << "Derived Destructor🍳" << std::endl; }

void ScavTrap::guardGate() {
  std::cout << "아군을 고르세요. 1. 파이리" std::cout
            << "아군이 Gate를 Keeper한다." << std::endl;
}