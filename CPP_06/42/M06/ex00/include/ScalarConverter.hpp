/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Paradis <adil.d.pro@gmail.com>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/09 19:53:52 by Paradis           #+#    #+#             */
/*   Updated: 2025/07/23 18:13:17 by Paradis          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef                 __SCALARCONVERTER_HPP__
#define                 __SCALARCONVERTER_HPP__

#include <string>
class                   ScalarConverter
{
    public:
        static void     convert(const std::string &str);
    private:
        ScalarConverter(void) {};
        ScalarConverter(const ScalarConverter &obj) {
            static_cast<void>(obj);
        };
        ScalarConverter &operator=(const ScalarConverter &rhs) {
            static_cast<void>(rhs);
            return *this;
        };
        virtual ~ScalarConverter(void) {};

};
#endif //               !_SCALARCONVERTER_HPP__