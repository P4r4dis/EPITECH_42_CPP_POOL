/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AForm.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Paradis <adil.d.pro@gmail.com>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/18 17:14:44 by Paradis           #+#    #+#             */
/*   Updated: 2025/06/18 17:14:46 by Paradis          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef                 __AFORM_HPP__
#define                 __AFORM_HPP__

#include <string>
#include <ostream>

class Bureaucrat;
#include "Bureaucrat.hpp"

#define HIGHEST 1
#define LOWEST  150
class                   AForm
{
    public:
        AForm(const std::string &name, const size_t gradeToSign,
            const size_t gradeToExecute);

        AForm(const AForm &cpy);
        AForm            &operator=(const AForm &form);
        virtual ~AForm(void);

        const std::string   getName(void) const;
        bool                getIsSigned(void) const;
        size_t              getGradeToSign(void) const;
        size_t              getGradeToExecute(void) const;

        void                beSigned(const Bureaucrat &bureaucrat);
        void                execute(const Bureaucrat &executor) const;

        virtual void        executeAction(void) const  = 0;
        
        class           GradeTooHighException   :   public std::exception
        {
            public:
                virtual     const char *what(void) const throw();
        };

        class           GradeTooLowException   :   public std::exception
        {
            public:
                virtual     const char *what(void) const throw();
        };

        class           FormNotSigned   :   public std::exception
        {
            public:
                virtual     const char *what(void) const throw();
        };
        
    private:
        const std::string   _name;
        bool                _isSigned;
        const size_t        _gradeToSign;
        const size_t        _gradeToExecute;
};

std::ostream                &operator<<(std::ostream &os, const AForm &form);
#endif //               !_AFORM_HPP__