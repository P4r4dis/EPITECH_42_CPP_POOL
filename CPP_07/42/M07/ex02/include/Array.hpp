/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Array.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Paradis <adil.d.pro@gmail.com>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/29 19:31:46 by Paradis           #+#    #+#             */
/*   Updated: 2025/09/08 20:35:48 by Paradis          ###   ########.fr       */
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
        Array(unsigned int n);
        // Array(const Array &copy);
        // Array           &operator=(const Array &copy);
        virtual ~Array(void);

        unsigned int    size(void) const;
        T               operator[](unsigned int idx);

    private:
        const T         *_array;
        unsigned int    _n;
};

template <typename T>
Array<T>::Array(void)  :    _n(0)
{
    _array = new T[_n];
}

template <typename T>
Array<T>::Array(unsigned int n)  :  _n(n)
{
    _array = new T[_n] {};
}

template <typename T>
Array<T>::~Array(void)
{
    if (_array)
        delete [] _array;
}

template <typename T>
unsigned int            Array<T>::size(void) const
{
    return _n;
}

template <typename T>
T                        Array<T>::operator[](unsigned int idx)
{
    return _array[idx];
}

#endif //               !_ARRAY_HPP__