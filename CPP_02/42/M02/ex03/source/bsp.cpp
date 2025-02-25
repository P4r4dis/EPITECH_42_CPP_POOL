/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bsp.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Paradis <adil.d.pro@gmail.com>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/24 21:33:49 by Paradis           #+#    #+#             */
/*   Updated: 2025/02/25 19:54:57 by Paradis          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include//Point.hpp"
#include <cmath>

Fixed   abs(Fixed const value)
{
    return (value < 0) ? (value * -1) : value;
}

Fixed   area(Point const a, Point const b, Point const c)
{
    Fixed constant(0.5f);

    return abs((constant * ((a.getX() * (b.getY() - c.getY()))
                                + (b.getX() * (c.getY() - a.getY()))
                                + (c.getX() * (a.getY() - b.getY())))));
}
bool    bsp(Point const a, Point const b, Point const c, Point const point)
{
    Fixed areaTotal = area(a, b, c);
    Fixed areaPointABP = area(a, b, point);
    Fixed areaPointACP = area(a, c, point);
    Fixed areaPointBCP = area(b, c, point);

    if (areaTotal == Fixed(0)) 
        return false;
    
    bool subTriangle_EQ_totalTriangle = (areaTotal ==   roundf(
                                                        areaPointABP.toFloat() +
                                                        areaPointACP.toFloat() +
                                                        areaPointBCP.toFloat()));
    bool area_not_eq_zero = areaPointABP != 0 &&
                            areaPointACP != 0 &&
                            areaPointBCP != 0;
                            
    return (subTriangle_EQ_totalTriangle && area_not_eq_zero);
}



