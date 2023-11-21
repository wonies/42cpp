/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wonhshin <wonhshin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/20 18:21:18 by wonhshin          #+#    #+#             */
/*   Updated: 2023/11/21 10:43:52 by wonhshin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/Zombie.hpp"

int main(void)
{
    Zombie *horde;
    horde = zombieHorde(Zombie::HordeSize, "twits");
    
    for (int i=0; i<Zombie::HordeSize; i++)
        horde[i].announce(i);
    
    delete [] horde;
    return (0);
}
