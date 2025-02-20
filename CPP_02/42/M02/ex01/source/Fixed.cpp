/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Paradis <adil.d.pro@gmail.com>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/19 17:23:46 by Paradis           #+#    #+#             */
/*   Updated: 2025/02/20 00:08:04 by Paradis          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */



#include <cmath>
#include <iostream>
#include "../include/Fixed.hpp"

const int    Fixed::_fractionalBits = 8;

Fixed::Fixed(void)  : _fixedPointValue(0)
{
    std::cout << "Default constructor called" << std::endl;
}

// int to fixed point value
Fixed::Fixed(const int intValue)  
            : _fixedPointValue(intValue << _fractionalBits)
{
    std::cout << "Int constructor called"<< std::endl;
}

// float to fixed point value
Fixed::Fixed(const float floatValue)
            : _fixedPointValue(roundf(floatValue * (1<< _fractionalBits)))
{
    std::cout << "Float constructor called" << std::endl;
}

Fixed::Fixed(const Fixed &src)  : _fixedPointValue(src._fixedPointValue)
{
    std::cout << "Copy constructor called" << std::endl;
    *this = src;
    // _fixedPointValue = src.getRawBits();
}
Fixed::~Fixed(void)
{
    std::cout << "Destructor called" << std::endl;
}

Fixed               &Fixed::operator=(const Fixed &src)
{
    std::cout << "Copy assignment operator called" << std::endl;
    if (this != &src)
        this->_fixedPointValue = src.getRawBits();

    return *this;
}

int     Fixed::getRawBits(void) const
{
    std::cout << "getRawBits member function called" << std::endl;
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