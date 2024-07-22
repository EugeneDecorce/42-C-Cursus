/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Weapon.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edecorce <edecorce@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/28 10:03:31 by edecorce          #+#    #+#             */
/*   Updated: 2024/06/28 10:29:40 by edecorce         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Weapon.hpp"

Weapon::Weapon(std::string type) : _type(type)
{
	std::cout << this->_type << ": weapon constructed" << std::endl;
}

Weapon::Weapon() : _type("fist")
{
	std::cout << this->_type << ": weapon constructed" << std::endl;
}

Weapon::~Weapon()
{
	std::cout << this->_type << ": weapon destructed" << std::endl;
}

std::string	Weapon::getType()
{
	return this->_type;
}

void	Weapon::setType(std::string type)
{
	this->_type = type;
}