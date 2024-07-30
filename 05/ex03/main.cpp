/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edecorce <edecorce@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/24 15:22:04 by edecorce          #+#    #+#             */
/*   Updated: 2024/07/30 20:00:21 by edecorce         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"
#include "Intern.hpp"

static void testForm(Bureaucrat& bur, AForm* form)
{
	std::cout << std::endl << "Sign & Execute \033[33m" << form->getName() << "\033[0m : " << std::endl;
	bur.signForm(*form);
	bur.executeForm(*form);
}

static void testIntern(Intern& intern, const std::string &form_name, const std::string &target_name)
{
	Bureaucrat sign("Bob", 1);
	AForm *totest = NULL;
	std::cout << std::endl;
	totest = intern.makeForm(form_name, target_name);
	if (totest)
	{
		testForm(sign, totest);
		delete totest;
	}
}

int	main()
{
	Intern someRandomIntern;
	testIntern(someRandomIntern, "presidential pardon", "Michelon");
	testIntern(someRandomIntern, "robotomy request", "Bender");
	testIntern(someRandomIntern, "shrubbery creation", "Maison");
	testIntern(someRandomIntern, "doesn't exist", "NOP");
	return (0);
}