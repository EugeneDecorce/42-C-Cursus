/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   phonebook.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edecorce <edecorce@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/26 12:05:24 by edecorce          #+#    #+#             */
/*   Updated: 2024/07/22 17:06:15 by edecorce         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "phonebook.hpp"
#include "contact.hpp"

PhoneBook::PhoneBook() : index(0)
{
	for (int i = 0; i < 8;  i++)
		contacts[i] = Contact();
}

int	ft_isnum(std::string str)
{
	for (int i = 0; str[i]; i++)
	{
		if (!(str[i] >= '0' && str[i] <= '9'))
		{
			std::cout << "Not a number" << std::endl;
			return (0);
		}
	}
	return (1);
}

void	PhoneBook::ADD()
{
	std::string first_name;
	while (first_name.empty())
	{
		std::cout << "First name: ";
		std::getline(std::cin, first_name);
	}
	std::string last_name;
	while (last_name.empty())
	{
		std::cout << "Last name: ";
		std::getline(std::cin, last_name);
	}
	std::string nickname;
	while (nickname.empty())
	{
		std::cout << "Nickname: ";
		std::getline(std::cin, nickname);
	}
	std::string phone_number;
	while (phone_number.empty() || !ft_isnum(phone_number))
	{
		std::cout << "Phone number: ";
		std::getline(std::cin, phone_number);
	}
	std::string darkest_secret;
	while (darkest_secret.empty())
	{
		std::cout << "Darkest secret: ";
		std::getline(std::cin, darkest_secret);
	}
	Contact newContact(first_name, last_name, nickname, phone_number, darkest_secret);
	contacts[index] = newContact;
	index = (index + 1) % 8;
}

std::string	format_detail(std::string detail)
{
	if (detail.length() > 10)
		return detail.substr(0,9) + ".";
	else
		return std::string(10 - detail.length(), ' ') + detail;
}

std::string intToString(int value)
{
	char buffer[50];
	std::sprintf(buffer, "%d", value);
	return std::string(buffer);
}

void	PhoneBook::SEARCH()
{
	int i;
	if (contacts[0].getFirstName().empty())
	{
		std::cout << "No contact" << std::endl;
		return ;
	}
	std::cout << std::setw(11);
	std::cout << "index|";
	std::cout << std::setw(11);
	std::cout << "first_name|";
	std::cout << std::setw(11);
	std::cout << "last_name|";
	std::cout << std::setw(10);
	std::cout << "nickname" << std::endl;
	for (i = 0; i < 8 && !contacts[i].getFirstName().empty(); i++)
	{
		std::string index = intToString(i) + "|";
		std::string first_name = format_detail(contacts[i].getFirstName()) + "|";
		std::string last_name = format_detail(contacts[i].getLastName()) + "|";
		std::string nickname = format_detail(contacts[i].getNickname());
		std::cout << std::setw(11);
		std::cout << index;
		std::cout << std::setw(11);
		std::cout << first_name;
		std::cout << std::setw(11);
		std::cout << last_name;
		std::cout << std::setw(10);
		std::cout << nickname << std::endl;
	}
	std::cout << "Enter the concat index to get details: ";
	std::string selected;
	std::getline(std::cin, selected);
	try
	{
		int selectedIndex = std::atoi(selected.c_str());
		if (ft_isnum(selected) && 0 <= selectedIndex && selectedIndex < i)
			contacts[selectedIndex].display_details();
		else
			std::cout <<"Contact not found." << std::endl;
	}
	catch (const std::invalid_argument& e)
	{
		std::cout << "Bad entry, input is not an integer." << std::endl;
	}
	catch (const std::out_of_range& e)
	{
		std::cout << "Bad entry, input is out of range." << std::endl;
	}
}