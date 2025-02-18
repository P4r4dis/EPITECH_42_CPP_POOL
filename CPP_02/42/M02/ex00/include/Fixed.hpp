/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Paradis <adil.d.pro@gmail.com>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/18 20:01:46 by Paradis           #+#    #+#             */
/*   Updated: 2025/02/18 22:05:24 by Paradis          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef                 __FIXED_HPP__
    #define             __FIXED_HPP__

    class               Fixed
    {
        public:
            Fixed(void); // Default constructor -> Canonical
            Fixed(const Fixed &src); // Copy constructor -> Canonical
            virtual ~Fixed(void); // Virtaul Destructor -> Canonical

            Fixed               &operator=(const Fixed &src); // Assignation operator -> Canonical

            int                 getRawBits(void) const;
            static int          getFractionalBits(void);
            void                setRawBits(int const raw);

        private:
            int                 _fixedPointValue;
            static const int    _fractionalBits;
    };
#endif //               !_FIXED_HPP__