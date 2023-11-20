#include "../inc/Zombie.hpp"

int main(void)
{
    Zombie zb("FOO");
    
    zb.announce();

    Zombie *newZomb = newZombie("Wonei");
    newZomb->announce();
    delete  newZomb;

    randomChump("Kcian");

    return (0);
}