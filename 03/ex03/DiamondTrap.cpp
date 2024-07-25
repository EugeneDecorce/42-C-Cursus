/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   DiamondTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edecorce <edecorce@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/17 11:10:15 by edecorce          #+#    #+#             */
/*   Updated: 2024/07/17 11:38:29 by edecorce         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "DiamondTrap.hpp"

DiamondTrap::DiamondTrap(): ClapTrap(), ScavTrap(), FragTrap()
{
	this->_name = "default name";
	this->ClapTrap::_name = "default name";

	FragTrap::_hit_points = 100;
	ScavTrap::_energy_points = 50;
	FragTrap::_attack_damage = 30;
	
	std::cout << "DiamondTrap default constructor called" << std::endl;
}

DiamondTrap::DiamondTrap(std::string name): ClapTrap(name), ScavTrap(name), FragTrap(name)
{
	this->_name = name;
	this->ClapTrap::_name = name;

	FragTrap::_hit_points = 100;
	ScavTrap::_energy_points = 50;
	FragTrap::_attack_damage = 30;
	
	std::cout << "DiamondTrap constructor for the name " << this->_name << " called" << std::endl;
}

DiamondTrap::DiamondTrap(const DiamondTrap &other)
{
	std::cout << "DiamondTrap copy constructor called" << std::endl;
	*this = other;
}

DiamondTrap::~DiamondTrap()
{
	std::cout << "DiamondTrap deconstructor for " << this->_name << " called" << std::endl;
}

void DiamondTrap::whoAmI(void)
{
	std::cout << "DiamondTrap name: " << this->_name << ", ClapTrap name: " << ClapTrap::_name << std::endl;
}