/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edecorce <edecorce@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/28 08:02:17 by edecorce          #+#    #+#             */
/*   Updated: 2024/06/28 08:54:00 by edecorce         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"



int main()
{
	Zombie	*zomb1 = newZombie("zomb1");
	zomb1->annouce();
	delete zomb1;
	randomChump("zomb2");
}