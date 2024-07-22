/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   contact.hpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edecorce <edecorce@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/26 12:13:25 by edecorce          #+#    #+#             */
/*   Updated: 2024/06/26 17:39:14 by edecorce         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#ifndef CONTACT_HPP
# define CONTACT_HPP

# include <iostream>

class Contact {
	private:
		std::string first_name;
		std::string last_name;
		std::string nickname;
		std::string phone_number;
		std::string darkest_secret;

	public:
		Contact(std::string first_name, std::string last_name, std::string nickname,std::string phone_number, std::string darkest_secret) : first_name(first_name), last_name(last_name), nickname(nickname), phone_number(phone_number), darkest_secret(darkest_secret) {}
		Contact() : first_name(""), last_name(""), nickname(""), phone_number(""), darkest_secret("") {}
		std::string getFirstName() const;
		std::string getLastName() const;
		std::string getNickname() const;
		std::string getPhoneNumber() const;
		std::string getDarkestSecret() const;
		void	display_details()
		{
			std::cout << "-----Contact details-----" << std::endl;
			std::cout << "First name: " + first_name << std::endl;
			std::cout << "Last name: " + last_name << std::endl;
			std::cout << "Nickname: " + nickname << std::endl;
			std::cout << "Phone number: " + phone_number << std::endl;
			std::cout << "Darkest secret: " + darkest_secret << std::endl;
		}
		~Contact() {}
};

#endif