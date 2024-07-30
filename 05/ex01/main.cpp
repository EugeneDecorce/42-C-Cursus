/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edecorce <edecorce@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/24 15:22:04 by edecorce          #+#    #+#             */
/*   Updated: 2024/07/24 18:14:15 by edecorce         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"

int main()
{
	try {
		Bureaucrat bureaucrat("A",11);
		Form form("B", 10);
		bureaucrat.signForm(form);
		std::cout << form << std::endl;
	} catch (std::exception &e) {
		std::cout << e.what() << std::endl;
	}
}