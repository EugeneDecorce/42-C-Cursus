/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edecorce <edecorce@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/17 10:22:00 by edecorce          #+#    #+#             */
/*   Updated: 2024/07/17 11:50:26 by edecorce         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "FragTrap.hpp"
#include "ClapTrap.hpp"

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
	FragTrap e;
	FragTrap f("C");

	std::cout << "Testing" << std::endl;
	e.highFivesGuys();
	e.attack("some random dude");
	e.takeDamage(101);
	e.takeDamage(1);
	e.attack("some random dude");
	f.highFivesGuys();
	std::cout << "Deconstructing" << std::endl;

	return (0);
}