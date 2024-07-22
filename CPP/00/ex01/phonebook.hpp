/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   phonebook.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edecorce <edecorce@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/26 17:27:41 by edecorce          #+#    #+#             */
/*   Updated: 2024/07/22 09:29:22 by edecorce         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHONEBOOK_HPP
# define PHONEBOOK_HPP

# include "contact.hpp"

class PhoneBook {
	private:
		Contact contacts[8];
		int index;

	public:
		PhoneBook();
		void	ADD();
		void	SEARCH();
		~PhoneBook() {}
};

#endif