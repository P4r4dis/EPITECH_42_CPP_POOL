/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Paradis <adil.d.pro@gmail.com>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/20 17:10:03 by Paradis           #+#    #+#             */
/*   Updated: 2025/02/21 19:40:47 by Paradis          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef                 __FIXED_HPP__
    #define             __FIXED_HPP__

    #include <ostream>
class               Fixed
    {
        public:
            Fixed(void); // Default constructor -> Canonical
            Fixed(const int intValue); // Custom CTOR
            Fixed(const float floatValue); // Custom CTOR
            Fixed(const Fixed &src); // Copy constructor -> Canonical
            virtual ~Fixed(void); // Virtaul Destructor -> Canonical
            
            Fixed               &operator=(const Fixed &src); // Assignation operator -> Canonical
            
            Fixed               operator+(const Fixed &rhs) const;
            Fixed               operator-(const Fixed &rhs) const;
            Fixed               operator*(const Fixed &rhs) const;
            Fixed               operator/(const Fixed &rhs) const;

            bool                operator>(const Fixed &rhs) const;
            bool                operator>=(const Fixed &rhs) const;
            bool                operator<(const Fixed &rhs) const;
            bool                operator<=(const Fixed &rhs) const;
            bool                operator==(const Fixed &rhs) const;
            bool                operator!=(const Fixed &rhs) const;

            Fixed               &operator++(void);
            Fixed               operator++(int);
            Fixed               &operator--(void);
            Fixed               operator--(int);

            static Fixed        &min(Fixed &fixedPointvalue1,
                                    Fixed &fixedPointvalue2);
            static const Fixed  &min(const Fixed &fixedPointvalue1,
                                    const Fixed &fixedPointvalue2);
            static Fixed        &max(Fixed &fixedPointvalue1,
                                    Fixed &fixedPointvalue2);
            static const Fixed  &max(const Fixed &fixedPointvalue1,
                                    const Fixed &fixedPointvalue2);
            int                 getRawBits(void) const;
            static int          getFractionalBits(void);
            void                setRawBits(int const raw);

            float               toFloat(void) const;
            int                 toInt(void) const;

        private:
            int                 _fixedPointValue;
            static const int    _fractionalBits;
    };
#endif //               !_FIXED_HPP__
std::ostream                    &operator<<(std::ostream &os,
                                            Fixed const &rhs);