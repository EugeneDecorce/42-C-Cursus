/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edecorce <edecorce@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/01 13:49:52 by edecorce          #+#    #+#             */
/*   Updated: 2024/08/01 14:57:38 by edecorce         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScalarConverter.hpp"

int	main(int argc, char **argv) {
	if (argc == 2)
		ScalarConverter::convert(argv[1]);
	else
		std::cout << "Incorrect program use: ./convert <value_to_convert>" << std::endl;
	return 0;
}