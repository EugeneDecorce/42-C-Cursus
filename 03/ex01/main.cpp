/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edecorce <edecorce@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/17 10:22:00 by edecorce          #+#    #+#             */
/*   Updated: 2024/07/17 11:30:49 by edecorce         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScavTrap.hpp"

int main()
{
	std::cout << "Constructing" << std::endl;
	ClapTrap a;
	ClapTrap b("A");

	std::cout << "Testing" << std::endl;
	a.attack("some other robot");
	a.takeDamage(10);
	a.takeDamage(10);
	a.beRepaired(5);
	a.attack("some other other robot");
	b.beRepaired(3);
	for (int i = 0; i < 12; i++)
		b.attack("A-clone");
	b.beRepaired(3);
	std::cout << "Deconstructing" << std::endl;


	std::cout << "Constructing" << std::endl;
	ScavTrap c;
	ScavTrap d("B");

	std::cout << "Testing" << std::endl;
	c.attack("CloneTrap");
	// for (int i = 0; i < 50; i++)
	// 	c.attack("CloneTrap");
	c.beRepaired(22);
	c.takeDamage(21);
	c.beRepaired(22);
	c.guardGate();
	c.guardGate();
	d.attack("B-clone");
	d.takeDamage(101);
	d.takeDamage(15);
	d.attack("ScavTrap-clone");
	std::cout << "Deconstructing" << std::endl;
	return (0);
}