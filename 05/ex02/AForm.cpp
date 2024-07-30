/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AForm.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edecorce <edecorce@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/15 19:47:24 by edecorce          #+#    #+#             */
/*   Updated: 2024/07/30 19:38:24 by edecorce         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AForm.hpp"

AForm::AForm() : _name("default_name"), _issigned(false), _gradesign(10), _gradeexec(0) {
	if (_gradesign < 1)
		throw AForm::GradeTooHighException();
	else if (_gradesign > 150)
		throw AForm::GradeTooLowException();
	std::cout << "Default AForm constructor called" << std::endl;
}

AForm::AForm(std::string name, const int gradesign, const int gradeexec) : _name(name), _issigned(false), _gradesign(gradesign), _gradeexec(gradeexec) {
	std::cout << "AForm constructor called" << std::endl;
}

AForm::AForm(const AForm &other) : _gradesign(other.getGradesign()), _gradeexec(other.getGradeexec()) {
	std::cout << "AForm copy constructor called" << std::endl;
	*this = other;
}

AForm::~AForm() {
	std::cout << "AForm deconstructor called" << std::endl;
}

AForm &AForm::operator=(const AForm &other)
{
	std::cout << "AForm assignment operator called" << std::endl;
	if (this != &other)
		this->_issigned = other._issigned;
	return *this;
}

std::string	AForm::getName(void) const {
	return this->_name;
}

bool	AForm::getIssigned(void) const {
	return this->_issigned;
}

int	AForm::getGradesign(void) const {
	return this->_gradesign;
}

int	AForm::getGradeexec(void) const {
	return this->_gradeexec;
}

void	AForm::beSigned(Bureaucrat &bureaucrat) {
	if (bureaucrat.getGrade() <= this->_gradesign)
	{
		bureaucrat.signForm(*this);
		this->_issigned = true;
	}
	else
	{
		bureaucrat.signForm(*this);
		throw AForm::GradeTooLowException();
		this->_issigned = false;
	}
}

std::ostream	&operator<<(std::ostream &out, const AForm &AForm) {
	out << AForm.getName() << ", AForm issigned: " << AForm.getIssigned() << ", AForm gradesign: " << AForm.getGradesign() << ", AForm gradeexec: " << AForm.getGradeexec();
	return out;
}

void	AForm::beExecuted() const {}

void	AForm::execute(Bureaucrat const & executor) const
{
	if (!this->_issigned)
		throw AForm::GradeNotSignedException();
	else if (executor.getGrade() > this->_gradeexec)
		throw Bureaucrat::GradeTooLowException();
	this->beExecuted();
}


const char *AForm::GradeTooLowException::what(void) const throw()
{
	return ("Grade cannot be greater than 150");
};

const char *AForm::GradeTooHighException::what(void) const throw()
{
	return ("Grade cannot be less than 1");
};

const char *AForm::GradeNotSignedException::what(void) const throw()
{
	return ("Grade is not signed");
};
