/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_main.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Paradis <adil.d.pro@gmail.com>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/29 19:33:07 by Paradis           #+#    #+#             */
/*   Updated: 2025/09/08 20:36:18 by Paradis          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <criterion/criterion.h>
#include <criterion/internal/assert.h>
#include <criterion/logging.h>
#include <criterion/new/assert.h>
#include <criterion/redirect.h>

#include "../../include/Array.hpp"

#include <iostream>

void redirect_all_stdout(void)
{
    cr_redirect_stdout();
    cr_redirect_stderr();
}

Test(Array, TEST_constructor_with_no_parameter_is_defined,
    .init = redirect_all_stdout)
{
    Array<int>     array;

    cr_assert_not_null(&array);
}

Test(Array, TEST__constructor_with_no_parameter_should_create_an_empty_array,
    .init = redirect_all_stdout)
{
    Array<void *>     array;

    cr_assert(array.size() == 0);
}

Test(Array, TEST_constructor_with_parameter_is_defined,
    .init = redirect_all_stdout)
{
    Array<int>     array(10);

    cr_assert_not_null(&array);
}

Test(Array, TEST__constructor_with_parameter_create_array_of_N_elements,
)//.init = redirect_all_stdout)
{
    Array<int>     array(10);

    cr_assert(array.size() == 10);
    
    int *a = new int();
    std::cout << *a << std::endl;

    for (unsigned int i = 0; i < array.size(); ++i)
        cr_assert(array[i] == 0);
}
///////////////////////////////////////////////////////////////////////////////
//                            TEST main                                      //
///////////////////////////////////////////////////////////////////////////////
Test(main, Test_main, .init = redirect_all_stdout)
{
    {

    }
//     cr_assert_stdout_eq_str
//     (
//     );
}