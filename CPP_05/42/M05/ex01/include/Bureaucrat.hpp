/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Paradis <adil.d.pro@gmail.com>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/13 19:25:50 by Paradis           #+#    #+#             */
/*   Updated: 2025/06/16 18:41:51 by Paradis          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef                 __BUREAUCRAT_HPP__
#define                 __BUREAUCRAT_HPP__

#include <cstddef>
#include <exception>
#include <string>

class Form;
#include "Form.hpp"

#define HIGHEST 1
#define LOWEST  150
class                   Bureaucrat
{
    public:
        Bureaucrat(const std::string &name, size_t grade);
        virtual ~Bureaucrat(void);

        const std::string   getName(void) const;
        size_t              getGrade(void) const;
        void                increment(void);
        void                decrement(void);
        void                signForm(Form &form);

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
        size_t              _grade;
};

std::ostream                &operator<<(std::ostream &os,
                                        const Bureaucrat &bureau);
#endif //               !_BUREAUCRAT_HPP__