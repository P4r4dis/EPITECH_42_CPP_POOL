/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Paradis <adil.d.pro@gmail.com>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/16 20:00:44 by Paradis           #+#    #+#             */
/*   Updated: 2025/06/18 16:42:22 by Paradis          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/Bureaucrat.hpp"
#include "../include/ShrubberyCreationForm.hpp"
#include "../include/RobotomyRequestForm.hpp"
#include "../include/PresidentialPardonForm.hpp"

int main()
{
	Bureaucrat	            bureaucrat      = Bureaucrat("bureaucrat", 3);
	ShrubberyCreationForm	f1 = ShrubberyCreationForm("A43");
	RobotomyRequestForm		f2 = RobotomyRequestForm("B28");
	PresidentialPardonForm	f3 = PresidentialPardonForm("C57");
	
	bureaucrat.executeForm(f1);
	bureaucrat.signForm(f1);
	bureaucrat.executeForm(f1);

	PresidentialPardonForm	f4 = f3;
	bureaucrat.signForm(f4);
	bureaucrat.executeForm(f4);

	bureaucrat.executeForm(f2);
	bureaucrat.signForm(f2);
	bureaucrat.executeForm(f2);
}