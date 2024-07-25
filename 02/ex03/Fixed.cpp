/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edecorce <edecorce@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/28 14:26:08 by edecorce          #+#    #+#             */
/*   Updated: 2024/07/24 13:55:13 by edecorce         ###   ########.fr       */
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

bool	Fixed::operator>(const Fixed &other) {
	std::cout << "Greater than operator called" << std::endl;
	return this->getRawBits() > other.getRawBits();
}

bool	Fixed::operator<(const Fixed &other) {
	std::cout << "Less than operator called" << std::endl;
	return this->getRawBits() < other.getRawBits();
}

bool	Fixed::operator>=(const Fixed &other) {
	std::cout << "Greater or equal than operator called" << std::endl;
	return this->getRawBits() >= other.getRawBits();
}

bool	Fixed::operator<=(const Fixed &other) {
	std::cout << "Less or equal than operator called" << std::endl;
	return this->getRawBits() <= other.getRawBits();
}

bool	Fixed::operator==(const Fixed &other) {
	std::cout << "Equal operator called" << std::endl;
	return this->getRawBits() == other.getRawBits();
}

bool	Fixed::operator!=(const Fixed &other) {
	std::cout << "Not equal operator called" << std::endl;
	return this->getRawBits() != other.getRawBits();
}

Fixed	Fixed::operator+(const Fixed &other) const {
	std::cout << "Addition operator called" << std::endl;
	return Fixed(this->toFloat() + other.toFloat());
}

Fixed	Fixed::operator-(const Fixed &other) const {
	std::cout << "Substraction operator called" << std::endl;
	return Fixed(this->toFloat() - other.toFloat());
}

Fixed	Fixed::operator*(const Fixed &other) const {
	std::cout << "Multiplication operator called" << std::endl;
	return Fixed(this->toFloat() * other.toFloat());
}

Fixed	Fixed::operator/(const Fixed &other) const {
	std::cout << "Division operator called" << std::endl;
	if (other.toFloat() == 0)
	{
		std::cout << "Division by 0 impossible" << std::endl;
	}
		return *this;
	return Fixed(this->toFloat() / other.toFloat());
}

Fixed	&Fixed::operator++(void) {
	std::cout << "Pre increment comparison operator called" << std::endl;
	++this->_val;
	return *this;
}

Fixed	&Fixed::operator--(void) {
	std::cout << "Pre decrement comparison operator called" << std::endl;
	--this->_val;
	return *this;
}

Fixed	Fixed::operator++(int) {
	std::cout << "Post increment comparison operator called" << std::endl;
	Fixed	tmp = Fixed(*this);
	tmp._val = this->_val++;
	return tmp;
}

Fixed	Fixed::operator--(int) {
	std::cout << "Post decrement comparison operator called" << std::endl;
	Fixed	tmp = Fixed(*this);
	tmp._val = this->_val++;
	return tmp;
}


Fixed	&Fixed::min(Fixed &a, Fixed &b) {
	std::cout << "Min operator called" << std::endl;
	if (a.getRawBits() < b.getRawBits())
		return a;
	return b;
}

const Fixed	&Fixed::min(const Fixed &a, const Fixed &b) {
	std::cout << "Min operator called" << std::endl;
	if (a.getRawBits() < b.getRawBits())
		return a;
	return b;
}

Fixed	&Fixed::max(Fixed &a, Fixed &b) {
	std::cout << "Min operator called" << std::endl;
	if (a.getRawBits() > b.getRawBits())
		return a;
	return b;
}

const Fixed	&Fixed::max(const Fixed &a, const Fixed &b) {
	std::cout << "Min operator called" << std::endl;
	if (a.getRawBits() > b.getRawBits())
		return a;
	return b;
}
