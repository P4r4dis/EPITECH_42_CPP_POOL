/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ShrubberyCreationForm.hpp                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Paradis <adil.d.pro@gmail.com>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/17 15:59:30 by Paradis           #+#    #+#             */
/*   Updated: 2025/06/17 18:36:58 by Paradis          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef                 __SHRUBBERYCREATIONFORM_HPP__
#define                 __SHRUBBERYCREATIONFORM_HPP__

#include "AForm.hpp"
#include <string>

#define GRADE_TO_SIGN   145
#define GRADE_TO_EXEC   137

class                   ShrubberyCreationForm    :   public AForm
{
    public:
        ShrubberyCreationForm(const std::string &target);
        ShrubberyCreationForm(const ShrubberyCreationForm &obj);
        ShrubberyCreationForm   &operator=(const ShrubberyCreationForm& rhs);
        virtual ~ShrubberyCreationForm(void);

        std::string             getTarget(void) const;
        virtual void            executeAction(void) const;
    private:
        std::string             _target;
};
#endif //               !_SHRUBBERYCREATIONFORM_HPP__