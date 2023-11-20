/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wonhshin <wonhshin@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/20 18:21:18 by wonhshin          #+#    #+#             */
/*   Updated: 2023/11/20 19:41:41 by wonhshin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/Zombie.hpp"


void    displayZombie(Zombie *zb)
{
    if (zb) {
        std::cout << "display zb : " << zb->getName() << std::endl;
    }
}

void    displayZombies(Zombie &zb)
{
        std::cout << "display zbs : " << zb.getName() << std::endl;
}

int main(void)
{
    Zombie zb("Foo");
    Zombie *newZomb = newZombie("Wonei");

    displayZombie(newZomb);
    displayZombies(zb);
    zb.announce();
    newZomb->announce();
    randomChump("Konie");

    delete  newZomb;
    return (0);
}
