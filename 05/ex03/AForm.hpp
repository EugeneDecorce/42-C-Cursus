/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AForm.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edecorce <edecorce@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/15 19:47:47 by edecorce          #+#    #+#             */
/*   Updated: 2024/07/30 19:29:42 by edecorce         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef AForm_HPP
# define AForm_HPP

# include "Bureaucrat.hpp"

class Bureaucrat;

class AForm
{
	private:
		const std::string	_name;
		bool				_issigned;
		const int			_gradesign;
		const int			_gradeexec;
		virtual void		beExecuted() const;

	public:
		AForm(std::string name, const int gradesign, const int gradeexec);
		AForm(const AForm &copy);
		AForm();
		virtual ~AForm();
		AForm &operator=(const AForm &other);
		std::string	getName(void) const;
		virtual bool		getIssigned(void) const;
		virtual int			getGradesign(void) const;
		virtual int			getGradeexec(void) const;
		virtual void		beSigned(Bureaucrat &bureaucrat);
		class		GradeTooHighException : public std::exception {
			public:
				virtual const char *what() const throw();
		};
		class		GradeTooLowException : public std::exception {
			public:
				virtual const char *what() const throw();
		};
		class		GradeNotSignedException : public std::exception {
			public:
				virtual const char *what() const throw();
		};
		void	execute(Bureaucrat const & executor) const;
};

std::ostream	&operator<<(std::ostream &out, const AForm &AForm);

#endif
