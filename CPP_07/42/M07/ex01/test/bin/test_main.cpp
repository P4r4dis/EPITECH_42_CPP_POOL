/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_main.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Paradis <adil.d.pro@gmail.com>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/29 18:43:48 by Paradis           #+#    #+#             */
/*   Updated: 2025/08/29 19:24:18 by Paradis          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <criterion/criterion.h>
#include <criterion/internal/assert.h>
#include <criterion/logging.h>
#include <criterion/new/assert.h>
#include <criterion/redirect.h>

#include "../../include/whatever.hpp"
#include "../../include/iter.hpp"

#include <iostream>

void redirect_all_stdout(void)
{
    cr_redirect_stdout();
    cr_redirect_stderr();
}

template <typename T>
void print(const T &elem)
{
    std::cout << elem << std::endl;
}

Test(iter, TEST_iter_should_display_error_because_the_address_of_array_is_null,
    .init = redirect_all_stdout)
{
    {
        int *array = nullptr;
        
        iter(array, 0, print);
    }
    cr_assert_stdout_eq_str(
        "Error\n"
    );
}

Test(iter, TEST_iter_should_display_error_because_the_size_of_array_is_incorrect,
    .init = redirect_all_stdout)
{
    {
        int     array[5] = {1, 2, 3, 4, 5};
        
        iter(array, 0, print);
    }
    cr_assert_stdout_eq_str(
        "Error\n"
    );
}

Test(iter, TEST_iter_should_display_all_elements_of_INT_array,
    .init = redirect_all_stdout)
{
    {
        int     array[5] = {1, 2, 3, 4, 5};
        
        iter(array, 5, print);
    }
    cr_assert_stdout_eq_str(
        "1\n"
        "2\n"
        "3\n"
        "4\n"
        "5\n"
    );
}

Test(iter, TEST_iter_should_display_all_elements_of_CHAR_array,
    .init = redirect_all_stdout)
{
    {
        char     array[5] = {'a', 'b', 'c', 'd', 'e'};
        
        iter(array, 5, print);
    }
    cr_assert_stdout_eq_str(
        "a\n"
        "b\n"
        "c\n"
        "d\n"
        "e\n"
    );
}

Test(iter, TEST_iter_should_display_all_elements_of_STRING_array,
    .init = redirect_all_stdout)
{
    {
        std::string     array[6] = {"Hello", "World", "How", "Are", "You", "?" };
        
        iter(array, 6, print);
    }
    cr_assert_stdout_eq_str(
        "Hello\n"
        "World\n"
        "How\n"
        "Are\n"
        "You\n"
        "?\n"
    );
}

///////////////////////////////////////////////////////////////////////////////
//                            TEST main                                      //
///////////////////////////////////////////////////////////////////////////////
Test(main, Test_main, .init = redirect_all_stdout)
{
    {
        int *array = nullptr;
        
        iter(array, 0, print);

        int     array2[5] = {1, 2, 3, 4, 5};
        
        iter(array2, 0, print);

        int     array3[5] = {1, 2, 3, 4, 5};
        
        iter(array3, 5, print);

        char     array4[5] = {'a', 'b', 'c', 'd', 'e'};
        
        iter(array4, 5, print);

        std::string     array6[6] = {"Hello", "World", "How", "Are", "You", "?"};
        
        iter(array6, 6, print);
    }
    cr_assert_stdout_eq_str
    (
        "Error\n"
        "Error\n"
        "1\n"
        "2\n"
        "3\n"
        "4\n"
        "5\n"
        "a\n"
        "b\n"
        "c\n"
        "d\n"
        "e\n"
        "Hello\n"
        "World\n"
        "How\n"
        "Are\n"
        "You\n"
        "?\n"
    );
}