/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Paradis <adil.d.pro@gmail.com>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/09 19:53:52 by Paradis           #+#    #+#             */
/*   Updated: 2025/07/09 20:04:06 by Paradis          ###   ########.fr       */
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
        ScalarConverter(void) = delete;
        ScalarConverter(const ScalarConverter &obj) = delete;
        ScalarConverter &operator=(const ScalarConverter &rhs) = delete;
        virtual ~ScalarConverter(void);

};
#endif //               !_SCALARCONVERTER_HPP__