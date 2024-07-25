/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edecorce <edecorce@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/17 10:22:00 by edecorce          #+#    #+#             */
/*   Updated: 2024/07/24 13:51:33 by edecorce         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "FragTrap.hpp"
#include "ClapTrap.hpp"
#include "DiamondTrap.hpp"

int main()
{
	DiamondTrap diamond("diamond");
	DiamondTrap diamond2(diamond);
	DiamondTrap diamond3(".");

	diamond.whoAmI();
	diamond2.whoAmI();
	diamond3 = diamond;
	diamond3.whoAmI();

	diamond.attack("something");
	diamond.takeDamage(10);
	diamond.beRepaired(10);

	return (0);
}