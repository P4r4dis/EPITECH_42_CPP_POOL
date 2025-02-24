/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Point.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Paradis <adil.d.pro@gmail.com>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/24 19:44:56 by Paradis           #+#    #+#             */
/*   Updated: 2025/02/24 20:47:46 by Paradis          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/Point.hpp"

Point::Point(void)  :   _x(0), _y(0)
{}

Point::Point(const Fixed x, const Fixed y)  :   _x(x), _y(y)
{}

Point::Point(const Point &copy) :   _x(copy._x), _y(copy._y)
{
}

Point::~Point(void)
{}

Point   &Point::operator=(const Point &rhs)
{
    (void)rhs;
    
    return *this;
}

Fixed   Point::getX(void) const
{
    return _x;
}

Fixed   Point::getY(void) const
{
    return _y;
}