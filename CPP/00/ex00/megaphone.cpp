/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   megaphone.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edecorce <edecorce@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/26 11:50:35 by edecorce          #+#    #+#             */
/*   Updated: 2024/06/26 11:55:13 by edecorce         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <string>
#include <cctype>

int main(int argc, char **argv)
{
	if (argc > 1)
		for (int j = 1; argv[j]; j++)
			for (int i = 0; argv[j][i]; i++)
				std::cout << static_cast<char>(std::toupper(argv[j][i]));
	return (0);
}