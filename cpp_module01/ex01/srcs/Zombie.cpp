#include "../inc/Zombie.hpp"

void    Zombie::announce(int idx)
{
    std::cout << idx << ":\t" << name << ": BraiiiiiiinnnzzzZ..." << std::endl;
};

Zombie::Zombie()
{
};

Zombie::~Zombie()
{
    std::cout << "[DIED AGAIN 🧟‍♂️ | 🧟‍♀️ " << name  << ']' << ": Zombie is Disappear" << std::endl;
};

void    Zombie::settingName(std::string naming)
{
    name = naming;
}

Zombie* zombieHorde( int N, std::string name )
{
    Zombie  *horde = new Zombie[N];
    
    for (int i=0; i<N; i++)
        horde[i].settingName(name);
    return horde;
}
