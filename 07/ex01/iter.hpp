/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   iter.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edecorce <edecorce@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/01 19:34:25 by edecorce          #+#    #+#             */
/*   Updated: 2024/08/01 19:43:55 by edecorce         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ITER_HPP
# define ITER_HPP

# include <iostream>

template <typename T, typename F>
void iter(T* array, size_t length, F func) {
	for (size_t i = 0; i < length; ++i) {
		func(array[i]);
	}
}

#endif