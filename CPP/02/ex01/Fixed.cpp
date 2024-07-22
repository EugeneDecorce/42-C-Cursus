/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edecorce <edecorce@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/28 14:26:08 by edecorce          #+#    #+#             */
/*   Updated: 2024/06/28 17:21:38 by edecorce         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"

Fixed::Fixed() : _val(0) {
	std::cout << "Default constructor called" << std::endl;
}

Fixed::Fixed(int const raw) : _val(raw << _rawbits) {
	std::cout << "Int constructor called" << std::endl;
}

Fixed::Fixed(float const raw) : _val(roundf(raw * (1 << _rawbits))) {
	std::cout << "Float constructor called" << std::endl;
}

Fixed::Fixed(const Fixed &other) {
	std::cout << "Copy constructor called" << std::endl;
	*this = other;
}

Fixed	&Fixed::operator=(const Fixed &other) {
	std::cout << "Copy assignment operator called" << std::endl;
	if (this != &other)
		this->_val = other._val;
	return *this;
}

Fixed::~Fixed() {
	std::cout << "Destructor called" << std::endl;
}

int	Fixed::getRawBits(void) const {
	std::cout << "getRawBits member function called" << std::endl;
	return this->_val;
}

void	Fixed::setRawBits(int const raw) {
	this->_val = raw;
}

float	Fixed::toFloat(void) const {
	return ((float)this->_val / (float)(1 << this->_rawbits));
}

int		Fixed::toInt(void) const {
	return (this->_val >> _rawbits);
}

std::ostream	&operator<<(std::ostream &out, const Fixed &fixed) {
	out << fixed.toFloat();
	return out;
}