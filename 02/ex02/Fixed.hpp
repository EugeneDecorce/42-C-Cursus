/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edecorce <edecorce@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/28 14:21:04 by edecorce          #+#    #+#             */
/*   Updated: 2024/07/15 19:33:20 by edecorce         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef Fixed_HPP
# define Fixed_HPP

# include <iostream>
# include <cmath>

class Fixed
{
	private:
		int					_val;
		static const int	_rawbits = 8;

	public:
		Fixed(int const raw);
		Fixed(float const raw);
		Fixed();
		Fixed(const Fixed &other);
		~Fixed();
		int					getRawBits(void) const;
		void				setRawBits(int const raw);
		float				toFloat( void ) const;
		int					toInt( void ) const;
		Fixed				&operator=(const Fixed &other);
		bool				operator>(const Fixed &other);
		bool				operator<(const Fixed &other);
		bool				operator>=(const Fixed &other);
		bool				operator<=(const Fixed &other);
		bool				operator==(const Fixed &other);
		bool				operator!=(const Fixed &other);
		Fixed				operator+(const Fixed &other) const;
		Fixed				operator-(const Fixed &other) const;
		Fixed				operator*(const Fixed &other) const;
		Fixed				operator/(const Fixed &other) const;
		Fixed				&operator++(void);
		Fixed				&operator--(void);
		Fixed				operator++(int);
		Fixed				operator--(int);
		static Fixed		&min(Fixed &a, Fixed &b);
		static Fixed		&max(Fixed &a, Fixed &b);
		static const Fixed	&min(const Fixed &a, const Fixed &b);
		static const Fixed	&max(const Fixed &a, const Fixed &b);
};

std::ostream	&operator<<(std::ostream &out, const Fixed &fixed);

#endif
