/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Array.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Paradis <adil.d.pro@gmail.com>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/29 19:31:46 by Paradis           #+#    #+#             */
/*   Updated: 2025/08/29 21:22:14 by Paradis          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef                 __ARRAY_HPP__
#define                 __ARRAY_HPP__

#include <cstddef>

template <typename T>
class                    Array
{
    public:
        Array(void);
        // Array(unsigned int n);
        // Array(const Array &copy);
        // Array           &operator=(const Array &copy);
        virtual ~Array(void);

        unsigned int    size(void) const;
    private:
        const T         *_array;
        unsigned int    _n;
};

template <typename T>
unsigned int            Array<T>::size(void) const
{
    return _n;
}

template <typename T>
Array<T>::Array(void)  :    _array(nullptr), _n(0)
{
    _array = new T[_n];
}

template <typename T>

Array<T>::~Array(void)
{
    if (_array)
        delete [] _array;
}
#endif //               !_ARRAY_HPP__