/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edecorce <edecorce@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/28 11:07:29 by edecorce          #+#    #+#             */
/*   Updated: 2024/06/28 12:34:25 by edecorce         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <fstream>
#include <sstream>
#include <string>

int	is_occ(std::string line, std::string subset1, int index)
{
	for (int i = 0; index + i < int(line.length()) && i < int(subset1.length()); i++)
	{
		if (line[index + i] != subset1[i])
			return (0);
	}
	return (1);
}

int	main(int argc, char **argv)
{
	if (argc == 4)
	{
		std::ifstream	file(argv[1]);
		std::stringstream		buffer;

		if (file) {
			std::ofstream	newfile(std::string(argv[1]) + ".replace");

			if (newfile) {
				buffer << file.rdbuf();
				std::string content = buffer.str();
				for (int i = 0; content[i]; i++) {
					if (is_occ(content, argv[2], i)) {
						newfile << argv[3];
						i += strlen(argv[2]) - 1;
					}
					else {
						newfile << content[i];
					}
				}
				file.close();
				newfile.close();
			} else {
				std::cout << "unable to write in file.replace" << std::endl;
			}
		} else {
			std::cout << "unable to open file.txt" << std::endl;
		}
	}
	else
		std::cout << "incorrect paramters given" << std::endl;
	return (0);
}
