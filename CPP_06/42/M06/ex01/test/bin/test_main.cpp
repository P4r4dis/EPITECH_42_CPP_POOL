/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_main.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Paradis <adil.d.pro@gmail.com>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/23 20:51:03 by Paradis           #+#    #+#             */
/*   Updated: 2025/07/29 15:59:44 by Paradis          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <criterion/criterion.h>
#include <criterion/internal/assert.h>
#include <criterion/logging.h>
#include <criterion/new/assert.h>
#include <criterion/redirect.h>

#include "../../include/Serializer.hpp"

#include <iostream>
void redirect_all_stdout(void)
{
    cr_redirect_stdout();
    cr_redirect_stderr();
}

///////////////////////////////////////////////////////////////////////////////
//                            TEST main                                      //
///////////////////////////////////////////////////////////////////////////////
Test(main, Test_main)//, .init = redirect_all_stdout)
{
    {
        Serializer::Data *original = new Serializer::Data;
        original->_data = 42;

        uintptr_t raw = Serializer::serialize(original);

        Serializer::Data *result = Serializer::deserialize(raw);

        // Verify if pointers are the same
        cr_assert_eq(original, result);

        // Verify variables are the same
        cr_assert_eq(result->_data, original->_data);
    std::cout   << "addr of result pointer and original pointer "
                << "should be the same:" << std::endl
                << "addr result pointer: " << result << std::endl
                << "addr original pointer: " << original << std::endl;
    std::cout   << "value _data of result pointer and original pointer "
                << "should be the same:" << std::endl
                << "value _data of result pointer: " << result->_data 
                << std::endl
                << "value _data of original pointer: " << original->_data
                << std::endl;

        delete original;
    }
}