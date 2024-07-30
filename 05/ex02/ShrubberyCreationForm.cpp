/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ShrubberyCreationForm.cpp                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edecorce <edecorce@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/15 19:47:24 by edecorce          #+#    #+#             */
/*   Updated: 2024/07/30 19:32:33 by edecorce         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ShrubberyCreationForm.hpp"

ShrubberyCreationForm::ShrubberyCreationForm() : AForm("ShrubberyCreationForm", 145, 137), _target("default target") {
	std::cout << "ShrubberyCreationForm constructor called" << std::endl;
}

ShrubberyCreationForm::ShrubberyCreationForm(std::string target) : AForm("ShrubberyCreationForm", 145, 137), _target(target) {
	std::cout << "ShrubberyCreationForm constructor called" << std::endl;
}

ShrubberyCreationForm::ShrubberyCreationForm(const ShrubberyCreationForm &other) : AForm(other), _target(other._target) {
	std::cout << "ShrubberyCreationForm copy constructor called" << std::endl;
}

ShrubberyCreationForm::~ShrubberyCreationForm() {
	std::cout << "ShrubberyCreationForm deconstructor called" << std::endl;
}

std::string ShrubberyCreationForm::getTarget() const
{
	return this->_target;
}

ShrubberyCreationForm &ShrubberyCreationForm::operator=(const ShrubberyCreationForm &other)
{
	std::cout << "ShrubberyCreationForm assignment operator called" << std::endl;
	if (this == &other)
		return *this;
	AForm::operator=(other);
	return *this;
}

void	ShrubberyCreationForm::beExecuted() const
{
	std::ofstream file;

	file.open(std::string(this->getTarget() + "_shrubbery").c_str(),
		std::ios::out | std::ios::app);
	if(file.is_open())
	{
		file << "                 # #### ####			" << std::endl;
		file << "               ### \\/#|### |/####		" << std::endl;
		file << "              ##\\/#/ \\||/##/_/##/_#	" << std::endl;
		file << "            ###  \\/###|/ \\/ # ###	" << std::endl;
		file << "          ##_\\_#\\_\\## | #/###_/_####" << std::endl;
		file << "         ## #### # \\ #| /  #### ##/##	" << std::endl;
		file << "          __#_--###`  |{,###---###-~	" << std::endl;
		file << "                    \\ }{				" << std::endl;
		file << "                     }}{				" << std::endl;
		file << "                     }}{				" << std::endl;
		file << "                     {{}				" << std::endl;
		file << "               , -=-~{ .-^- _			" << std::endl;
		file << "                     `}				" << std::endl;
		file << "                      {				" << std::endl;
		file.close();
	}
}
