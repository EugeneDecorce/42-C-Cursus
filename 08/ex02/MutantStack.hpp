/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MutantStack.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edecorce <edecorce@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/05 14:19:02 by edecorce          #+#    #+#             */
/*   Updated: 2024/08/05 14:20:48 by edecorce         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MUTANTSTACK_HPP
# define MUTANTSTACK_HPP

# include <iostream>
# include <stack>
# include <deque>
# include <iterator>

template<typename T, typename Container = std::deque<T> >
class MutantStack : public std::stack<T, Container> {
public:
	// Typedefs for iterators
	typedef typename Container::iterator iterator;
	typedef typename Container::const_iterator const_iterator;
	typedef typename Container::reverse_iterator reverse_iterator;
	typedef typename Container::const_reverse_iterator const_reverse_iterator;

	// Constructors
	MutantStack() : std::stack<T, Container>() {}
	MutantStack(const MutantStack &other) : std::stack<T, Container>(other) {}
	MutantStack &operator=(const MutantStack &other) {
		if (this != &other) {
			std::stack<T, Container>::operator=(other);
		}
		return *this;
	}
	~MutantStack() {}

	// Iterator functions
	iterator begin() { return this->c.begin(); }
	iterator end() { return this->c.end(); }

	const_iterator begin() const { return this->c.begin(); }
	const_iterator end() const { return this->c.end(); }

	reverse_iterator rbegin() { return this->c.rbegin(); }
	reverse_iterator rend() { return this->c.rend(); }

	const_reverse_iterator rbegin() const { return this->c.rbegin(); }
	const_reverse_iterator rend() const { return this->c.rend(); }
};

#endif
