/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edecorce <edecorce@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/28 09:25:46 by edecorce          #+#    #+#             */
/*   Updated: 2024/06/28 09:41:06 by edecorce         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>

int main()
{
	std::string variable = "HI THIS IS BRAIN";
	std::string *stringPTR = &variable;
	std::string &stringREF = variable;

	std::cout << &variable << std::endl;
	std::cout << stringPTR << std::endl;
	std::cout << &stringREF << std::endl;

	std::cout << variable << std::endl;
	std::cout << *stringPTR << std::endl;
	std::cout << stringREF << std::endl;
}