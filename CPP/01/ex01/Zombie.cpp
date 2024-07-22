/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edecorce <edecorce@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/28 07:38:44 by edecorce          #+#    #+#             */
/*   Updated: 2024/06/28 09:19:36 by edecorce         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

Zombie::Zombie(std::string name) : _name(name)
{
	std::cout << _name << " constructed" << std::endl;
}

Zombie::Zombie(void) : _name("null")
{
	std::cout << "Zombie constructed" << std::endl;
}

Zombie::~Zombie()
{
	std::cout << _name << " destructed" << std::endl;
}

void	Zombie::annouce(void)
{
	std::cout << _name << ": BraiiiiiiinnnzzzZ..." << std::endl;
}


void	Zombie::setName(std::string name)
{
	this->_name = name;
}