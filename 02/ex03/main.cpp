/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edecorce <edecorce@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/24 11:02:43 by edecorce          #+#    #+#             */
/*   Updated: 2024/07/24 13:10:21 by edecorce         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Point.hpp"

int main()
{
	Point a = Point(0, 0);
	Point b = Point(1, 0);
	Point c = Point(0, 1);
	Point point = Point(1, 0);
	std::cout << "Not inside: " << bsp(a, b, c, point) << std::endl;

	a = Point(0, 0);
	b = Point(1, 0);
	c = Point(0, 1);
	point = Point(0.25, 0);
	std::cout << "Not inside: " << bsp(a, b, c, point) << std::endl;

	a = Point(0, 0);
	b = Point(1, 0);
	c = Point(0, 1);
	point = Point(0.25, 0.25);
	std::cout << "Inside: " << bsp(a, b, c, point) << std::endl;

	a = Point(0, 0);
	b = Point(1, 0);
	c = Point(0, 1);
	point = Point(0.1, 0.1);
	std::cout << "Inside: " << bsp(a, b, c, point) << std::endl;
}