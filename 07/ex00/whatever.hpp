/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   whatever.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edecorce <edecorce@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/01 19:34:25 by edecorce          #+#    #+#             */
/*   Updated: 2024/08/01 19:35:02 by edecorce         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WHATEVER_HPP
# define WHATEVER_HPP

# include <iostream>

template <typename T>
void swap(T& a, T& b) {
	T temp = a;
	a = b;
	b = temp;
}

template <typename T>
const T& min(const T& a, const T& b) {
	return (b < a) ? b : a;
}

template <typename T>
const T& max(const T& a, const T& b) {
	return (a < b) ? b : a;
}

#endif