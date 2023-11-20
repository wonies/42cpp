// #ifndef __ZOMBIE_H
// #define __ZOMBIE_H

#include <iostream>
#include <string>

class   Zombie
{
private:
    std::string name;
public:
    Zombie(std::string name)
    {
        this->name = name; //name = newName(매개변수를 name)
    };
    // ~Zombie()
    // {
    //     std::cout << "All Zombie is Disappear" << std::endl;
    // };

    void announce( void );
};

void    Zombie::announce(void)
{
    std::cout << name << "BraiiiiiiinnnzzzZ..." << std::endl;
}

Zombie *newZombie( std::string name )
{
    return new Zombie(name);
}

void    randomChump( std::string name )
{
    Zombie  randZombie(name);
    randZombie.announce();
}

// #endif