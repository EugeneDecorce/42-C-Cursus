/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Intern.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edecorce <edecorce@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/15 19:47:47 by edecorce          #+#    #+#             */
/*   Updated: 2024/07/30 19:57:30 by edecorce         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef Intern_HPP
# define Intern_HPP

# include "Bureaucrat.hpp"
# include "ShrubberyCreationForm.hpp"
# include "RobotomyRequestForm.hpp"
# include "PresidentialPardonForm.hpp"

class Bureaucrat;

class Intern
{
	private:

	public:
		Intern(const Intern &copy);
		Intern();
		virtual ~Intern();
		Intern &operator=(const Intern &other);

		AForm	*makeForm(std::string const & form_name, std::string const & target);

};

#endif
