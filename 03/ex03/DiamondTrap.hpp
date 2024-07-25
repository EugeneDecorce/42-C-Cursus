/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   DiamondTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edecorce <edecorce@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/17 10:49:22 by edecorce          #+#    #+#             */
/*   Updated: 2024/07/17 11:24:19 by edecorce         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#ifndef DiamondTrap_HPP
# define DiamondTrap_HPP

# include "ClapTrap.hpp"
# include "ScavTrap.hpp"
# include "FragTrap.hpp"

class DiamondTrap : public ScavTrap, public FragTrap
{
	private:
		std::string _name;
		
	public:
		DiamondTrap(std::string name);
		DiamondTrap(const DiamondTrap &other);
		DiamondTrap();
		~DiamondTrap();
		using ScavTrap::attack;
		void whoAmI(void);
};

#endif
