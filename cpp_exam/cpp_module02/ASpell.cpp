#include "ASpell.hpp"

ASpell::ASpell()
{
    return ;
}

ASpell::ASpell(ASpell const &src)
{
    *this = src;
}

ASpell& ASpell::operator=(const ASpell &src)
{
    _name = src._name;
    _effects = src._effects;
    return *this;
}

ASpell::~ASpell()
{
    return ;
}

ASpell::ASpell(std::string const &name, std::string const &effects) : _name(name), _effects(effects)
{
    return ;
}

std::string const &ASpell::getName() const
{
    return _name;
}

std::string const &ASpell::getEffects() const{
    return _effects;
}

void ASpell::launch(ATarget const &src) const
{
    src.getHitBySpell(*this);    
} 
