/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Paradis <adil.d.pro@gmail.com>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/13 19:25:36 by Paradis           #+#    #+#             */
/*   Updated: 2025/06/16 19:51:46 by Paradis          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/Bureaucrat.hpp"

int main()
{
        Bureaucrat bureaucrat("Bureaucrat",9);
        Form form("A43", 10, 50);

        bureaucrat.signForm(form);

 
        Bureaucrat bureaucrat2("Bureaucrat",15);
        Form form2("A43", 10, 50);

        bureaucrat2.signForm(form2);
}