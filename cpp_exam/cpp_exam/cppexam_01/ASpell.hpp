#pragma once

#include <iostream>
#include <string>
#include "ATarget.hpp"

class ATarget;

class ASpell
{
    private:
        std::string _name;
        std::string _effects;
    public:
        ASpell();
        ASpell(ASpell const &src);
        ASpell& operator=(const ASpell &src);
        virtual ~ASpell();
        ASpell(std::string const &name, std::string const &effects);
        std::string const &getName() const;
        std::string const &getEffects() const;


        void launch(ATarget const &ref) const;
        ASpell virtual *clone() const = 0;
};