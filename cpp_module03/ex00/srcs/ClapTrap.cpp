#include "ClapTrap.hpp"

ClapTrap::ClapTrap(void) {}

ClapTrap::ClapTrap(std::string _name)
    : Name(_name), HitPoints(10), EnergyPoints(10), AttackDamage(10) {}

ClapTrap::ClapTrap(const ClapTrap &ct) { *this = ct; }

ClapTrap &ClapTrap::operator=(const ClapTrap &ct) {
  if (this != ct) {
  }
  (void)&ct;
  return (*this);
}

ClapTrap::~ClapTrap(void) {}

void ClapTrap::attack(const std::string &target) {
  if (EnergyPoints <= 0 || HitPoints <= 0) return;
  std::cout << this->Name << " (은/는) " << target << " (을/를) "
            << AttackDamage << " 만큼 공격했다!" << std::endl;
  EnergyPoints--;
  std::cout << "\n\n-----------------CURRENT STATUS------------------"
            << std::endl;
  std::cout << "\t\tcurrent ENERGY : " << EnergyPoints << std::endl;
  std::cout << "\t\tcurrent HITPOINTS : " << HitPoints << std::endl;
  if (EnergyPoints <= 3)
    std::cout << "[WARNING] CHECK YOUR ENERGY POINTS!" << std::endl;
  std::cout << "---------------------STATUS-----------------------\n"
            << std::endl;
}

void ClapTrap::takeDamage(unsigned int amount) {
  if (EnergyPoints <= 0 || HitPoints <= 0) return;
  HitPoints -= amount;
  std::cout << this->Name << " (은/는) " << amount << " 만큼 공격받았다."
            << std::endl;
  std::cout << "\n\n-----------------CURRENT STATUS------------------"
            << std::endl;
  std::cout << "\t\tcurrent ENERGY : " << EnergyPoints << std::endl;
  std::cout << "\t\tcurrent HITPOINTS : " << HitPoints << std::endl;
  if (EnergyPoints <= 3)
    std::cout << "[WARNING] CHECK YOUR ENERGY POINTS!" << std::endl;
  std::cout << "---------------------STATUS-----------------------\n"
            << std::endl;
}

void ClapTrap::beRepaired(unsigned int amount) {
  if (EnergyPoints <= 0 || HitPoints <= 0) return;
  EnergyPoints--;
  HitPoints += amount;
  std::cout << Name << " (은/는) " << amount << " 만큼 회복하였다. "
            << std::endl;
  std::cout << "\n\n-----------------CURRENT STATUS------------------"
            << std::endl;
  std::cout << "\t\tcurrent ENERGY : " << EnergyPoints << std::endl;
  std::cout << "\t\tcurrent HITPOINTS : " << HitPoints << std::endl;
  if (EnergyPoints <= 3)
    std::cout << "[WARNING] CHECK YOUR ENERGY POINTS!" << std::endl;
  std::cout << "---------------------STATUS-----------------------\n"
            << std::endl;
}

void ClapTrap::others(ClapTrap &ct, unsigned int _amount) {
  ct.HitPoints += _amount;
  std::cout << ct.Name << " " << _amount << std::endl;
}

void ClapTrap::others_() {
  // Mem++;
  std::cout << "static: \t" << Mem << std::endl;
}

// int ClapTrap::Mem = 0;