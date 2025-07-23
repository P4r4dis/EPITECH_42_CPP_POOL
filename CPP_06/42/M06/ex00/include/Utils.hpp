/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Utils.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Paradis <adil.d.pro@gmail.com>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/09 20:35:55 by Paradis           #+#    #+#             */
/*   Updated: 2025/07/23 18:13:51 by Paradis          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef                 __Utils_HPP__
#define                 __Utils_HPP__

#include <string>
class                   Utils
{
    public:
        static bool     isPseudoLiteral(const std::string &str);
        static bool     isChar(const std::string &str);
        static bool     isInt(const std::string &str);
        static bool     isFloat(const std::string &str);
        static bool     isDouble(const std::string &str);
        static bool     isPrintable(const std::string &str);
        static void     printChar(const std::string &str);
        static void     printInt(const std::string &str);
        static void     printFloat(const std::string &str);
        static void     printDouble(const std::string &str);
        static void     printLiteral(const std::string &str);
        static void     printLimits(const std::string &str);
        static void     convertToChar(const std::string &str);
    private:
        Utils(void) {};
        Utils(const Utils &obj) {
            static_cast<void>(obj);
        };
        Utils &operator=(const Utils &rhs) {
            static_cast<void>(rhs);
            return *this;
        };
        virtual ~Utils(void);

};
#endif //               !_Utils_HPP__