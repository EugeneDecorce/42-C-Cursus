/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edecorce <edecorce@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/24 15:22:04 by edecorce          #+#    #+#             */
/*   Updated: 2024/07/24 17:19:58 by edecorce         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"

int main()
{
	Bureaucrat a = Bureaucrat("a", 148);
	try {
		Bureaucrat b = Bureaucrat("b", -34);
	} catch (const Bureaucrat::GradeTooHighException &e) {
		std::cerr << "Caught an invalid_argument exception: " << e.what() << std::endl;
	}
	try {
		Bureaucrat c = Bureaucrat("c", 153);
	} catch (const Bureaucrat::GradeTooLowException &e) {
		std::cerr << "Caught an invalid_argument exception: " << e.what() << std::endl;
	}
	for (int i = 0; i < 5; i++)
	{
		try {
			a.decGrade();
		} catch (const Bureaucrat::GradeTooLowException &e) {
			std::cerr << "Caught an invalid_argument exception: " << e.what() << std::endl;
		}
	}
	for (int i = 0; i < 5; i++)
	{
		try {
			a.incGrade();
		} catch (const Bureaucrat::GradeTooHighException &e) {
			std::cerr << "Caught an invalid_argument exception: " << e.what() << std::endl;
		}
	}
	for (int i = 0; i < 5; i++)
	{
		try {
			a.decGrade();
		} catch (const Bureaucrat::GradeTooLowException &e) {
			std::cerr << "Caught an invalid_argument exception: " << e.what() << std::endl;
		}
	}
}