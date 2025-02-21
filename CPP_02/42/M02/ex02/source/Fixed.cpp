/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Paradis <adil.d.pro@gmail.com>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/20 17:10:17 by Paradis           #+#    #+#             */
/*   Updated: 2025/02/21 17:00:39 by Paradis          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include <cmath>
#include <iostream>
#include "../include/Fixed.hpp"

const int    Fixed::_fractionalBits = 8;

Fixed::Fixed(void)  : _fixedPointValue(0)
{
}

// int to fixed point value
Fixed::Fixed(const int intValue)  
            : _fixedPointValue(intValue << _fractionalBits)
{
}

// float to fixed point value
Fixed::Fixed(const float floatValue)
            : _fixedPointValue(roundf(floatValue * (1 << _fractionalBits)))
{
}

Fixed::Fixed(const Fixed &src)
{
    *this = src;
}
Fixed::~Fixed(void)
{
}

Fixed               &Fixed::operator=(const Fixed &src)
{
    if (this != &src)
        this->_fixedPointValue = src.getRawBits();

    return *this;
}

int     Fixed::getRawBits(void) const
{
    return _fixedPointValue;
}

void    Fixed::setRawBits(int const raw)
{
    _fixedPointValue = raw;
}

int     Fixed::getFractionalBits(void)
{
    return _fractionalBits;
}

// fixedPointValue to float
float   Fixed::toFloat(void) const
{
    return static_cast<float>(_fixedPointValue) / (1 << _fractionalBits);
}

// fixedPointValue to int
int     Fixed::toInt(void) const
{
    return _fixedPointValue >> _fractionalBits;
}

bool    Fixed::operator>(const Fixed &rhs) const
{
    return (_fixedPointValue > rhs._fixedPointValue);
}

bool    Fixed::operator>=(const Fixed &rhs) const
{
    return (_fixedPointValue >= rhs._fixedPointValue);
}

bool    Fixed::operator<(const Fixed &rhs) const
{
    return (_fixedPointValue < rhs._fixedPointValue);
}

bool    Fixed::operator<=(const Fixed &rhs) const
{
    return (_fixedPointValue <= rhs._fixedPointValue);
}

bool    Fixed::operator==(const Fixed &rhs) const
{
    return (_fixedPointValue == rhs._fixedPointValue);
}

bool    Fixed::operator!=(const Fixed &rhs) const
{
    return (_fixedPointValue != rhs._fixedPointValue);
}

Fixed    Fixed::operator+(const Fixed &rhs) const
{
    return Fixed(toFloat() + rhs.toFloat());
}

Fixed    Fixed::operator-(const Fixed &rhs) const
{
    return Fixed(toFloat() - rhs.toFloat());
}

Fixed    Fixed::operator*(const Fixed &rhs) const
{
    return Fixed(toFloat() * rhs.toFloat());
}

std::ostream    &operator<<(std::ostream &os, Fixed const &rhs)
{
    return os << rhs.toFloat();
}

