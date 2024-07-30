/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Intern.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edecorce <edecorce@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/15 19:47:24 by edecorce          #+#    #+#             */
/*   Updated: 2024/07/30 19:38:24 by edecorce         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Intern.hpp"

Intern::Intern() {
	std::cout << "Intern constructor called" << std::endl;
}

Intern::Intern(const Intern &other) {
	std::cout << "Intern copy constructor called" << std::endl;
	*this = other;
}

Intern::~Intern() {
	std::cout << "Intern deconstructor called" << std::endl;
}

Intern &Intern::operator=(const Intern &other)
{
	std::cout << "Intern assignment operator called" << std::endl;
	(void) other;
	return *this;
}

static AForm*	createPresidentialPardonForm(std::string const & target) { return (new PresidentialPardonForm(target)); }
static AForm*	createRobotomyRequestForm(std::string const & target) { return (new RobotomyRequestForm(target)); }
static AForm*	createShrubberyCreationForm(std::string const & target) { return (new ShrubberyCreationForm(target)); }

AForm* Intern::makeForm(std::string const& form_name, std::string const& target)
{
	struct FormType
	{
		std::string name;
		AForm* (*createFunc)(std::string const&);
	};
	FormType forms[] = 
	{
		{"presidential pardon", &createPresidentialPardonForm},
		{"robotomy request", &createRobotomyRequestForm},
		{"shrubbery creation", &createShrubberyCreationForm}
	};
	const int numForms = sizeof(forms) / sizeof(forms[0]);
	for (int i = 0; i < numForms; ++i)
	{
		if (forms[i].name == form_name)
		{
			AForm* rtn = forms[i].createFunc(target);
			std::cout << "Intern creates " << rtn->getName() << std::endl;
			return rtn;
		}
	}
	std::cout << "Intern is not able to create the form asked." << std::endl;
	return NULL;
}
