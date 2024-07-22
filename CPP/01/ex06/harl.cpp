/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   harl.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edecorce <edecorce@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/28 13:15:15 by edecorce          #+#    #+#             */
/*   Updated: 2024/07/22 11:39:12 by edecorce         ###   ########.fr       */
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
	int	index = -1;

	for (int i = 0; i < 4; i++)
	{
		if (keys[i] == level)
		{
			index = i;
			break ;
		}
	}
	switch (index)
	{
		case (0):
			for (int i = 0; i < 4; i++)
				(this->*actions[i])();
			break ;
		case (1):
			for (int i = 1; i < 4; i++)
				(this->*actions[i])();
			break ;
		case (2):
			for (int i = 2; i < 4; i++)
				(this->*actions[i])();
			break ;
		case (3):
			for (int i = 3; i < 4; i++)
				(this->*actions[i])();
			break ;
		default:
			std::cout << "Nothing to complain about " << std::endl;
			break ;
	}
}
