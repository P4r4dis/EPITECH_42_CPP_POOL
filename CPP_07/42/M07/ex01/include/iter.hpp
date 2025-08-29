/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   iter.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Paradis <adil.d.pro@gmail.com>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/29 18:29:40 by Paradis           #+#    #+#             */
/*   Updated: 2025/08/29 19:25:38 by Paradis          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef                 __ITER_HPP__
#define                 __ITER_HPP__

#include <iostream>

template <typename T>
void    iter(const T *addrArray, size_t length, void (*function) (const T &))
{
    if (!addrArray || !length)
        std::cout << "Error" << std::endl;

    for (size_t i = 0; i < length; ++i)
        function(addrArray[i]);
}
#endif //               !_ITER_HPP__