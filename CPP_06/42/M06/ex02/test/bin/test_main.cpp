/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_main.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Paradis <adil.d.pro@gmail.com>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/23 20:51:03 by Paradis           #+#    #+#             */
/*   Updated: 2025/07/29 17:19:00 by Paradis          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <criterion/criterion.h>
#include <criterion/internal/assert.h>
#include <criterion/logging.h>
#include <criterion/new/assert.h>
#include <criterion/redirect.h>

#include "../../include/Utils.hpp"

#include <iostream>
#include <typeinfo>
void redirect_all_stdout(void)
{
    cr_redirect_stdout();
    cr_redirect_stderr();
}

Test(Utils_generate, Test_should_generate_A_B_or_C_classes_randomly, .init = redirect_all_stdout)
{
    {
        Base *base = generate();
        std::string str = typeid(*base).name();
        if (str == "1A")
        {
            std::cout << "Class A was generated." << std::endl;
            cr_assert_stdout_eq_str("Class A was generated.\n");
        }
        else if (str == "1B")
        {
            std::cout << "Class B was generated." << std::endl;
            cr_assert_stdout_eq_str("Class B was generated.\n");
        }
        else if (str == "1c")
        {
            std::cout << "Class C was generated." << std::endl;
            cr_assert_stdout_eq_str("Class C was generated.\n");
        }
        else
        {
            std::cout << "Nothing was generated." << std::endl;
            cr_assert_stdout_eq_str("Nothing was generated.\n");
        }

    }
}
///////////////////////////////////////////////////////////////////////////////
//                            TEST main                                      //
///////////////////////////////////////////////////////////////////////////////
Test(main, Test_main)//, .init = redirect_all_stdout)
{
    {

    }
}