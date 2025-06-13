/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Paradis <adil.d.pro@gmail.com>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/11 20:46:59 by Paradis           #+#    #+#             */
/*   Updated: 2025/06/13 18:40:58 by Paradis          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/Bureaucrat.hpp"

#include <iostream>

int main()
{
    Bureaucrat bureau("name", 42);

    bureau.getName();
    bureau.getGrade();
    bureau.increment();
    bureau.getGrade();
    bureau.decrement();
    bureau.getGrade();


    try
    {
        Bureaucrat bureau("name", 1);

        bureau.getName();
        bureau.getGrade();
        bureau.increment();
    }
    catch (std::exception &e)
    {
        std::cerr << e.what() << std::endl;
    }

    try
    {
        Bureaucrat bureau("name", 150);

        bureau.getName();
        bureau.getGrade();
        bureau.decrement();
    }
    catch (std::exception &e)
    {
        std::cerr << e.what() << std::endl;
    }
}