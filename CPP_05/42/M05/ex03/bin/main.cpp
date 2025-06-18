/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Paradis <adil.d.pro@gmail.com>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/18 17:14:37 by Paradis           #+#    #+#             */
/*   Updated: 2025/06/18 19:39:54 by Paradis          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/Bureaucrat.hpp"
#include "../include/Intern.hpp"
#include <iostream>

int main()
{
    Bureaucrat	bureaucrat = Bureaucrat("bureaucrat", 3);

	Intern	intern = Intern();

	std::cout << "Intern creates:" << std::endl;
	AForm	*f1 = intern.makeForm("shrubbery creation", "A43");
	AForm	*f2 = intern.makeForm("robotomy request", "B28");
	AForm	*f3 = intern.makeForm("presidential pardon", "C57");

	std::cout << "Bureaucrat executes:" << std::endl;
	bureaucrat.signForm(*f1);
	bureaucrat.executeForm(*f1);

	bureaucrat.signForm(*f2);
	bureaucrat.executeForm(*f2);

	bureaucrat.signForm(*f3);
	bureaucrat.executeForm(*f3);

	std::cout << "Intern creates the form that does not exist:" << std::endl;
	intern.makeForm("world destruction", "Bob");

    if (f1)
        delete f1;
    if (f2)
        delete f2;
    if (f3)
        delete f3;
}