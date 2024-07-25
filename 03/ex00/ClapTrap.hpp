/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edecorce <edecorce@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/15 19:47:47 by edecorce          #+#    #+#             */
/*   Updated: 2024/07/17 10:11:19 by edecorce         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ClapTrap_HPP
# define ClapTrap_HPP

# include <iostream>
# include <cmath>

class ClapTrap
{
	private:
		std::string		_name;
		unsigned int	_hit_points;
		unsigned int	_energy_points;
		unsigned int	_attack_damage;

	public:
		ClapTrap(std::string name);
		ClapTrap(const ClapTrap &copy);
		ClapTrap();
		~ClapTrap();
		ClapTrap &operator=(const ClapTrap &other);
		std::string	getName(void) const;
		void		attack(const std::string &target);
		void		takeDamage(unsigned int amount);
		void		beRepaired(unsigned int amount);
};

#endif
