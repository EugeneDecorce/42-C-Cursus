/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edecorce <edecorce@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/15 19:47:24 by edecorce          #+#    #+#             */
/*   Updated: 2024/07/30 19:47:23 by edecorce         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"

Bureaucrat::Bureaucrat() : _name("default_name"), _grade(150) {
	std::cout << "Default Bureaucrat constructor called" << std::endl;
}

Bureaucrat::Bureaucrat(std::string name, int grade) : _name(name) {
	if (grade < 1 )
		throw Bureaucrat::GradeTooHighException();
	else if (grade > 150)
		throw Bureaucrat::GradeTooLowException();
	this->_grade = grade;
	std::cout << "Bureaucrat constructor called" << std::endl;
}

Bureaucrat::Bureaucrat(const Bureaucrat &other) 
{
	std::cout << "Bureaucrat copy constructor called" << std::endl;
	*this = other;
}

Bureaucrat::~Bureaucrat() {
	std::cout << "Bureaucrat deconstructor called" << std::endl;
}

Bureaucrat &Bureaucrat::operator=(const Bureaucrat &other)
{
	std::cout << "Bureaucrat assignment operator called" << std::endl;
	if (this != &other)
		this->_grade = other._grade;
	return *this;
}

std::string	Bureaucrat::getName(void) const {
	return this->_name;
}

int	Bureaucrat::getGrade(void) const {
	return this->_grade;
}

void Bureaucrat::incGrade(void) {
	if (this->_grade == 1)
		throw Bureaucrat::GradeTooHighException();
	std::cout << *this;
	this->_grade--;
	std::cout << " --incrementing--> " << *this << std::endl;
}

void Bureaucrat::decGrade(void) {

	if (this->_grade == 150)
		throw Bureaucrat::GradeTooLowException();
	std::cout << *this;
	this->_grade++;
	std::cout << " --decrementing--> " << *this << std::endl;
}

void Bureaucrat::signForm(AForm &AForm) {
	if (AForm.getIssigned())
		std::cout << this->getName() << " signed " << AForm.getName() << std::endl;
	else
		std::cout << this->getName() << " couldn't sign " << AForm.getName() << " because minimum grade is not met" << std::endl;
}

void	Bureaucrat::executeForm(AForm const & form)
{
	try
	{
		form.execute(*this);
		std::cout << this->_name << " executing " << form.getName() << std::endl;
	}
	catch (std::string & e)
	{
		std::cout << this->_name << " cannot execute form" << form.getName();
		std::cout << " because " << e << std::endl;
	}
}

std::ostream	&operator<<(std::ostream &out, const Bureaucrat &bureaucrat) {
	out << bureaucrat.getName() << ", bureaucrat grade " << bureaucrat.getGrade();
	return out;
}

const char *Bureaucrat::GradeTooLowException::what(void) const throw()
{
	return ("Grade cannot be greater than 150");
};

const char *Bureaucrat::GradeTooHighException::what(void) const throw()
{
	return ("Grade cannot be less than 1");
};