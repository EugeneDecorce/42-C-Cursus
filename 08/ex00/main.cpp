/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edecorce <edecorce@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/05 12:30:19 by edecorce          #+#    #+#             */
/*   Updated: 2024/08/05 12:31:21 by edecorce         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <vector>
#include "easyfind.hpp"

int main() {
	int arr[] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
	std::vector<int> vec(arr, arr + sizeof(arr) / sizeof(int));

	try {
		std::vector<int>::iterator it = easyfind(vec, 1);
		std::cout << "Element found: " << *it << std::endl;
	} catch (const NotFoundException& e) {
		std::cerr << e.what() << std::endl;
	}
	try {
		std::vector<int>::iterator it = easyfind(vec, 11);
		std::cout << "Element found: " << *it << std::endl;
	} catch (const NotFoundException& e) {
		std::cerr << e.what() << std::endl;
	}

	return 0;
}
