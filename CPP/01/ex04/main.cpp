/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edecorce <edecorce@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/28 11:07:29 by edecorce          #+#    #+#             */
/*   Updated: 2024/07/22 11:28:41 by edecorce         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <cstring>

// int	is_occ(std::string line, std::string subset1, int index)
// {
// 	for (int i = 0; index + i < int(line.length()) && i < int(subset1.length()); i++)
// 	{
// 		if (line[index + i] != subset1[i])
// 			return (0);
// 	}
// 	return (1);
// }

void	replace(char **argv)
{
	std::ifstream	file(argv[1]);
	std::string line;
	std::string av1 = argv[2];
	std::string av2 = argv[3];

	if (file.is_open()) {
		std::string outfile_name = std::string(argv[1]) + ".replace";
		std::ofstream	newfile(outfile_name.c_str());

		if (!newfile.is_open()) {
			std::cout << "Unable to open " << outfile_name << std::endl;
			return;
		}
		while (getline(file, line)) {
			size_t	pos;
			while ((pos = line.find(av1)) != std::string::npos)
			{
				line.erase(pos, av1.length());
				line.insert(pos, av2);
			}
			if (!std::cin.eof())
				newfile << line << std::endl;
		}
	} else {
		std::cout << "unable to open " << argv[1] << std::endl;
	}
}

int	main(int argc, char **argv)
{
	if (argc == 4)
		replace(argv);
	else
		std::cout << "incorrect parameters given" << std::endl;
	return (0);
}
