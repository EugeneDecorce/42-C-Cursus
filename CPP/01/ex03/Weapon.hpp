/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Weapon.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edecorce <edecorce@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/28 10:01:01 by edecorce          #+#    #+#             */
/*   Updated: 2024/06/28 10:51:02 by edecorce         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WEAPON_HPP
# define WEAPON_HPP

# include <iostream>

class Weapon
{
	private:
		std::string _type;

	public:
		Weapon(std::string type);
		Weapon();
		~Weapon();
		std::string	getType();
		void		setType(std::string type);
};

#endif