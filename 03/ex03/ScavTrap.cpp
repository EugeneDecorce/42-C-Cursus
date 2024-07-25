/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScavTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edecorce <edecorce@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/17 11:10:15 by edecorce          #+#    #+#             */
/*   Updated: 2024/07/17 11:38:29 by edecorce         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScavTrap.hpp"

ScavTrap::ScavTrap(): ClapTrap()
{
	this->_hit_points = 100;
	this->_energy_points = 50;
	this->_attack_damage = 20;
	this->_guard_gate = false;
	std::cout << "ScavTrap default constructor called" << std::endl;
}

ScavTrap::ScavTrap(const ScavTrap &other): ClapTrap(other)
{
	this->_guard_gate = other._guard_gate;
	std::cout << "ScavTrap copy constructor called" << std::endl;
}

ScavTrap::ScavTrap(std::string name): ClapTrap(name)
{
	this->_hit_points = 100;
	this->_energy_points = 50;
	this->_attack_damage = 20;
	this->_guard_gate = false;
	std::cout << "ScavTrap constructor for the name " << this->_name << " called" << std::endl;
}

ScavTrap::~ScavTrap()
{
	std::cout << "ScavTrap deconstructor for " << this->_name << " called" << std::endl;
}

ScavTrap &ScavTrap::operator=(const ScavTrap &src)
{
	std::cout << "ScavTrap assignment operator called" << std::endl;
	this->_name = src._name;
	this->_hit_points = src._hit_points;
	this->_energy_points = src._energy_points;
	this->_attack_damage = src._attack_damage;
	return *this;
}

void	ScavTrap::attack(const std::string &target)
{
	if (this->_energy_points > 0 && this->_hit_points > 0)
	{
		std::cout << "ScavTrap " << this->_name << " attacks " << target << ", causing " << this->_attack_damage << " points of damage!" << std::endl;
		this->_energy_points--;
	}
	else if (this->_energy_points == 0)
		std::cout << "ScavTrap " << this->_name << " cannot attack " << target << ", no energy points left." << std::endl;
	else
		std::cout << "ScavTrap " << this->_name << " cannot attack " << target << ", not enough hit points." << std::endl;
}

void	ScavTrap::guardGate(void)
{
	if (this->_guard_gate == false)
	{
		this->_guard_gate = true;
		std::cout << "ScavTrap " << this->_name << " is now guarding the gate." << std::endl;
	}
	else
		std::cout << "ScavTrap " << this->_name << " is already guarding the gate." << std::endl;
}
