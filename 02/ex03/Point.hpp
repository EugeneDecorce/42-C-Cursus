/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Point.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edecorce <edecorce@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/15 19:47:47 by edecorce          #+#    #+#             */
/*   Updated: 2024/07/17 11:24:35 by edecorce         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef Point_HPP
# define Point_HPP

# include "Fixed.hpp"

class Point
{
	private:
		const Fixed _x;
		const Fixed _y;

	public:
		Point();
		Point(const float x, const float y);
		Point(const Point &copy);
		~Point();
		Point &operator=(const Point &other);
		float getX(void) const;
		float getY(void) const;
};

bool bsp( Point const a, Point const b, Point const c, Point const point);

#endif
