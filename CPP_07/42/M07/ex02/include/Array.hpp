/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Array.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Paradis <adil.d.pro@gmail.com>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/29 19:31:46 by Paradis           #+#    #+#             */
/*   Updated: 2025/09/10 20:13:56 by Paradis          ###   ########.fr       */
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
        Array(const Array &copy);
        Array           &operator=(const Array &copy);
        virtual ~Array(void);

        unsigned int    size(void) const;
        T               &operator[](unsigned int idx);

    private:
        T               *_array;
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
Array<T>::Array(const Array &cpy)    :   _array(new T[cpy._n]), _n(cpy._n)
{
    if (this != &cpy)
    {
        for (unsigned int i = 0; i < _n; ++i)
            _array[i] = cpy._array[i];
    }
}

template <typename T>
Array<T>                       &Array<T>::operator=(const Array &cpy)
{
    if (this != &cpy)
    {
        delete [] _array;

        _n = cpy._n;
        _array = new T[_n];

        for (unsigned int i = 0; i < _n; ++i)
            _array[i] = cpy._array[i];
    }
    return *this;
}

template <typename T>
Array<T>::~Array(void)
{
    if (_array)
        delete [] _array;
}

template <typename T>
unsigned int                Array<T>::size(void) const
{
    return _n;
}

template <typename T>
T                           &Array<T>::operator[](unsigned int idx)
{
    return _array[idx];
}

#endif //               !_ARRAY_HPP__