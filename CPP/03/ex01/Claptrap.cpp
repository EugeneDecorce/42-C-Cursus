/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Claptrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edecorce <edecorce@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/15 19:47:24 by edecorce          #+#    #+#             */
/*   Updated: 2024/07/17 10:21:39 by edecorce         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"

ClapTrap::ClapTrap() : _name("default_name"), _hit_points(10), _energy_points(10), _attack_damage(0) {
	std::cout << "Default ClapTrap constructor called" << std::endl;
}

ClapTrap::ClapTrap(std::string name) : _name(name), _hit_points(10), _energy_points(10), _attack_damage(0) {
	std::cout << "ClapTrap constructor called" << std::endl;
}

ClapTrap::ClapTrap(const ClapTrap &other) 
{
	std::cout << "ClapTrap copy constructor called" << std::endl;
	*this = other;
}

ClapTrap::~ClapTrap() {
	std::cout << "ClapTrap deconstructor called" << std::endl;
}

ClapTrap &ClapTrap::operator=(const ClapTrap &other)
{
	std::cout << "ClapTrap assignment operator called" << std::endl;
	this->_name = other._name;
	this->_hit_points = other._hit_points;
	this->_energy_points = other._energy_points;
	this->_attack_damage = other._attack_damage;
	return *this;
}

std::string	ClapTrap::getName(void) const {
	return this->_name;
}

void	ClapTrap::takeDamage(unsigned int amount) {
	if (this->_hit_points > amount)
		this->_hit_points -= amount;
	else if (this->_hit_points > 0)
		this->_hit_points = 0;
	else
	{
		std::cout << this->getName() << " is already dead!" << std::endl;
		return ;
	}
	std::cout << this->getName() << " took " << amount << " damage points!" << std::endl;
}

void	ClapTrap::attack(const std::string &target) {
	if (this->_energy_points > 0 && this->_hit_points > 0)
	{
		std::cout << this->getName() << " attacks " << target <<", causing " << this->_attack_damage << " points of damage!" << std::endl;
		this->_energy_points -= 1;
	}
	else if (this->_energy_points == 0)
		std::cout << "No energy points left: cannot do anything!" << std::endl;
	else
		std::cout << "No hit points left: cannot attack!" << std::endl;
}

void	ClapTrap::beRepaired(unsigned int amount) {
	if (this->_energy_points && this->_hit_points && this->_hit_points + amount <= 10)
	{
		std::cout << this->getName() << " healed " << amount << " hit points" << std::endl;
		this->_hit_points += amount;
		this->_energy_points -= 1;
	}
	else if (this->_energy_points == 0)
		std::cout << "No energy points left: cannot do anything" << std::endl;
	else if (this->_hit_points == 0)
		std::cout << "No hit points left: already dead" << std::endl;
	else
		std::cout << "CAnnot have more than 10 hit points" << std::endl;
}