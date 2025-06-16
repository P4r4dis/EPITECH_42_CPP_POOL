/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Paradis <adil.d.pro@gmail.com>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/13 19:28:27 by Paradis           #+#    #+#             */
/*   Updated: 2025/06/16 15:00:39 by Paradis          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef                 __FORM_HPP__
#define                 __FORM_HPP__

#include <string>
#include "Bureaucrat.hpp"

#define HIGHEST 1
#define LOWEST  150
class                   Form
{
    public:
        Form(const std::string &name, const size_t gradeToSign,
            const size_t gradeToExecute);

        Form(const Form &cpy);
        Form            &operator=(const Form &rhs);
        virtual ~Form(void);

        const std::string   getName(void) const;
        bool                getIsSigned(void) const;
        size_t              getGradeToSign(void) const;
        size_t              getGradeToExecute(void) const;

        void                beSigned(const Bureaucrat &bureaucrat);
        
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
    private:
        const std::string   _name;
        bool                _isSigned;
        const size_t        _gradeToSign;
        const size_t        _gradeToExecute;


};

std::ostream                &operator<<(std::ostream &os, const Form form);
#endif //               !_FORM_HPP__