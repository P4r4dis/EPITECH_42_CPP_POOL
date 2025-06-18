/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PresidentialPardonForm.hpp                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Paradis <adil.d.pro@gmail.com>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/17 20:52:59 by Paradis           #+#    #+#             */
/*   Updated: 2025/06/17 21:07:19 by Paradis          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef                 __PRESIDENTIALPARDONFORM_HPP__
#define                 __PRESIDENTIALPARDONFORM_HPP__

#include "AForm.hpp"
#include <string>

#define PRES_GRADE_TO_SIGN   25
#define PRES_GRADE_TO_EXEC   5

class                   PresidentialPardonForm    :   public AForm
{
    public:
        PresidentialPardonForm(const std::string &target);
        PresidentialPardonForm(const PresidentialPardonForm &obj);
        PresidentialPardonForm   &operator=(const PresidentialPardonForm& rhs);
        virtual ~PresidentialPardonForm(void);

        std::string             getTarget(void) const;
        virtual void            executeAction(void) const;
    private:
        std::string             _target;
};
#endif //               !_PRESIDENTIALPARDONFORM_HPP__