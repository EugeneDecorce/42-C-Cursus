/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edecorce <edecorce@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/26 17:20:12 by edecorce          #+#    #+#             */
/*   Updated: 2024/06/26 17:21:48 by edecorce         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "classes/headers/contact.hpp"
#include "classes/headers/phonebook.hpp"

int main()
{
	PhoneBook phonebook;
	while (1)
	{
		std::string input;
		std::cout << "~Enter a command: ";
		std::getline(std::cin, input);
		if (input == "EXIT")
			return (0);
		else if (input == "ADD")
			phonebook.ADD();
		else if (input == "SEARCH")
			phonebook.SEARCH();
		else 
			std::cout << "Available commands: ADD, SEARCH, EXIT" << std::endl;
	}
	return (0);
}