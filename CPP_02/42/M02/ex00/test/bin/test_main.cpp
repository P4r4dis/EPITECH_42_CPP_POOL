/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_main.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Paradis <adil.d.pro@gmail.com>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/18 19:58:37 by Paradis           #+#    #+#             */
/*   Updated: 2025/02/18 22:03:45 by Paradis          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <criterion/criterion.h>
#include <criterion/new/assert.h>
#include <criterion/redirect.h>

#include "../../include/Fixed.hpp"

void redirect_all_stdout(void)
{
    cr_redirect_stdout();
    cr_redirect_stderr();
}

Test(Fixed_class, Test_default_CTOR_isDefined, .init = redirect_all_stdout)
{
    Fixed a;

    cr_assert_not_null(&a);
}

Test(Fixed_class, Test_default_CTOR_initializes_fixedPointValue_to_zero,
.init = redirect_all_stdout)
{
    Fixed a;

    cr_assert(a.getRawBits() == 0);
}

Test(Fixed_class, Test_default_CTOR_and_DTOR_prints_msg_to_stdout,
.init = redirect_all_stdout)
{
    {
        Fixed a;
    }
    cr_assert_stdout_eq_str(
        "Default constructor called\n"
        "Destructor called\n"
    );
}

Test(Fixed_class, Test_getRawBits_func_returns_fixedPointValue,
.init = redirect_all_stdout)
{
    {
        Fixed a;

        cr_assert(a.getRawBits() == 0);
    }
}

Test(Fixed_class, Test_getRawBits_func_prints_msg_to_stdout,
.init = redirect_all_stdout)
{
    {
        Fixed a;

        cr_assert(a.getRawBits() == 0);
    }
    cr_assert_stdout_eq_str(
        "Default constructor called\n"
        "getRawBits member function called\n"
        "Destructor called\n"
    );
}

Test(Fixed_class, Test_Copy_CTOR_isDefined, .init = redirect_all_stdout)
{
    Fixed a;
    Fixed b(a);
    cr_assert_not_null(&b);
}

Test(Fixed_class, Test_Copy_CTOR_copy_instance,
.init = redirect_all_stdout)
{
    Fixed a;
    Fixed b(a);
    cr_assert(b.getRawBits() == 0);
    cr_assert(b.getRawBits() == a.getRawBits());
}

Test(Fixed_class, Test_assigment_operator,
.init = redirect_all_stdout)
{
    Fixed a;
    Fixed b;

    b = a;
    cr_assert(b.getRawBits() == a.getRawBits());
}

Test(Fixed_class, Test_assigment_operator_prints_msg_to_stdout,
.init = redirect_all_stdout)
{
    {
        Fixed a;
        Fixed b;

        b = a;
        cr_assert(b.getRawBits() == a.getRawBits());
    }
    cr_assert_stdout_eq_str(
        "Default constructor called\n"
        "Default constructor called\n"
        "Copy assignment operator called\n"
        "getRawBits member function called\n"
        "getRawBits member function called\n"
        "getRawBits member function called\n"
        "Destructor called\n"
        "Destructor called\n"
    );
}

Test(Fixed_class, Test_CopyCTOR_and_CTOR_and_DTOR_prints_msg_to_stdout,
.init = redirect_all_stdout)
{
    {
        Fixed a;
        Fixed b(a);
    }
    cr_assert_stdout_eq_str(
        "Default constructor called\n"
        "Copy constructor called\n"
        "Copy assignment operator called\n"
        "getRawBits member function called\n"
        "Destructor called\n"
        "Destructor called\n"
    );
}

Test(Fixed_class, Test_setRawBits_allows_to_change_fixedPointValue,
.init = redirect_all_stdout)
{
    Fixed a;

    cr_assert(a.getRawBits() == 0);
    a.setRawBits(42);
    cr_assert(a.getRawBits() == 42);
}

Test(Fixed_class, Test_getFractionalBits_func_returns_fractionalBits,
.init = redirect_all_stdout)
{
    Fixed a;

    cr_assert(a.getFractionalBits() == 8);
}


///////////////////////////////////////////////////////////////////////////////
//                            TEST main                                      //
///////////////////////////////////////////////////////////////////////////////
#include <iostream>

Test(main, Test_main, .init = redirect_all_stdout)
{
    {
        Fixed a;
        Fixed b(a);
        Fixed c;

        c = b;

        std::cout << a.getRawBits() << std::endl;
        std::cout << b.getRawBits() << std::endl;
        std::cout << c.getRawBits() << std::endl;
    }
    cr_assert_stdout_eq_str(
        "Default constructor called\n"
        "Copy constructor called\n"
        "Copy assignment operator called\n"
        "getRawBits member function called\n"
        "Default constructor called\n"
        "Copy assignment operator called\n"
        "getRawBits member function called\n"
        "getRawBits member function called\n"
        "0\n"
        "getRawBits member function called\n"
        "0\n"
        "getRawBits member function called\n"
        "0\n"
        "Destructor called\n"
        "Destructor called\n"
        "Destructor called\n"
    );
}