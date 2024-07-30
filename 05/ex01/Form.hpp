/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edecorce <edecorce@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/15 19:47:47 by edecorce          #+#    #+#             */
/*   Updated: 2024/07/24 18:09:25 by edecorce         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef Form_HPP
# define Form_HPP

# include "Bureaucrat.hpp"

class Bureaucrat;

class Form
{
	private:
		const std::string	_name;
		bool				_issigned;
		const int			_gradesign;
		const int			_gradeexec;

	public:
		Form(std::string name, const int gradesign);
		Form(const Form &copy);
		Form();
		~Form();
		Form &operator=(const Form &other);
		std::string	getName(void) const;
		bool		getIssigned(void) const;
		int			getGradesign(void) const;
		int			getGradeexec(void) const;
		void		beSigned(Bureaucrat &bureaucrat);
		class		GradeTooHighException : public std::exception {
			public:
				virtual const char *what() const throw();
		};
		class		GradeTooLowException : public std::exception {
			public:
				virtual const char *what() const throw();
		};
};

std::ostream	&operator<<(std::ostream &out, const Form &Form);

#endif
