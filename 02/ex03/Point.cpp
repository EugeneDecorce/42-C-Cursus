/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Point.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edecorce <edecorce@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/24 13:05:27 by edecorce          #+#    #+#             */
/*   Updated: 2024/07/24 13:55:37 by edecorce         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Point.hpp"

Point::Point() : _x(0), _y(0) {
	std::cout << "Default Point constructor called" << std::endl;
}

Point::Point(const float x, const float y) : _x(x), _y(y) {
	std::cout << "Point constructor called" << std::endl;
}

Point::Point(const Point &other) 
{
	std::cout << "Point copy constructor called" << std::endl;
	*this = other;
}

Point::~Point() {
	std::cout << "Point deconstructor called" << std::endl;
}

Point &Point::operator=(const Point &other)
{
	if (this != &other)
	{
		std::cout << "Point assignment operator called" << std::endl;
		const_cast<Fixed&>(this->_x) = Fixed(other.getX());
		const_cast<Fixed&>(this->_y) = Fixed(other.getY());
	}
	return *this;
}

float Point::getX(void) const
{
	return this->_x.toFloat();
}

float Point::getY(void) const
{
	return this->_y.toFloat();
}


bool bsp(Point const a, Point const b, Point const c, Point const point)
{
	// Compute vectors
	Point v0 = Point(c.getX() - a.getX(), c.getY() - a.getY());
	Point v1 = Point(b.getX() - a.getX(), b.getY() - a.getY());
	Point v2 = Point(point.getX() - a.getX(), point.getY() - a.getY());

	// Compute dot products
	Fixed dot00 = Fixed(v0.getX()) * Fixed(v0.getX()) + Fixed(v0.getY()) * Fixed(v0.getY());
	Fixed dot01 = Fixed(v0.getX()) * Fixed(v1.getX()) + Fixed(v0.getY()) * Fixed(v1.getY());
	Fixed dot02 = Fixed(v0.getX()) * Fixed(v2.getX()) + Fixed(v0.getY()) * Fixed(v2.getY());
	Fixed dot11 = Fixed(v1.getX()) * Fixed(v1.getX()) + Fixed(v1.getY()) * Fixed(v1.getY());
	Fixed dot12 = Fixed(v1.getX()) * Fixed(v2.getX()) + Fixed(v1.getY()) * Fixed(v2.getY());

	// Compute barycentric coordinates
	Fixed invDenom = Fixed(1) / (dot00 * dot11 - dot01 * dot01);
	Fixed u = (dot11 * dot02 - dot01 * dot12) * invDenom;
	Fixed v = (dot00 * dot12 - dot01 * dot02) * invDenom;

	return (u > Fixed(0) && v > Fixed(0) && (u + v) < Fixed(1));
}

