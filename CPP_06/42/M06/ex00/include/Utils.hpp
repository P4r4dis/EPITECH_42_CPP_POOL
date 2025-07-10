/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Utils.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Paradis <adil.d.pro@gmail.com>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/09 20:35:55 by Paradis           #+#    #+#             */
/*   Updated: 2025/07/10 19:59:03 by Paradis          ###   ########.fr       */
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
    private:
        Utils(void) = delete;
        Utils(const Utils &obj) = delete;
        Utils &operator=(const Utils &rhs) = delete;
        virtual ~Utils(void);

};
#endif //               !_Utils_HPP__