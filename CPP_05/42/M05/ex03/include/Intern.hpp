/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Intern.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Paradis <adil.d.pro@gmail.com>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/18 17:21:34 by Paradis           #+#    #+#             */
/*   Updated: 2025/06/18 17:27:18 by Paradis          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef                 __INTERN_HPP__
#define                 __INTERN_HPP__

#include "AForm.hpp"
class                   Intern
{
    public:
        Intern(void);
        Intern(const Intern &obj);
        Intern          &operator=(const Intern &obj);
        virtual ~Intern(void);

        AForm           *makeForm(const std::string &nameForm,
                                const std::string &target);
};
#endif //               !_INTERN_HPP__