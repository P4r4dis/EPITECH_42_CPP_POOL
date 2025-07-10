/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_main.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Paradis <adil.d.pro@gmail.com>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/09 18:51:29 by Paradis           #+#    #+#             */
/*   Updated: 2025/07/09 20:54:43 by Paradis          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <criterion/criterion.h>
#include <criterion/internal/assert.h>
#include <criterion/logging.h>
#include <criterion/new/assert.h>
#include <criterion/redirect.h>

#include "../../include/ScalarConverter.hpp"
#include "../../include/Utils.hpp"

void redirect_all_stdout(void)
{
    cr_redirect_stdout();
    cr_redirect_stderr();
}

Test(ScalarConverter_isPseudoLiteral, TEST_check_if_string_is_a_literal,
.init = redirect_all_stdout)
{
    {
        std::string pos_inff = "+inff";
        std::string neg_inff = "-inff";
        std::string pos_inf = "+inf";
        std::string neg_inf = "-inf";
        std::string nan = "nan";
        std::string nanf = "nanf";

        cr_assert(Utils::isPseudoLiteral(pos_inff) == true);
        cr_assert(Utils::isPseudoLiteral(neg_inff) == true);
        cr_assert(Utils::isPseudoLiteral(pos_inf) == true);
        cr_assert(Utils::isPseudoLiteral(neg_inf) == true);
        cr_assert(Utils::isPseudoLiteral(nan) == true);
        cr_assert(Utils::isPseudoLiteral(nanf) == true);
    }
}

///////////////////////////////////////////////////////////////////////////////
//                            TEST main                                      //
///////////////////////////////////////////////////////////////////////////////
Test(main, Test_main, .init = redirect_all_stdout)
{
    {
    }
    // cr_assert_stdout_eq_str
    // (

    // );
}