/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   phonebook.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edecorce <edecorce@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/26 12:05:24 by edecorce          #+#    #+#             */
/*   Updated: 2024/06/26 17:38:09 by edecorce         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/phonebook.hpp"
#include "../headers/contact.hpp"

PhoneBook::PhoneBook() : index(0)
{
	for (int i = 0; i < 8;  i++)
		contacts[i] = Contact();
}

void	PhoneBook::ADD()
{
	std::string first_name;
	std::cout << "First name: ";
	std::getline(std::cin, first_name);
	std::string last_name;
	std::cout << "Last name: ";
	std::getline(std::cin, last_name);
	std::string nickname;
	std::cout << "Nickname: ";
	std::getline(std::cin, nickname);
	std::string phone_number;
	std::cout << "Phone number: ";
	std::getline(std::cin, phone_number);
	std::string darkest_secret;
	std::cout << "Darkest secret: ";
	std::getline(std::cin, darkest_secret);
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

void	PhoneBook::SEARCH()
{
	int i;
	for (i = 0; !contacts[i].getFirstName().empty(); i++)
	{
		std::string index = "         " + std::to_string(i) + "|";
		std::string first_name = format_detail(contacts[i].getFirstName()) + "|";
		std::string last_name = format_detail(contacts[i].getLastName()) + "|";
		std::string nickname = format_detail(contacts[i].getNickname());
		std::cout << index + first_name + last_name + nickname <<std::endl;
	}
	std::cout << "Enter the concat index to get details: ";
	std::string selected;
	std::getline(std::cin, selected);
	try
	{
		int selectedIndex = std::stoi(selected);
		if (0 <= selectedIndex && selectedIndex < i)
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