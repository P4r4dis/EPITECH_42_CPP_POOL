/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Point.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Paradis <adil.d.pro@gmail.com>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/24 19:17:03 by Paradis           #+#    #+#             */
/*   Updated: 2025/02/25 16:46:45 by Paradis          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef                 __POINT_HPP__
    #define             __POINT_HPP__

#include "Fixed.hpp"

class                   Point
{
    public:
        Point(void);
        Point(const Fixed x, const Fixed y);
        Point(const Point &copy);
        virtual ~Point(void);
        Point           &operator=(const Point &rhs);

        Fixed           getX(void) const;
        Fixed           getY(void) const;
    private:
        const Fixed     _x;
        const Fixed     _y;
};

#endif //               !_POINT_HPP__