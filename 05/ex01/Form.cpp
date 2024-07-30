/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edecorce <edecorce@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/15 19:47:24 by edecorce          #+#    #+#             */
/*   Updated: 2024/07/24 18:12:48 by edecorce         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Form.hpp"

Form::Form() : _name("default_name"), _issigned(false), _gradesign(10), _gradeexec(0) {
	if (_gradesign < 1)
		throw Form::GradeTooHighException();
	else if (_gradesign > 150)
		throw Form::GradeTooLowException();
	std::cout << "Default Form constructor called" << std::endl;
}

Form::Form(std::string name, const int gradesign) : _name(name), _issigned(false), _gradesign(gradesign), _gradeexec(0) {
	std::cout << "Form constructor called" << std::endl;
}

Form::Form(const Form &other) : _gradesign(other.getGradesign()), _gradeexec(other.getGradeexec()) {
	std::cout << "Form copy constructor called" << std::endl;
	*this = other;
}

Form::~Form() {
	std::cout << "Form deconstructor called" << std::endl;
}

Form &Form::operator=(const Form &other)
{
	std::cout << "Form assignment operator called" << std::endl;
	if (this != &other)
		this->_issigned = other._issigned;
	return *this;
}

std::string	Form::getName(void) const {
	return this->_name;
}

bool	Form::getIssigned(void) const {
	return this->_issigned;
}

int	Form::getGradesign(void) const {
	return this->_gradesign;
}

int	Form::getGradeexec(void) const {
	return this->_gradeexec;
}

void	Form::beSigned(Bureaucrat &bureaucrat) {
	if (bureaucrat.getGrade() <= this->_gradesign)
	{
		bureaucrat.signForm(*this);
		this->_issigned = true;
	}
	else
	{
		bureaucrat.signForm(*this);
		throw Form::GradeTooLowException();
		this->_issigned = false;
	}
}

std::ostream	&operator<<(std::ostream &out, const Form &Form) {
	out << Form.getName() << ", Form issigned: " << Form.getIssigned() << ", Form gradesign: " << Form.getGradesign() << ", Form gradeexec: " << Form.getGradeexec();
	return out;
}

const char *Form::GradeTooLowException::what(void) const throw()
{
	return ("Grade cannot be greater than 150");
};

const char *Form::GradeTooHighException::what(void) const throw()
{
	return ("Grade cannot be less than 1");
};