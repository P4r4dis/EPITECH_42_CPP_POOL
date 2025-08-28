/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_main.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Paradis <adil.d.pro@gmail.com>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/28 17:16:13 by Paradis           #+#    #+#             */
/*   Updated: 2025/08/28 19:19:17 by Paradis          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <criterion/criterion.h>
#include <criterion/internal/assert.h>
#include <criterion/logging.h>
#include <criterion/new/assert.h>
#include <criterion/redirect.h>

#include "../../include/whatever.hpp"

#include <iostream>

void redirect_all_stdout(void)
{
    cr_redirect_stdout();
    cr_redirect_stderr();
}

Test(swap, TEST_swap_2_values_of_2_arguments, .init = redirect_all_stdout)
{
    {
        int     a = 2;
        int     b = 3;

        cr_assert(a == 2);
        cr_assert(b == 3);

        ::swap(a, b);

        cr_assert(a == 3);
        cr_assert(b == 2);
    }
}

Test(swap, TEST_swap_2_values_of_2_arguments_with_any_type,
    .init = redirect_all_stdout)
{
    {
        int     a = 2;
        int     b = 3;

        cr_assert(a == 2);
        cr_assert(b == 3);

        ::swap(a, b);

        cr_assert(a == 3);
        cr_assert(b == 2);

        char    c = 'c';
        char    d = 'd';

        cr_assert(c == 'c');
        cr_assert(d == 'd');

        ::swap(c, d);

        cr_assert(c == 'd');
        cr_assert(d == 'c');

        std::string    str1 = "Hello";
        std::string    str2 = "World";

        cr_assert(str1 == "Hello");
        cr_assert(str2 == "World");

        ::swap(str1, str2);

        cr_assert(str1 == "World");
        cr_assert(str2 == "Hello");
    }
}

///////////////////////////////////////////////////////////////////////////////
//                            TEST main                                      //
///////////////////////////////////////////////////////////////////////////////
Test(main, Test_main, .init = redirect_all_stdout)
{
    {
        int a = 2;
        int b = 3;

        ::swap( a, b );

        std::cout << "a = " << a << ", b = " << b << std::endl;
//         std::cout << "min( a, b ) = " << ::min( a, b ) << std::endl;
//         std::cout << "max( a, b ) = " << ::max( a, b ) << std::endl;

        std::string c = "chaine1";
        std::string d = "chaine2";

        ::swap(c, d);

        std::cout << "c = " << c << ", d = " << d << std::endl;
//         std::cout << "min( c, d ) = " << ::min( c, d ) << std::endl;
//         std::cout << "max( c, d ) = " << ::max( c, d ) << std::endl;
    }
    cr_assert_stdout_eq_str
    (
        "a = 3, b = 2\n"
        // "min(a, b) = 2\n"
        // "max(a, b) = 3\n"
        "c = chaine2, d = chaine1\n"
        // "min(c, d) = chaine1\n"
        // "max(c, d) = chaine2\n"
    );
}