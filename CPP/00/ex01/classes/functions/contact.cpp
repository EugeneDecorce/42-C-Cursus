/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   contact.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edecorce <edecorce@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/26 17:09:18 by edecorce          #+#    #+#             */
/*   Updated: 2024/06/26 17:27:37 by edecorce         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/contact.hpp"

std::string Contact::getFirstName() const {return first_name; }
std::string Contact::getLastName() const {return last_name; }
std::string Contact::getNickname() const {return nickname; }
std::string Contact::getPhoneNumber() const {return phone_number; }
std::string Contact::getDarkestSecret() const {return darkest_secret; }