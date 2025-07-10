/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_main.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Paradis <adil.d.pro@gmail.com>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/09 18:51:29 by Paradis           #+#    #+#             */
/*   Updated: 2025/07/10 21:24:10 by Paradis          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <criterion/criterion.h>
#include <criterion/internal/assert.h>
#include <criterion/logging.h>
#include <criterion/new/assert.h>
#include <criterion/redirect.h>

#include <iostream>
#include <climits>
#include <string>

#include "../../include/ScalarConverter.hpp"
#include "../../include/Utils.hpp"

void redirect_all_stdout(void)
{
    cr_redirect_stdout();
    cr_redirect_stderr();
}

Test(Utils_isPseudoLiteral, TEST_check_if_string_is_a_literal,
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

Test(Utils_isChar, TEST_check_if_string_length_is_different_of_one,
.init = redirect_all_stdout)
{
    {
        std::string A = "a";
        std::string string = "hello";

        cr_assert(Utils::isChar(A) == true);
        cr_assert(Utils::isChar(string) == false);
    }
}

#include <iostream>
Test(Utils_isChar, TEST_should_return_true_for_any_character,
.init = redirect_all_stdout)
{
    {
        for (int i = -127; i < 128; ++i)
        {
            std::string str(1, i);
            cr_assert(Utils::isChar(str) == true);
        }
    }
}

Test(Utils_isInt, TEST_should_return_true_if_is_neg_number,
.init = redirect_all_stdout)
{
    {
        std::string str = std::to_string(-5423543);
        cr_assert(Utils::isInt(str) == true);
    }
}

Test(Utils_isInt, TEST_should_return_true_if_is_pos_number,
.init = redirect_all_stdout)
{
    {
        std::string str = std::to_string(4515243);
        cr_assert(Utils::isInt(str) == true);
    }
}

Test(Utils_isInt, TEST_should_return_false_if_its_not_integer,
.init = redirect_all_stdout)
{
    {
        std::string str = "4321jk413";
        cr_assert(Utils::isInt(str) == false);
    }
}

Test(Utils_isFloat, TEST_should_return_false_if_its_not_float,
.init = redirect_all_stdout)
{
    {
        std::string str = "12.23ffffff";

        cr_assert(Utils::isFloat(str) == false);
    }
}

Test(Utils_isFloat, TEST_should_return_true_if_its_float,
.init = redirect_all_stdout)
{
    {
        std::string str = "12.23f";
        
        cr_assert(Utils::isFloat(str) == true);
    }
}

Test(Utils_isFloat, TEST_should_return_true_if_its_neg_float,
.init = redirect_all_stdout)
{
    {
        std::string str = "-12.23f";
        
        cr_assert(Utils::isFloat(str) == true);
    }
}

Test(Utils_isDouble, TEST_should_return_false_if_its_not_double,
.init = redirect_all_stdout)
{
    {
        std::string str = "12.23gsfd";

        cr_assert(Utils::isDouble(str) == false);
    }
}

Test(Utils_isDouble, TEST_should_return_true_if_its_double,
.init = redirect_all_stdout)
{
    {
        std::string str = "12.23";
        
        cr_assert(Utils::isDouble(str) == true);
    }
}


Test(Utils_isisDouble, TEST_should_return_true_if_its_neg_double,
.init = redirect_all_stdout)
{
    {
        std::string str = "-12.23";
        
        cr_assert(Utils::isDouble(str) == true);
    }
}

Test(Utils_isChar, TEST_should_return_true_if_char_is_printable,
.init = redirect_all_stdout)
{
    {
        for (int i = -127; i < 128; ++i)
        {
            std::string str(1, i);
            if (Utils::isPrintable(str))
            {
                std::cout << str << std::endl;
                cr_assert(Utils::isPrintable(str) == true);
            }
            else
                cr_assert(Utils::isPrintable(str) == false);
        }
    }
    cr_assert_stdout_eq_str
    (
        " \n"
        "!\n"
        "\"\n"
        "#\n"
        "$\n"
        "%\n"
        "&\n"
        "'\n"
        "(\n"
        ")\n"
        "*\n"
        "+\n"
        ",\n"
        "-\n"
        ".\n"
        "/\n"
        "0\n"
        "1\n"
        "2\n"
        "3\n"
        "4\n"
        "5\n"
        "6\n"
        "7\n"
        "8\n"
        "9\n"
        ":\n"
        ";\n"
        "<\n"
        "=\n"
        ">\n"
        "?\n"
        "@\n"
        "A\n"
        "B\n"
        "C\n"
        "D\n"
        "E\n"
        "F\n"
        "G\n"
        "H\n"
        "I\n"
        "J\n"
        "K\n"
        "L\n"
        "M\n"
        "N\n"
        "O\n"
        "P\n"
        "Q\n"
        "R\n"
        "S\n"
        "T\n"
        "U\n"
        "V\n"
        "W\n"
        "X\n"
        "Y\n"
        "Z\n"
        "[\n"
        "\\\n"
        "]\n"
        "^\n"
        "_\n"
        "`\n"
        "a\n"
        "b\n"
        "c\n"
        "d\n"
        "e\n"
        "f\n"
        "g\n"
        "h\n"
        "i\n"
        "j\n"
        "k\n"
        "l\n"
        "m\n"
        "n\n"
        "o\n"
        "p\n"
        "q\n"
        "r\n"
        "s\n"
        "t\n"
        "u\n"
        "v\n"
        "w\n"
        "x\n"
        "y\n"
        "z\n"
        "{\n"
        "|\n"
        "}\n"
        "~\n"
    );
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