/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edecorce <edecorce@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/28 08:02:17 by edecorce          #+#    #+#             */
/*   Updated: 2024/06/28 09:24:49 by edecorce         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

int main()
{
	Zombie	*zomb_horde = zombieHorde(5, "Fabrice");
	for (int i = 0; i < 5; i++)
		zomb_horde[i].annouce();
	delete[] zomb_horde;
}