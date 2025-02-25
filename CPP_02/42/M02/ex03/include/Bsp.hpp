/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bsp.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Paradis <adil.d.pro@gmail.com>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/25 16:45:52 by Paradis           #+#    #+#             */
/*   Updated: 2025/02/25 16:47:11 by Paradis          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef                 __BSP_HPP__
    #define             __BSP_HPP__
    #include "Point.hpp"

    Fixed   area(Point const a, Point const b, Point const c);
    bool    bsp(Point const a, Point const b, Point const c, Point const point);

#endif //               !_BSP_HPP__