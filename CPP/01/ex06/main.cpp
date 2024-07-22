/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edecorce <edecorce@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/28 13:57:21 by edecorce          #+#    #+#             */
/*   Updated: 2024/06/28 15:10:28 by edecorce         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Harl.hpp"

int main(int argc, char **argv)
{
	if (argc == 2) {
		Harl harl = Harl();
		harl.complain(argv[1]);
	}
	else {
		std::cout << "bad input" << std::endl;
	}
	return (0);
}