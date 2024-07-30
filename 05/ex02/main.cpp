/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edecorce <edecorce@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/24 15:22:04 by edecorce          #+#    #+#             */
/*   Updated: 2024/07/30 19:47:15 by edecorce         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"

static void testAForm(Bureaucrat* bur, AForm* form)
{
	std::cout << std::endl << "Sign & Execute \033[33m" << form->getName() << "\033[0m : " << std::endl;
	bur->signForm(*form);
	bur->executeForm(*form);
}


int main()
{
	ShrubberyCreationForm* shrub = new ShrubberyCreationForm("Patrick");
	RobotomyRequestForm* robot = new RobotomyRequestForm("Bob");
	PresidentialPardonForm* pardon = new PresidentialPardonForm("Pef");

	Bureaucrat* bob = new Bureaucrat("Bob", 120);
	Bureaucrat* james = new Bureaucrat("James", 33);
	Bureaucrat* meg = new Bureaucrat("Meg", 1);

	testAForm(bob, shrub);
	testAForm(james, robot);
	testAForm(meg, pardon);

	testAForm(bob, pardon);

	delete shrub;
	delete robot;
	delete pardon;
	delete bob;
	delete james;
	delete meg;
	return (0);
}