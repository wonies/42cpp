// #ifndef __ZOMBIE_H
// #define __ZOMBIE_H

#include <iostream>
#include <string>

class   Zombie
{
private:
    std::string name;
public:
    static const int HordeSize = 5;
    Zombie();
    ~Zombie();
    void announce(int idx);
    void settingName(std::string naming);
};

Zombie* zombieHorde( int N, std::string name );

// #endif