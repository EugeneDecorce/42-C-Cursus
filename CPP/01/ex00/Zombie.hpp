/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edecorce <edecorce@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/28 07:36:56 by edecorce          #+#    #+#             */
/*   Updated: 2024/06/28 09:19:05 by edecorce         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ZOMBIE_HPP
# define ZOMBIE_HPP

# include <iostream>

class Zombie
{
	private:
		std::string _name;

	public:
		Zombie(std::string name);
		~Zombie();
		void	annouce(void);
};

Zombie	*newZombie(std::string name);
void	randomChump(std::string name);

#endif