/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   whatever.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Paradis <adil.d.pro@gmail.com>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/28 17:30:12 by Paradis           #+#    #+#             */
/*   Updated: 2025/08/28 17:54:37 by Paradis          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef                 __WHATEVER_HPP__
#define                 __WHATEVER_HPP__

template <typename T>
void    swap(T &a, T &b)
{
    const T tmp = a;

    a = b;
    b = tmp;
}

#endif //               !_WHATEVER_HPP__