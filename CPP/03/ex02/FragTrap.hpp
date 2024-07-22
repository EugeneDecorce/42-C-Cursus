/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   FragTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edecorce <edecorce@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/17 10:49:22 by edecorce          #+#    #+#             */
/*   Updated: 2024/07/17 11:37:06 by edecorce         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#ifndef FragTrap_HPP
# define FragTrap_HPP

# include "ClapTrap.hpp"

class FragTrap : public ClapTrap
{
	private:
		
	public:
		FragTrap(std::string name);
		FragTrap(const FragTrap &other);
		FragTrap();
		virtual ~FragTrap();
		FragTrap &operator=(const FragTrap &other);
		void		highFivesGuys(void);
};

#endif
