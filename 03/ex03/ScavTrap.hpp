/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScavTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edecorce <edecorce@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/17 10:49:22 by edecorce          #+#    #+#             */
/*   Updated: 2024/07/24 13:46:58 by edecorce         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#ifndef ScavTrap_HPP
# define ScavTrap_HPP

# include "ClapTrap.hpp"

class ScavTrap : virtual public ClapTrap
{
	private:
		bool	_guard_gate;
		
	public:
		ScavTrap(std::string name);
		ScavTrap(const ScavTrap &other);
		ScavTrap();
		virtual ~ScavTrap();
		ScavTrap &operator=(const ScavTrap &other);
		void		attack(const std::string &target);
		void		guardGate(void);
};

#endif
