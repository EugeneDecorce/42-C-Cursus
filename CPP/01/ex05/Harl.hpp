/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Harl.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edecorce <edecorce@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/28 13:12:25 by edecorce          #+#    #+#             */
/*   Updated: 2024/06/28 15:09:38 by edecorce         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef Harl_HPP
# define Harl_HPP

# include <iostream>

class Harl
{
	public:
		Harl();
		~Harl();
		void	debug(void);
		void	info(void);
		void	warning(void);
		void	error(void);
		void	complain( std::string level );
};

#endif