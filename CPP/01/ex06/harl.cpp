/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   harl.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edecorce <edecorce@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/28 13:15:15 by edecorce          #+#    #+#             */
/*   Updated: 2024/06/28 15:10:04 by edecorce         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Harl.hpp"

Harl::Harl()
{
	std::cout << "Harl created" << std::endl;
}

Harl::~Harl()
{
	std::cout << "Harl dextructed" << std::endl;
}

void	Harl::debug(void)
{
	std::cout << "DEBUG" << std::endl;
}

void	Harl::info(void)
{
	std::cout << "INFO" << std::endl;
}

void	Harl::warning(void)
{
	std::cout << "WARNING" << std::endl;
}

void	Harl::error(void)
{
	std::cout << "ERROR" << std::endl;
}

void	Harl::complain(std::string level)
{
	void (Harl::*actions[4])(void) = {&Harl::debug, &Harl::info, &Harl::warning, &Harl::error};
	std::string keys[4] = {"DEBUG", "INFO", "WARNING", "ERROR"};
	bool	trigger = false;

	for (int i = 0; i < 4; i++)
	{
		if (keys[i] == level || trigger)
		{
			(this->*actions[i])();
			trigger = true;
		}
	}
}
