/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RobotomyRequestForm.hpp                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Paradis <adil.d.pro@gmail.com>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/18 17:15:23 by Paradis           #+#    #+#             */
/*   Updated: 2025/06/18 17:15:23 by Paradis          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */



#ifndef                 __ROBOTOMYREQUESTFORM_HPP__
#define                 __ROBOTOMYREQUESTFORM_HPP__

#include "AForm.hpp"
#include <string>

#define ROBOT_GRADE_TO_SIGN   72
#define ROBOT_GRADE_TO_EXEC   45

class                   RobotomyRequestForm    :   public AForm
{
    public:
        RobotomyRequestForm(const std::string &target);
        RobotomyRequestForm(const RobotomyRequestForm &obj);
        RobotomyRequestForm   &operator=(const RobotomyRequestForm& rhs);
        virtual ~RobotomyRequestForm(void);

        std::string             getTarget(void) const;
        virtual void            executeAction(void) const;
    private:
        std::string             _target;
};
#endif //               !_ROBOTOMYREQUESTFORM_HPP__