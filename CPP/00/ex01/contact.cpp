/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   contact.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edecorce <edecorce@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/26 17:09:18 by edecorce          #+#    #+#             */
/*   Updated: 2024/07/22 17:14:23 by edecorce         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "contact.hpp"

std::string Contact::getFirstName() const
{
	return first_name;
}

std::string Contact::getLastName() const
{
	return last_name;
}

std::string Contact::getNickname() const
{
	return nickname;
}

std::string Contact::getPhoneNumber() const
{
	return phone_number;
}

std::string Contact::getDarkestSecret() const
{
	return darkest_secret;
}

void	Contact::display_details()
{
	std::cout << "-----Contact details-----" << std::endl;
	std::cout << "First name: " + first_name << std::endl;
	std::cout << "Last name: " + last_name << std::endl;
	std::cout << "Nickname: " + nickname << std::endl;
	std::cout << "Phone number: " + phone_number << std::endl;
	std::cout << "Darkest secret: " + darkest_secret << std::endl;
}

Contact::Contact(std::string first_name, std::string last_name, std::string nickname,std::string phone_number, std::string darkest_secret) : first_name(first_name), last_name(last_name), nickname(nickname), phone_number(phone_number), darkest_secret(darkest_secret) {}

Contact::Contact() : first_name(""), last_name(""), nickname(""), phone_number(""), darkest_secret("") {}

Contact::~Contact() {}
