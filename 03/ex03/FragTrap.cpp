/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   FragTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edecorce <edecorce@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/17 11:10:15 by edecorce          #+#    #+#             */
/*   Updated: 2024/07/17 11:38:57 by edecorce         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "FragTrap.hpp"

FragTrap::FragTrap(): ClapTrap()
{
	this->_hit_points = 100;
	this->_energy_points = 100;
	this->_attack_damage = 30;
	std::cout << "FragTrap default constructor called" << std::endl;
}

FragTrap::FragTrap(const FragTrap &other): ClapTrap(other)
{
	std::cout << "FragTrap copy constructor called" << std::endl;
	*this = other;
}

FragTrap::FragTrap(std::string name): ClapTrap(name)
{
	this->_hit_points = 100;
	this->_energy_points = 100;
	this->_attack_damage = 30;
	std::cout << "FragTrap constructor for the name " << this->_name << " called" << std::endl;
}

FragTrap::~FragTrap()
{
	std::cout << "FragTrap deconstructor for " << this->_name << " called" << std::endl;
}

FragTrap &FragTrap::operator=(const FragTrap &src)
{
	std::cout << "FragTrap assignment operator called" << std::endl;
	this->_name = src._name;
	this->_hit_points = src._hit_points;
	this->_energy_points = src._energy_points;
	this->_attack_damage = src._attack_damage;
	return *this;
}

void	FragTrap::highFivesGuys(void)
{
	std::cout << "High Five ?" << std::endl;
}
